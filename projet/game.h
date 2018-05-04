#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constantes.h"

typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;


}game;


extern void destroy(game *myGame);
extern void render(game *myGame);
extern void drawInRenderer(game *myGame);
extern void drawInSurface(game *myGame);


#endif
