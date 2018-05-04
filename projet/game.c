#include "game.h"

//modifie le fond
void render(game *myGame){


    //set to orange
    SDL_SetRenderDrawColor(myGame->g_pRenderer,COLORMAX,123,2,COLORMAX);

    //clear the window to orange
    SDL_RenderClear(myGame->g_pRenderer);

    //Show in the window
    SDL_RenderPresent(myGame->g_pRenderer);

    SDL_Delay(4000);

    destroy(myGame);

}

//
void drawInSurface(game *myGame){


            /* Creating the surface. */
            myGame->g_psurface = SDL_CreateRGBSurface(ZERO, 100, 400, 32, ZERO, ZERO, ZERO, ZERO);

            /* Filling the surface with red color. */
            SDL_FillRect(myGame->g_psurface, NULL, SDL_MapRGB(myGame->g_psurface->format,
                                                              255, ZERO, ZERO));

            SDL_Texture *texture_tampon = SDL_CreateTextureFromSurface(myGame->g_pRenderer,
                                                                       myGame->g_psurface);
            SDL_SetRenderTarget(myGame->g_pRenderer, texture_tampon);

            SDL_Rect position;//position de debut du dessin dans screen
            position.x = ZERO;
            position.y = ZERO;
            SDL_QueryTexture(texture_tampon, NULL, NULL, &position.w, &position.h);
            SDL_RenderCopy(myGame->g_pRenderer,texture_tampon,NULL,&position);


            SDL_RenderPresent(myGame->g_pRenderer);

            SDL_Delay(4000);

            destroy(myGame);


}

//dessiner dans le renderer, dans un objet

void drawInRenderer(game *myGame){


       //D�finition du rectangle a dessiner
        SDL_Rect rectangle;


        SDL_SetRenderDrawColor(myGame->g_pRenderer, ZERO, ZERO, ZERO, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(myGame->g_pRenderer);

        SDL_SetRenderDrawColor(myGame->g_pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        //Triangle
        SDL_RenderDrawLine(myGame->g_pRenderer, 320, 200, 300, 240);
        SDL_RenderDrawLine(myGame->g_pRenderer, 300, 240, 340, 240);
        SDL_RenderDrawLine(myGame->g_pRenderer, 340, 240, 320, 200);

        rectangle.x=100;//debut x
        rectangle.y=100;//debut y
        rectangle.w=10; //Largeur
        rectangle.h=100; //Hauteur

        //rectangle vide
        SDL_RenderDrawRect(myGame->g_pRenderer,&rectangle);

        rectangle.x=ZERO;//debut x
        rectangle.y=ZERO;//debut y
        rectangle.w=100; //Largeur
        rectangle.h=100; //Hauteur


        //rectangle plein
        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle);

        //Affichage dans fen�tre
        SDL_RenderPresent(myGame->g_pRenderer);

        SDL_Delay(4000);

        destroy(myGame);


}


void destroy(game *myGame){

      //Destroy render
     if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);

      //Destroy texture
     if(myGame->g_ptexture!=NULL)
        SDL_DestroyTexture(myGame->g_ptexture);

    //Destroy surface
     if(myGame->g_psurface!=NULL)
         SDL_FreeSurface(myGame->g_psurface);

    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}
