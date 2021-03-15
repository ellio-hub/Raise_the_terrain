#include "lib.h"

int main(void)
{
SDL_Instance instance;
if(init_instance(&instance) != 0)
return (1);
while("SDL is Shiit")
{
SDL_SetRenderDrawColor(instance.rendrer,0xFF,0xFF,0xFF,0xFF);
SDL_RenderClear(instance.rendrer);
if (events() == 1)
break;
draw(instance);
SDL_RenderPresent(instance.rendrer);
}
return(0);
}
int init_instance(SDL_Instance *instance)
{
if (SDL_INIT_VIDEO == 0)
{
fprintf(stderr,"Unable to intialize SDL: %s\n",SDL_GetError());
return(1);
}
instance->window = SDL_CreateWindow("First",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
1280,720,0);
if (instance->window == NULL)
{
fprintf(stderr,"Unable to Create a window %s\n",SDL_GetError());
SDL_DestroyWindow(instance->window);
SDL_Quit();
return(1);
}
instance->rendrer = SDL_CreateRenderer(instance->window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (instance->rendrer == NULL)
{
fprintf(stderr,"Unable to Render%s\n",SDL_GetError());
SDL_DestroyWindow(instance->window);
SDL_Quit();
return(1);
}
return(0);
}
void draw (SDL_Instance instance)
{
SDL_Rect fillRect = {1280 / 6, 720 / 6, 1280 * 2 / 3, 720 * 2 / 3};
SDL_SetRenderDrawColor( instance.rendrer,0,0,0,0);
SDL_RenderFillRect( instance.rendrer, &fillRect );
}
