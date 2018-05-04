#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>





int	load_splash(SDL_Renderer *renderer, char *path)
{
  SDL_Texture	*pong;
  int w, h;
  SDL_Event event;
  bool quit;

  quit = false;
  w = 640;
  h = 480;
  pong = IMG_LoadTexture(renderer, path);
  SDL_QueryTexture(pong, NULL, NULL, &w, &h);
  if (pong == NULL)
    {
      printf("Can't Load %s", path);
      return (0);
    }
  while (!quit)
    {
      SDL_PollEvent(&event);
      switch (event.type)
        {
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
            {
            case SDLK_UP:
              {
                quit = true;
                return (1);
              }
	      break;
	    }
	}
      SDL_RenderCopy(renderer, pong, 0, 0);
      SDL_RenderPresent(renderer);
    }
  SDL_DestroyTexture(pong);
  //  SDL_RenderClear(renderer);
}
