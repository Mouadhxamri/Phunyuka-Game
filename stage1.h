#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>


void Blit(SDL_Surface* source,SDL_Surface* dest,int x,int y);
void stage0(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell);
void stage1(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix);
void stage1s(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit,int *victory,int *choix);
