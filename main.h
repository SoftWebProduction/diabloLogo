//
//  main.h
//  diabloLogo
//
//  Created by Moerbius on 21/11/2014.
//  Copyright (c) 2014 softWEB Production. All rights reserved.
//

#ifndef diabloLogo_main_h
#define diabloLogo_main_h

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2.h>
#include <SDL2_image.h>
#include <SDL2_mixer.h>
#endif

#include <iostream>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600
#define LOGO_WIDTH      550
#define LOGO_HEIGHT     216
#define ANIMATION_SPEED 60
#define LOGO_FRAMES     15

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event* event = new SDL_Event();
SDL_Texture* texture = NULL;


bool quit;
SDL_Rect logo;
SDL_Rect logoClip[ LOGO_FRAMES ];

unsigned int timeCheck;
unsigned int currentFrame;

#endif
