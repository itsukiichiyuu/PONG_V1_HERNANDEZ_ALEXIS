#ifndef OTHERFCT_H_INCLUDED
#define OTHERFCT_H_INCLUDED

#include "rectangle.h"
#include "game.h"

typedef struct gameState{

    int g_bRunning;


}gameState;

void handleEvents(gameState *state,rectangle *rec,int *up, int *down);
extern void renderTexture(game *myGame,rectangle *rec,rectangle *recIA,rectangle *balle);
int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame);
void moveBalle(rectangle *recIA,rectangle *rec,rectangle *balle,int *allerX, int *allerY, int *retourX, int *retourY,int *scoreD, int *scoreG, int* manche,int *up, int *down,int *vitesse);
void moveIA(rectangle *recIA,rectangle *balle);

#endif
