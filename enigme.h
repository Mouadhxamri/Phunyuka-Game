#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <time.h>

void enigme3(SDL_Surface **ecran,int **continuer,Mix_Music **intro,Mix_Chunk **effet,Mix_Chunk **effet2,Mix_Music **musique,int **mute,SDL_Rect **posvolb,Mix_Chunk **dying, int *victory,int *choix);
