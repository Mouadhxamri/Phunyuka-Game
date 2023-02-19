#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "debut.h"
#include "fonction.h"
#include <SDL/SDL_rotozoom.h>
void debut(SDL_Surface *ecran)
{
/*SDL_Surface *parag[8]={NULL},*black=NULL,*skip=NULL,*paragg=NULL;
SDL_Rect postexte,posskip,pos;
posskip.x=1100;
posskip.y=650;
pos.x=0;
pos.y=0;
postexte.x=0;
postexte.y=770;
parag[0]=IMG_Load ("image/histoire/parag1.png");
parag[1]=IMG_Load ("image/histoire/parag2.png");
parag[2]=IMG_Load ("image/histoire/parag3.png");
parag[3]=IMG_Load ("image/histoire/parag4.png");
parag[4]=IMG_Load ("image/histoire/parag5.png");
parag[5]=IMG_Load ("image/histoire/parag6.png");
parag[6]=IMG_Load ("image/histoire/parag7.png");
parag[7]=IMG_Load ("image/histoire/parag8.png");
black=IMG_Load ("image/histoire/black.png");
Mix_Music *intro;
SDL_Color couleurr ={255,255,255};
int continuer=1,i=0,j=0,a=0;
SDL_Event event;
intro = Mix_LoadMUS("music/tuto.mp3");
TTF_Font *text = NULL;
text=TTF_OpenFont("fonts/Takota.ttf", 30);
skip=TTF_RenderText_Blended(text,"Press x to skip",couleurr);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface (skip,NULL,ecran,&posskip);
SDL_Flip(ecran);
for (j=0; j<8;j++)
{
	postexte.y=770;
	paragg=parag[j];
	if (j==2)
	{
		postexte.y=400;
		for (i=0; i<400;i++)
		{
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
			SDL_BlitSurface(paragg, NULL, ecran, &postexte);
			SDL_BlitSurface(skip, NULL, ecran, &posskip);
			SDL_Flip(ecran);
			postexte.y=postexte.y-2;
			while (SDL_PollEvent(&event))
			switch(event.type)
			 {
		 		case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
		 			case SDLK_x:
					Mix_PlayMusic(intro, -1);
		 			j=7;
					i=600;
		 			break;
					
					case SDLK_p:
					i=850;
		 			break;
		 		}
			 }
		}
	}
	else if (j>=6)
	{	
		if (a==1)
		{
			Mix_FadeOutMusic(3000) && Mix_PlayingMusic();
			Mix_PlayMusic(intro, -1);	
		}
		for (i=0; i<850; i++)
		{
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
			SDL_BlitSurface(paragg, NULL, ecran, &postexte);
			if (a==2)
			{
				SDL_BlitSurface(skip, NULL, ecran, &posskip);
			}
			if (i>=600)
			{
				SDL_BlitSurface(skip, NULL, ecran, &posskip);
				a=2;
			}
			SDL_Flip(ecran);
			postexte.y--;
			while (SDL_PollEvent(&event))
			switch(event.type)
		 	{
		 		case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
		 				case SDLK_x:
						Mix_PlayMusic(intro, -1);
		 				j=7;
						i=850;
		 				break;
		 			
		 				case SDLK_p:
						i=850;
		 				break;
		 		}
		 	}
		 }
	}
	else
	{
		for (i=0; i<850; i++)
		{
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
			SDL_BlitSurface(paragg, NULL, ecran, &postexte);
			if (a==1)
			{
				SDL_BlitSurface(skip, NULL, ecran, &posskip);
			}	
			if (i>=600)
			{
				SDL_BlitSurface(skip, NULL, ecran, &posskip);
				a=1;
			}
			SDL_Flip(ecran);
			postexte.y--;
			while (SDL_PollEvent(&event))
			switch(event.type)
		 	{
		 		case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
		 			case SDLK_x:
					Mix_PlayMusic(intro, -1);
		 			j=7;
					i=850;
		 			break;
		 			
		 			case SDLK_p:
					i=850;
		 			break;
		 		}
			 }
		}
	}
	i=0;
	while (i!=32)
	{
		SDL_SetAlpha (black, SDL_SRCALPHA, i);
		SDL_BlitSurface(black, NULL, ecran, &pos);
		SDL_BlitSurface(skip, NULL, ecran, &posskip);
		SDL_Flip(ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		postexte.y=950;
		 		break;
		 	}
		 }
	}
}
SDL_FreeSurface(paragg);
for (i=0; i<8; i++)
{
	SDL_FreeSurface(parag[i]);
}
SDL_FreeSurface(skip);
*/
}
