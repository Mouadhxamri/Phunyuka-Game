//option

#include "sound.h"
#include "choix.h"


void option(SDL_Surface* ecran,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,int *continuer,SDL_Rect *posvolb,int *choix)
{
    SDL_Surface *menu = NULL, *textsett=NULL,*textesound=NULL,*texteback=NULL;
    SDL_Rect positionFond, posback, possound, possett;
    TTF_Font *police = NULL;
    SDL_Color couleur ={226,206,206},couleur2={116,106,106};


    int boucle=1,pause=0,son=0;
    SDL_Event event;

    positionFond.x = 0;
    positionFond.y =0;
    possett.x=120;
    possett.y=200;
    possound.x=120;
    possound.y=320;
    posback.x=120;
    posback.y=440;

    TTF_Init();

    menu = IMG_Load("image/soumenu.png");
    SDL_BlitSurface(menu, NULL, ecran, &positionFond);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    police = TTF_OpenFont("fonts/Takota.ttf", 70);
    textsett = TTF_RenderText_Blended(police, "1: GAME SETTINGS", couleur);
    textesound = TTF_RenderText_Blended(police, "2: SOUND", couleur);
    texteback = TTF_RenderText_Blended(police, "0: BACK", couleur);
    SDL_BlitSurface(textesound, NULL, ecran, &possound);
    SDL_BlitSurface(textsett, NULL, ecran, &possett);
    SDL_BlitSurface(texteback, NULL, ecran, &posback);
    SDL_Flip(ecran);

    while ((boucle)&&((*continuer)))
    {
        while (SDL_PollEvent(&event))
        switch(event.type)
        {
        case SDL_QUIT:
            (*continuer) = 0;
            break;

        case SDL_MOUSEMOTION:
            if (event.motion.x<650  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200)
            {
                TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                textsett = TTF_RenderText_Blended(police, "1: GAME SETTINGS", couleur2);
                if (son==0 && *mute==0)
                {
                    son=1;
                    Mix_PlayChannel( -1, effet, 0 ) ;
                }
            }
            else if (event.motion.x<370  && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
            {
                TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                textesound = TTF_RenderText_Blended(police, "2: SOUND", couleur2);
                if (son==0 && *mute==0)
                {
                    son=1;
                    Mix_PlayChannel( -1, effet, 0 ) ;
                }
            }
            else if (event.motion.x<330  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
            {
                TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                texteback = TTF_RenderText_Blended(police, "0: BACK", couleur2);
                if (son==0 && *mute==0)
                {
                    son=1;
                    Mix_PlayChannel( -1, effet, 0 ) ;
                }
            }
            else
            {
                son=0;
                TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
                textsett = TTF_RenderText_Blended(police, "1: GAME SETTINGS", couleur);
                textesound = TTF_RenderText_Blended(police, "2: SOUND", couleur);
                texteback = TTF_RenderText_Blended(police, "0: BACK", couleur);
            }

            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                (*continuer) = 0;
                break;
            case SDLK_KP3:
                  if ((*mute)==0)
           	{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           	}
                boucle=0;
               break;
	    case SDLK_KP2:
	        if ((*mute)==0)
           	{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           	}
            	sound(ecran,effet,effet2,&musique,mute,continuer,&boucle,posvolb);
            	break;
      case SDLK_KP1:
                if ((*mute)==0)
           	{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           	}
               choix1(ecran,effet,effet2,mute,continuer,&boucle,choix);
                   break;
		 case SDLK_KP0:
		 boucle=0;
		 break;
            }
        
        case SDL_MOUSEBUTTONUP:

          if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<330  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
           {
                if ((*mute)==0)
           	{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           	}
                boucle=0;
		          event.button.button=0;
          }
          else if (event.motion.x<370  && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
           {
            	if ((*mute)==0)
           	{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           	}
            	sound(ecran,effet,effet2,&musique,mute,continuer,&boucle,posvolb);
           }
           else if (event.motion.x<370  && event.motion.x>120 && event.motion.y<280 && event.motion.y>220)
           {
              if ((*mute)==0)
            {
              Mix_PlayChannel( -1, effet2, 0 ) ;
            }
              choix1(ecran,effet,effet2,mute,continuer,&boucle,choix);
           }

            break;
        }
if(boucle)
{

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, ecran, &positionFond);
        SDL_BlitSurface(textesound, NULL, ecran, &possound);
        SDL_BlitSurface(textsett, NULL, ecran, &possett);
        SDL_BlitSurface(texteback, NULL, ecran, &posback);
        SDL_Flip(ecran);
}
    }

    SDL_FreeSurface(menu);
    SDL_FreeSurface(textesound);
    SDL_FreeSurface(textsett);
    SDL_FreeSurface(texteback);
    TTF_CloseFont(police);
    TTF_Quit();

}

