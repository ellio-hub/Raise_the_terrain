#include "lib.h"
/**
 * @brief
 */
int events (void)
{
SDL_Event e;
SDL_KeyboardEvent key;
while (SDL_PollEvent(&e))
{
switch (e.type)
{
case SDL_QUIT:
return (1);
case SDL_KEYDOWN:
key = e.key;
if (key.keysym.sym == SDLK_ESCAPE)
return (1);
}
return (0);
}
}
