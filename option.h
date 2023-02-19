#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include"choix.h"

void option(SDL_Surface* ecran,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,int *continuer,SDL_Rect *posvolb,int *choix);
//void choix(SDL_Surface* ecran,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music **musique,int *mute,int *continuer,int *boucle,SDL_Rect *posvolb);
