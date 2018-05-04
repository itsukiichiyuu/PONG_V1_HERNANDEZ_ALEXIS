#include "otherFct.h"
#include "delay.h"
#include "rectangle.h"


//_________________________________ TODO_____________________________

//régler le problem de balle qui colle derrière la plateforme
//installer le TTF
//déplacement comme la balle pour l'IA, une certaine vitesse définie
//acceleration de la balle à chaque échange
//affichage des points
//ajout de la barre centrale
//écran de fin de jeux à 10pts
//splash screen

//cerle en dessiner, double boucle et calcul de la coordonnée polaire du cercle en utilisant le cos et le sin (équation géométrique d'un cercle)
//rebond balle: si centre balle.y<= extrémité gauche plateforme.y rebond avec multiplicateur
//SI centre balle.y> extrémité gauche plateforme.y ET balle.y+Width/2> extrémité gauche plateforme.y rebond avec multiplicateur plus élevé (fortement)

//_________________________________ TODO_____________________________

//Option de build dans les linker setting mettre les libSDL2main.a libSDL2.dll.a
//Dans search directory
//Option de build compiler mettre les include
//Option de build linker mettre les lib
//mettre dans build linker -lmingw32

int main(int argc, char *argv[])
{
    srand(time(NULL));
    game myGame;
    gameState state;

    unsigned int frameLimit = SDL_GetTicks() + FPS;

    rectangle rec;
    rectangle recIA;
    rectangle balle;

    initRec(&rec,10,SCREEN_HEIGHT/2,10,100,255,ZERO,ZERO,255);
    initRec(&recIA,SCREEN_WIDTH-20,SCREEN_HEIGHT/2,10,100,ZERO,ZERO,255,255);
    initRec(&balle,SCREEN_WIDTH/2,SCREEN_HEIGHT/2,10,10,ZERO,255,ZERO,255);

    int allerX=ZERO;
    int allerY=ZERO;
    int retourX=1;
    int retourY=1;
    int res=ZERO;
    int depart=1;
    int scoreG=ZERO;
    int scoreD=ZERO;
    int manche=1;
    int up=0;
    int down=0;
    int vitesse=3;


    /*TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("angelina.ttf", 65);

    TTF_CloseFont(police);
    TTF_Quit();*/



    state.g_bRunning=1;

    //CREER UN ECRAN
    init("Pong", 250,150,SCREEN_WIDTH, SCREEN_HEIGHT,ZERO,&myGame);


    while(state.g_bRunning)
    {
        while((manche==1)&&(state.g_bRunning))
        {
            //GESTION DES TOUCHES
            handleEvents(&state,&rec,&up,&down);

            //GESTION DU DEPLACEMENT DE LA BALLE +COLLISIONS
            moveBalle(&recIA,&rec,&balle,&allerX,&allerY,&retourX,&retourY,&scoreD,&scoreG,&manche,&up,&down,&vitesse);
            moveIA(&recIA,&balle);

            //AFFICHAGE
            renderTexture(&myGame,&rec,&recIA,&balle);

            // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + FPS;

            if (depart==1)
            {

                //action du premier tour
                //random du joueur commençant
                res=rand()%2+1;

                if(res==1)
                {
                    allerX=ZERO;
                    allerY=ZERO;
                    retourX=1;
                    retourY=1;
                }
                else
                {
                    allerX=1;
                    allerY=1;
                    retourX=ZERO;
                    retourY=ZERO;
                }

                depart=ZERO;

                SDL_Delay(3000);
            }
        }

        if ((scoreD==10)||(scoreG==10))
        {
            //_______________________________
            //FONCTION D'AFFICHAGE DES SCORES
            //_______________________________
            SDL_Delay(3000);
            //_______________________________
            //ENTREE DU JOUEUR POUR QUITTER
            //_______________________________
            state.g_bRunning=ZERO;
        }
        else
        {
            manche=1;
            vitesse=5;
            initRec(&rec,10,SCREEN_HEIGHT/2,10,100,255,ZERO,ZERO,255);
            initRec(&recIA,SCREEN_WIDTH-20,SCREEN_HEIGHT/2,10,100,ZERO,ZERO,255,255);
            initRec(&balle,SCREEN_WIDTH/2,SCREEN_HEIGHT/2,10,10,ZERO,255,ZERO,255);
            renderTexture(&myGame,&rec,&recIA,&balle);
            SDL_Delay(3000);
        }

    }

    system ("cls");

    destroy(&myGame);

    SDL_Quit();

    return ZERO;
}
