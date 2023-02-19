#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "intro.h"


void intro (SDL_Surface **ecran)
{
	SDL_Surface *logo=NULL, *embleme=NULL,*menu =NULL;
	SDL_Rect poslogo;
	poslogo.x=0;
	poslogo.y=0;
	int i=0;
	SDL_Event event;
	logo=IMG_Load ("image/logo.png");
	embleme=IMG_Load ("image/embleme.png");
	menu=IMG_Load("image/menu.png");

	SDL_FillRect(*ecran, NULL, SDL_MapRGB((*ecran)->format, 0, 0, 0));

	
	while (i!=128)
	{
		SDL_SetAlpha (logo, SDL_SRCALPHA, i);
		SDL_BlitSurface(logo, NULL, (*ecran), &poslogo);
		SDL_Flip(*ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
	
	i=0;
		while (i!=128)
	{
		SDL_SetAlpha (embleme, SDL_SRCALPHA, i);
		SDL_BlitSurface(embleme, NULL,(*ecran), &poslogo);
		SDL_Flip(*ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		{
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
		for(i=0;i<32;i++)
	{
		SDL_SetAlpha (menu, SDL_SRCALPHA, i);
		SDL_BlitSurface(menu, NULL,(*ecran), &poslogo);
		SDL_Flip(*ecran);
		
		
	}
	SDL_FreeSurface(logo);
	SDL_FreeSurface(embleme);
	SDL_FreeSurface(menu);
}
