//programme principal
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_rotozoom.h>
#include "option.h"
#include "fonction.h"
#include "intro.h"
#include "debut.h"
#include "stage1.h"

int main ()
{
    SDL_Surface *ecran=NULL,*menu=NULL,*texteplay=NULL,*texteoption=NULL,*textecredits=NULL,*textemulti=NULL,*textequit=NULL,*star=NULL,*commentaireplay=NULL,*commentaireoption=NULL,*commentairemulti=NULL,*commentairequit=NULL,*shab1=NULL,*shab2=NULL,*shab3=NULL,*logo=NULL,*embleme=NULL;
    SDL_Rect posvolb,posshab1,posshab2,posshab3,positionFond, posquit, posmulti, posoption,poscredits, posplay,posstar, poscquit, poscmulti, poscoption, poscplay,poslogo;
    Mix_Music *musique,*musiquetuto;
    Mix_Chunk *effet, *effet2,*sonspell,*dying,*hit;
    TTF_Font *police = NULL,*police1 = NULL;
    SDL_Color couleur = {226,206,206},couleur2= {116,106,106};
    int continuer=1,transp=0,compteurTrans=1,son=0,direction=1,direction2=1,direction3=1,mute=0,temps=0,victory=2,choix=0;
    SDL_Event event;
    Uint32 dte,t_prev;

    chargerTous(&ecran,&star,&shab1,&shab2,&shab3,&menu,&texteplay,&textemulti,&texteoption,&textecredits,&textequit,&musique,&effet,&sonspell,&dying,&hit,&effet2,&police,&police1,couleur);
    intro(&ecran);
    remplirlesposition(&positionFond,&posquit,&posmulti,&posoption,&poscredits,&posplay,&posstar,&poscquit,&poscmulti,&poscoption,&poscplay,&posshab1,&posshab2,&posshab3,&posvolb);
    SDL_BlitSurface(menu, NULL, ecran,&positionFond);
    SDL_Flip(ecran);
    Mix_PlayMusic(musique, -1);



    while (continuer)
    {
        while (SDL_PollEvent(&event))
            switch(event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                buttons1(ecran,event,effet,effet2,&continuer,musique,&mute,&posvolb,musiquetuto,sonspell,dying,hit,&victory,&choix);
                break;
            case SDL_MOUSEBUTTONUP:
                buttons(ecran,event,effet,effet2,&continuer,musique,&mute,&posvolb,musiquetuto,sonspell,dying,hit,&victory,&choix);
                break;

            case SDL_MOUSEMOTION:
                affichagetextmenu(&police,&police1,couleur,couleur2,event,&texteplay,&textemulti,&texteoption,&textecredits,&textequit,&commentaireplay,&commentaireoption,&commentairemulti,&commentairequit,effet,&son,&mute);
                break;
            }

        if(continuer)
        {
            positionshab(&posshab1,&posshab2,&posshab3,&direction,&direction2,&direction3);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            SDL_BlitSurface(menu, NULL, ecran, &positionFond);
            SDL_BlitSurface(star, NULL, ecran, &positionFond);
            SDL_BlitSurface(shab3, NULL, ecran, &posshab3);
            SDL_BlitSurface(textemulti, NULL, ecran, &posmulti);
            SDL_BlitSurface(texteplay, NULL, ecran, &posplay);
            SDL_BlitSurface(texteoption, NULL, ecran, &posoption);
            SDL_BlitSurface(textecredits, NULL, ecran, &poscredits);
            SDL_BlitSurface(textequit, NULL, ecran, &posquit);
            SDL_BlitSurface(commentairemulti, NULL, ecran, &poscmulti);
            SDL_BlitSurface(commentaireplay, NULL, ecran, &poscplay);
            SDL_BlitSurface(commentaireoption, NULL, ecran, &poscoption);
            SDL_BlitSurface(commentairequit, NULL, ecran, &poscquit);
            SDL_BlitSurface(shab1, NULL, ecran, &posshab1);
            SDL_BlitSurface(shab2, NULL, ecran, &posshab2);

            SDL_Flip(ecran);
        }
    }

    Mix_FreeChunk(effet2);
    Mix_FreeChunk(effet);
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_FreeSurface(menu);
    SDL_FreeSurface(texteplay);
    SDL_FreeSurface(textemulti);
    SDL_FreeSurface(texteoption);
    SDL_FreeSurface(textecredits);
    SDL_FreeSurface(textequit);
    SDL_FreeSurface(commentaireplay);
    SDL_FreeSurface(commentairemulti);
    SDL_FreeSurface(commentaireoption);
    SDL_FreeSurface(commentairequit);
    SDL_FreeSurface(shab1);
    SDL_FreeSurface(shab2);
    SDL_FreeSurface(shab3);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

