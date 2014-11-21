
#include "main.h"

int main ( int argc, char** argv )
{
    timeCheck = SDL_GetTicks();
    quit = false;
    currentFrame = 0;
    
    window = SDL_CreateWindow("Diablo Logo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN /*SDL_WINDOW_SHOWN*/);
    if(window == NULL) {
        std::cout << "Couldn't initialize the window!" << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    texture = IMG_LoadTexture(renderer, "logo.png");
    if(texture == NULL) {
        std::cout << "Couldn't load the image: " << SDL_GetError() << std::endl;
    }
    
    logo.x = (SCREEN_WIDTH / 2) - (LOGO_WIDTH / 2);
    logo.y = (SCREEN_HEIGHT / 2) - (LOGO_HEIGHT / 2);
    logo.w = LOGO_WIDTH;
    logo.h = LOGO_HEIGHT;
    
    for (int i = 0; i < LOGO_FRAMES; i++) {
        logoClip[i].x = 0;
        logoClip[i].y = LOGO_HEIGHT * i;
        logoClip[i].w = LOGO_WIDTH;
        logoClip[i].h = LOGO_HEIGHT;
    }

    while(!quit && event->type != SDL_QUIT) {
        SDL_PollEvent(event);
        
        if(timeCheck + ANIMATION_SPEED < SDL_GetTicks())
        {

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, &logoClip[currentFrame], &logo);
            SDL_RenderPresent(renderer);

            currentFrame++;
            
            if (currentFrame >= LOGO_FRAMES) {
                currentFrame = 0;
            }
            
            timeCheck = SDL_GetTicks();
        }
        
        if(event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
            quit = true;
        
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete event;
    
    return 0;
}