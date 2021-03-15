#ifndef _DEMO_H_
#define _DEMO_H_
#include <SDL2/SDL.h>
#include <stdio.h>
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *rendrer;

} SDL_Instance;
int init_instance(SDL_Instance *);
void draw (SDL_Instance instance);
int events (void);
#endif
