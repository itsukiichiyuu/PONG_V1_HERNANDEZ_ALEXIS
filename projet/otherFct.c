#include "otherFct.h"

/*void handleEvents(gameState *state,rectangle *rec){


    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_UP:

                                    if(rec->taille.y>=20)
                                    {
                                        rec->taille.y=rec->taille.y-20;
                                    }
                                    break;
                                case SDLK_DOWN:

                                    if((rec->taille.y+rec->taille.h)<=(SCREEN_HEIGHT-20))
                                    {
                                        rec->taille.y=rec->taille.y+20;
                                    }
                                    break;
                                case SDLK_ESCAPE: state->g_bRunning=0; break;
                            }
                            break;

        case SDL_KEYUP:;break;

        default:break;

        }
    }

}*/
void handleEvents(gameState *state,rectangle *rec,int *up, int *down){


    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_UP: *up=1; break;
                                case SDLK_DOWN: *down=1; break;
                                case SDLK_ESCAPE: state->g_bRunning=0; break;
                            }
                            break;

        case SDL_KEYUP:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_UP: *up=0; break;
                                case SDLK_DOWN: *down=0; break;
                            }
                            break;

        default:break;

        }
    }

}

void renderTexture(game *myGame,rectangle *rec,rectangle *recIA, rectangle *balle ) {


    SDL_SetRenderDrawColor(myGame->g_pRenderer,rec->R,rec->G,rec->B,rec->A);
    SDL_SetRenderTarget(myGame->g_pRenderer, myGame->g_ptexture); //on modifie la texture

    SDL_RenderFillRect(myGame->g_pRenderer, &rec->taille);

    //____________________________________________________________________________________________
    //____________________________________________________________________________________________

    SDL_SetRenderDrawColor(myGame->g_pRenderer,recIA->R,recIA->G,recIA->B,recIA->A);
    SDL_SetRenderTarget(myGame->g_pRenderer, myGame->g_ptexture); //on modifie la texture

    SDL_RenderFillRect(myGame->g_pRenderer, &recIA->taille);

    //____________________________________________________________________________________________
    //____________________________________________________________________________________________

    SDL_SetRenderDrawColor(myGame->g_pRenderer,balle->R,balle->G,balle->B,balle->A);
    SDL_SetRenderTarget(myGame->g_pRenderer, myGame->g_ptexture); //on modifie la texture

    SDL_RenderFillRect(myGame->g_pRenderer, &balle->taille);

    SDL_RenderPresent(myGame->g_pRenderer);

    SDL_SetRenderDrawColor(myGame->g_pRenderer,0,0,25,255);
    SDL_DestroyTexture(myGame->g_ptexture);
    SDL_RenderClear(myGame->g_pRenderer);

}

int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame){


    myGame->g_pWindow=NULL;
    myGame->g_pRenderer=NULL;
    myGame->g_psurface=NULL;
    myGame->g_ptexture=NULL;


    //initialize SDL

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

            }
    }else{

        return 0;
    }

    return 1;
}


void moveBalle(rectangle *recIA,rectangle *rec,rectangle *balle,int *allerX, int *allerY, int *retourX, int *retourY, int *scoreD, int *scoreG, int *manche,int* up, int *down, int *vitesse)
{
    //__________________________________________________
    //CHANGEMENT DE DIRECTION Y
    //__________________________________________________


    if (balle->taille.y>=(SCREEN_HEIGHT-balle->taille.h))
    {
        *allerY=0;
        *retourY=1;
    }

    if (balle->taille.y<=ZERO)
    {
        *allerY=1;
        *retourY=0;
    }

    //__________________________________________________
    //COLLISION JOUEUR 1
    //__________________________________________________

    if (balle->taille.x<=(rec->taille.w+rec->taille.x))
    {
        if((balle->taille.y<=(rec->taille.h+rec->taille.y))&&((balle->taille.y+balle->taille.h)>=rec->taille.y))
        {

            if (*retourX==0)
            {
                *retourX=1;
                *allerX=0;
            }
            else
            {
                *retourX=0;
                *allerX=1;
            }
            *vitesse=*vitesse+1;
        }

    }

    //__________________________________________________
    //COLLISION JOUEUR IA
    //__________________________________________________

    if ((balle->taille.x+balle->taille.w)>=(recIA->taille.x))
    {
        if((balle->taille.y<=(recIA->taille.h+recIA->taille.y))&&((balle->taille.y+balle->taille.h)>=recIA->taille.y))
        {
            if (*retourX==0)
            {
                *retourX=1;
                *allerX=0;
            }
            else
            {
                *retourX=0;
                *allerX=1;
            }
        }

    }
    //__________________________________________________
    //DEPLACEMENT BALLE
    //__________________________________________________

    if (*allerX==0)
    {
        balle->taille.x=balle->taille.x-*vitesse;
    }
    else
    {
        balle->taille.x=balle->taille.x+*vitesse;
    }

    if (*allerY==0)
    {
        balle->taille.y=balle->taille.y-*vitesse;
    }
    else
    {
        balle->taille.y=balle->taille.y+*vitesse;
    }

    //__________________________________________________
    //DEPLACEMENT JOUEUR
    //__________________________________________________

    if (*up)
    {
        if(rec->taille.y>=10)
        {
            rec->taille.y=rec->taille.y-10;
        }

    }
    if (*down)
    {
        if((rec->taille.y+rec->taille.h)<=(SCREEN_HEIGHT-10))
        rec->taille.y=rec->taille.y+10;
    }

    //__________________________________________________
    //SCORE
    //__________________________________________________

    if ((balle->taille.x>SCREEN_WIDTH)||(balle->taille.x<ZERO))
    {
        if (balle->taille.x>SCREEN_WIDTH)
        {
            *scoreG++;
        }
        if (balle->taille.x<ZERO)
        {
            *scoreD=*scoreD+1;
        printf("%i-%i",*scoreG,*scoreD);
        }
        *manche=ZERO;
    }

}

void moveIA(rectangle *recIA,rectangle *balle)
{
    recIA->taille.y=(balle->taille.y-50);

    if ((recIA->taille.y)>(SCREEN_HEIGHT-100))
    {
        recIA->taille.y=(SCREEN_HEIGHT-100);
    }

    if ((recIA->taille.y)<(0))
    {
        recIA->taille.y=(0);
    }

}
