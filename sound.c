	//sound

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

void sound(SDL_Surface* ecran,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music **musique,int *mute,int *continuer,int *boucle,SDL_Rect *posvolb)
{
	SDL_Surface *menu=NULL, *couper=NULL, *volume =NULL, *bar=NULL,*volb=NULL, *back=NULL,*volumeoff=NULL,*volumeoff1=NULL,*volumeon=NULL,*volumeon1=NULL,*sounds=NULL;
	SDL_Rect posmenu,poscouper,posvolume,posback,posvolumeoff,posbar;
	TTF_Font *police = NULL;
	SDL_Color couleur = {226, 206, 206}, couleur2 = {126,106,106};
	
	int boucle1=1,son=0,p=15;
	
	SDL_Event event;
	posbar.x=440;
	posbar.y=365;
	posmenu.x = 0;
    	posmenu.y =0;
    	posvolumeoff.x=420;
    	posvolumeoff.y=215;
    	poscouper.x=120;
    	poscouper.y=200;
    	posvolume.x=120;
    	posvolume.y=320;
    	posback.x=120;
    	posback.y=440;
    	
    	TTF_Init();
    	bar=IMG_Load ("image/bar.png");
    	volb=IMG_Load ("image/boutonv.png");
    	volumeoff=IMG_Load ("image/volumeoff.png");
    	volumeoff1=IMG_Load ("image/volumeoff1.png");
    	volumeon=IMG_Load ("image/volumeon.png");
    	volumeon1=IMG_Load ("image/volumeon1.png");
    	menu = IMG_Load("image/soumenu.png");
    	SDL_BlitSurface(menu, NULL, ecran, &posmenu);
    	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    	police = TTF_OpenFont("fonts/Takota.ttf", 70);
    	couper = TTF_RenderText_Blended(police, "1: MUTE", couleur);
    	volume = TTF_RenderText_Blended(police, "2: VOLUME", couleur);
    	back = TTF_RenderText_Blended(police, "0: BACK", couleur);
    	SDL_BlitSurface(bar, NULL, ecran, &posbar);
    	SDL_BlitSurface(volb, NULL, ecran, posvolb);
    	SDL_BlitSurface(couper, NULL, ecran, &poscouper);
    	SDL_BlitSurface(volume, NULL, ecran, &posvolume);
    	SDL_BlitSurface(back, NULL, ecran, &posback);
    	if ((*mute)==0)
        {
        	SDL_BlitSurface(volumeon, NULL, ecran, &posvolumeoff);
        	sounds=volumeon;
        }
        else if ((*mute)==1)
        {
        	SDL_BlitSurface(volumeoff, NULL, ecran, &posvolumeoff);
        	sounds=volumeoff;
        }
    	SDL_Flip(ecran);
    	
    	
    	
    	int x,y;
    	float xfloat,volumeeffect;
    	while ((boucle1)&&(*continuer)&&(*boucle))
    	{
    		SDL_GetMouseState(&x,&y);
    		if(hover(posbar,x,y)){
        	if((x<625 && x>400) && event.button.button == SDL_BUTTON_LEFT)
		{
        		posvolb->x = x;
        		xfloat = x;
       			volumeeffect = ((x-440)*128)/(660-400);        
        		Mix_VolumeMusic(volumeeffect);
        		//Mix_PlayChannel(1,buttonsound,0);
        		}
    		}
    		while (SDL_PollEvent(&event))
    		switch(event.type)
    		{
    			case SDL_QUIT:
    				(*continuer)=0;
				(*boucle)=0;
    			break;
    			case SDL_MOUSEMOTION:
    				if (event.motion.x<340  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200&&(*mute)==0)
    				{
    					if ((*mute)==0)
    					{
    						sounds=volumeon1;
    						TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                				couper = TTF_RenderText_Blended(police, "1: MUTE", couleur2);
                			}
                			else 
                			{
                				sounds=volumeoff1;
    						TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                				couper = TTF_RenderText_Blended(police, "1: UNMUTE", couleur2);
                			}
                			if (son==0 && (*mute) ==0)
                			{
                    				son=1;
                   				Mix_PlayChannel( -1, effet, 0 ) ;
                			}
    				}
    				else if (event.motion.x<420  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200&&(*mute)!=0)
    				{
    				if ((*mute)==0)
    					{
    						sounds=volumeon1;
    						TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                				couper = TTF_RenderText_Blended(police, "1: MUTE", couleur2);
                			}
                			else 
                			{
                				sounds=volumeoff1;
    						TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
                				couper = TTF_RenderText_Blended(police, "1: UNMUTE", couleur2);
                			}
                			if (son==0 && (*mute) ==0)
                			{
                    				son=1;
                   				Mix_PlayChannel( -1, effet, 0 ) ;
                			}
    				}
    				else if (event.motion.x<330 && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
            			{
               				 TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
               				 volume = TTF_RenderText_Blended(police, "2: VOLUME", couleur2);
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
                			if ((*mute==0))
                			{
                				couper = TTF_RenderText_Blended(police, "1: MUTE", couleur);
                				sounds=volumeon;
                			}
                			else
                			{
                				couper = TTF_RenderText_Blended(police, "1: UNMUTE", couleur);
                				sounds=volumeoff;
                			}
                			volume = TTF_RenderText_Blended(police, "2: VOLUME", couleur);
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
           					sounds=volumeoff1;
           					(*mute)=1;
                				couper = TTF_RenderText_Blended(police, "1: UNMUTE", couleur);
                				SDL_BlitSurface(volumeon1, NULL, ecran, &posvolumeoff);
           					SDL_Flip(ecran);
                       				Mix_HaltMusic();
           			}
           			else if ((*mute)!=0)
           			{
           				(*mute)=0;
           					sounds=volumeon1;
                				couper = TTF_RenderText_Blended(police, "1: MUTE", couleur2);
                				SDL_BlitSurface(couper,NULL,ecran,&poscouper);
                				SDL_Flip(ecran);
                				Mix_PlayMusic((*musique), -1);
                                }
           			break;
           			case SDLK_KP0:
           			boucle1=0;
           			break;
           		}
           		case SDL_MOUSEBUTTONUP:
				if (event.motion.x<340  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200&&(*mute)==0)
           			{
           					sounds=volumeoff1;
           					(*mute)=1;
                				couper = TTF_RenderText_Blended(police, "1: UNMUTE", couleur2);
                				SDL_BlitSurface(volumeon1, NULL, ecran, &posvolumeoff);
           					SDL_Flip(ecran);
                       				Mix_HaltMusic();
           			}
           			else if (event.motion.x<320  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200&&(*mute)!=0)
           			{
           				(*mute)=0;
           					sounds=volumeon1;
                				couper = TTF_RenderText_Blended(police, "1: MUTE", couleur2);
                				SDL_BlitSurface(couper,NULL,ecran,&poscouper);
                				SDL_Flip(ecran);
                				Mix_PlayMusic((*musique), -1);
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
        SDL_BlitSurface(couper, NULL, ecran, &poscouper);
        SDL_BlitSurface(volume, NULL, ecran, &posvolume);
        SDL_BlitSurface(back, NULL, ecran, &posback);
        SDL_BlitSurface(sounds,NULL,ecran,&posvolumeoff);
        SDL_BlitSurface(bar, NULL, ecran, &posbar);
    	SDL_BlitSurface(volb, NULL, ecran, posvolb);
	
        SDL_Flip(ecran);
    	}
}
