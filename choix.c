#include "choix.h"
void choix1(SDL_Surface* ecran,Mix_Chunk *effet,Mix_Chunk *effet2,int *mute,int *continuer,int *boucle, int *choix)
{
	SDL_Surface *menu=NULL,*clavier=NULL, *back=NULL,*souris=NULL,*manette=NULL,*souristt=NULL,*claviertt=NULL,*manettett=NULL;
	
	SDL_Rect posmenu,possouris,posclavier,posmanette,posback,possouristt,posclaviertt,posmanettett;
	
	TTF_Font *police = NULL;
	SDL_Color couleur = {226, 206, 206}, couleur2 = {126,106,106};
	
	int boucle1=1,son=0;
	
	SDL_Event event;
	
	    posmenu.x = 0;
    	posmenu.y =0;
    	posclavier.x=450;
    	posclavier.y=15;
    	possouris.x=60;
    	possouris.y=60;
    	posmanette.x=910;
    	posmanette.y=00; 
    	
    	possouristt.x=120;
    	possouristt.y=330;
    	posclaviertt.x=510;
    	posclaviertt.y=330;
    	posmanettett.x=960;
    	posmanettett.y=330;
    	posback.x=120;
    	posback.y=440;
    	
    	TTF_Init();
    	
    	clavier=IMG_Load ("image/clavier.png");
    	souris=IMG_Load ("image/souris.png");
    	manette=IMG_Load ("image/manette.png");
    	
    	
    menu = IMG_Load("image/soumenu.png");
    	SDL_BlitSurface(menu, NULL, ecran, &posmenu);
    	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    	police = TTF_OpenFont("fonts/Takota.ttf", 70);
    	
    	back = TTF_RenderText_Blended(police, "0: BACK", couleur); 
    	claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur); 
    	souristt = TTF_RenderText_Blended(police, "1: Souris", couleur); 
    	manettett = TTF_RenderText_Blended(police, "3: Manette", couleur); 

    	
    	SDL_BlitSurface(souris, NULL, ecran, &possouris);
    	SDL_BlitSurface(clavier, NULL, ecran, &posclavier);
    	SDL_BlitSurface(manette, NULL, ecran, &posmanette); 
    	
    	SDL_BlitSurface(souristt, NULL, ecran, &possouristt);
    	SDL_BlitSurface(claviertt, NULL, ecran, &posclaviertt);
    	SDL_BlitSurface(manettett, NULL, ecran, &posmanettett);
    	SDL_BlitSurface(back, NULL, ecran, &posback);
    	
    	SDL_Flip(ecran);
    	
    	
    	
    	int x,y;
    	float xfloat,volumeeffect;
    	while ((boucle1)&&(*continuer)&&(*boucle))
    	{
    		SDL_GetMouseState(&x,&y);
    		
    		while (SDL_PollEvent(&event))
    		switch(event.type)
    		{
    			case SDL_QUIT:
    				(*continuer)=0;
				(*boucle)=0;
    			break;
    			
          case SDL_MOUSEMOTION:
    			if (event.motion.x<330  && event.motion.x>120 && event.motion.y<410 && event.motion.y>340)
    				{
    					TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);	
                			souristt = TTF_RenderText_Blended(police, "1: Souris", couleur2);
                			if (son==0 && (*mute) ==0)
                			{
                   			 	 son=1;
                   				 Mix_PlayChannel( -1, effet, 0 ) ;
                			}
    				}
    			else if (event.motion.x<750  && event.motion.x>510 && event.motion.y<410 && event.motion.y>340)
    				{
    				TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);	
                			claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur2);
                			if (son==0 && (*mute) ==0)
                			{
                   			 	 son=1;
                   				 Mix_PlayChannel( -1, effet, 0 ) ;
                			}
    				}
    				else if (event.motion.x<1250 && event.motion.x>960 && event.motion.y<410 && event.motion.y>340)
            			{
               				 TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
               				 manettett = TTF_RenderText_Blended(police, "3: Manette", couleur2);
               				 if (son==0 && (*mute) ==0)
                			{
                   			 	 son=1;
                   				 Mix_PlayChannel( -1, effet, 0 ) ;
                			}
            			}
            		else if (event.motion.x<330  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
            			{
                			TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);	
                			back = TTF_RenderText_Blended(police, "0: BACK", couleur2);
                			if (son==0 && (*mute) ==0)
                			{
                   			 	 son=1;
                   				 Mix_PlayChannel( -1, effet, 0 ) ;
                			}
           			}
           		else
                {
                  son=0;
                  TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
                  souristt = TTF_RenderText_Blended(police, "1: Souris", couleur);
                  claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur);
                  manettett = TTF_RenderText_Blended(police, "3: Manette", couleur);
                  back = TTF_RenderText_Blended(police, "0: BACK", couleur);
                }
           			break; 

				case SDL_KEYDOWN:
           		switch (event.key.keysym.sym)
           		{
           			case SDLK_q: 
           				(*continuer)=0;
           			break;

           			case SDLK_KP1:
           			if ((*mute)==0)
           	         {
           		        Mix_PlayChannel( -1, effet2, 0 ) ;
           	         }
           	         souristt = TTF_RenderText_Blended(police, "1: Souris", couleur2);
           	         claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur);
           	         manettett = TTF_RenderText_Blended(police, "3: Manette", couleur);
                	 SDL_BlitSurface(souristt, NULL, ecran, &possouristt);
                	 SDL_BlitSurface(claviertt, NULL, ecran, &posclaviertt);
                	 SDL_BlitSurface(manettett, NULL, ecran, &posmanettett);
           	   		 SDL_Flip(ecran); 
                   (*choix)=1;
           	   		 boucle1=0;    
           			break; 

           			case SDLK_KP2:
           			if ((*mute)==0)
           	         {
           		        Mix_PlayChannel( -1, effet2, 0 ) ;
           	         }
           	         souristt = TTF_RenderText_Blended(police, "1: Souris", couleur);
           	         claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur2);
           	         manettett = TTF_RenderText_Blended(police, "3: Manette", couleur);
                	 SDL_BlitSurface(souristt, NULL, ecran, &possouristt);
                	 SDL_BlitSurface(claviertt, NULL, ecran, &posclaviertt);
                	 SDL_BlitSurface(manettett, NULL, ecran, &posmanettett);
           	   		 SDL_Flip(ecran);
                   (*choix)=2; 
           	   		 boucle1=0;           
           			break; 

           			case SDLK_KP3:
           			if ((*mute)==0)
           	         {
           		        Mix_PlayChannel( -1, effet2, 0 ) ;
           	         }
           	         souristt = TTF_RenderText_Blended(police, "1: Souris", couleur);
           	         claviertt = TTF_RenderText_Blended(police, "2: Clavier", couleur);
           	         manettett = TTF_RenderText_Blended(police, "3: Manette", couleur2);
                	 SDL_BlitSurface(souristt, NULL, ecran, &possouristt);
                	 SDL_BlitSurface(claviertt, NULL, ecran, &posclaviertt);
                	 SDL_BlitSurface(manettett, NULL, ecran, &posmanettett);
           	   		 SDL_Flip(ecran); 
                   (*choix)=3;
           	   		 boucle1=0;    

           		                
           			break; 
           			case SDLK_KP0:
           			boucle1=0; 
           			break;
           		}
           		case SDL_MOUSEBUTTONUP:
				if (event.motion.x<330  && event.motion.x>120 && event.motion.y<410 && event.motion.y>340)
    				{
           					if ((*mute)==0)
           				{
           					Mix_PlayChannel( -1, effet2, 0 ) ;
           				}
                  (*choix)=1;
           				boucle1=0;
           			}
          	else if (event.motion.x<750  && event.motion.x>510 && event.motion.y<410 && event.motion.y>340)
    				  {
    				     if ((*mute)==0)
           				{
           					Mix_PlayChannel( -1, effet2, 0 ) ;
           				}
                  (*choix)=2;
           				boucle1=0;
    				  }
    				else if (event.motion.x<1250 && event.motion.x>960 && event.motion.y<410 && event.motion.y>340)
            			{
               				 if ((*mute)==0)
           				{
           					Mix_PlayChannel( -1, effet2, 0 ) ;
           				}
                  (*choix)=3;
           				boucle1=0;
            			}
            else if (event.motion.x<280  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
           			{
           				if ((*mute)==0)
           				{
           					Mix_PlayChannel( -1, effet2, 0 ) ;
           				}
           				boucle1=0;
           			}            		
				 
            break;
    		}
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, ecran, &posmenu);
        SDL_BlitSurface(back, NULL, ecran, &posback);
        SDL_BlitSurface(souristt, NULL, ecran, &possouristt);
        SDL_BlitSurface(claviertt, NULL, ecran, &posclaviertt);
    	SDL_BlitSurface(manettett, NULL, ecran, &posmanettett);
       SDL_BlitSurface(clavier, NULL, ecran, &posclavier);
      SDL_BlitSurface(souris, NULL, ecran, &possouris);
      SDL_BlitSurface(manette, NULL, ecran, &posmanette); 
	
        SDL_Flip(ecran);
    	}
    }


