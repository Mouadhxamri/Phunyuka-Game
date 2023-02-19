/**
* @file main.c
* @brief Testing Program.
* @author  wiem trifi
* @version 0.1
* @date juin 01, 2020
*
* Testing program for mini map
*
*/

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
void main ()
{ int i,j,x=0,y=0,w=0;
SDL_Surface *screen;
  SDL_Surface *image,*petit=NULL,*barre=NULL;
  SDL_Rect positionecran,posdetective,posdetective1,posbarre,frame3[8];
for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+50;
			j=0;
		}
		frame3[ i ].x=x;
		frame3[ i ].y=y;
    		frame3[ i ].w =28;
    		frame3[ i ].h = 50;
    		x=x+28;
    		j++;
	}
  char pause;
  int done=1;
  SDL_Event event;
  Mix_Music *music;
  SDL_Surface *bg;
  SDL_Rect posbg;
posdetective.x=800;
	posdetective.y=10;
posdetective1.x=800;
	posdetective1.y=200;
posbarre.x=800;
	posbarre.y=60;
petit=IMG_Load("petit.png");
barre=IMG_Load ("barre.png");
  if(SDL_Init(SDL_INIT_VIDEO)!=0)
  {
      printf("Error: %s\n",SDL_GetError());

  }
  screen = SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(!screen)
  {
      printf("Error 2: %s\n",SDL_GetError());

  }
  image = IMG_Load("detective.png");


  bg = SDL_LoadBMP("background.bmp");

  if(!image)
  {
     printf("Error: %s\n",SDL_GetError());

  }

  positionecran.x = 225-32;    posbg.x = 0;
  positionecran.y = 225-32;    posbg.y = 0;
  positionecran.h = image->h;  posbg.h = image->h;
  positionecran.w = image->w;  posbg.w = image->w;

  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    printf("Error : %s",Mix_GetError());
  music = Mix_LoadMUS("music.mp3");
  Mix_PlayMusic(music,-1);
  while(done)
  {
    SDL_BlitSurface(bg,NULL,screen,&posbg);
    SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format,255,255,255));
  SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(barre, NULL, screen, &posbarre);
SDL_BlitSurface(petit, &frame3[w/4], screen, &posdetective);	
       		                		
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN:
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
           positionecran.x -= 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
posdetective.x-=1;
SDL_BlitSurface(petit, &frame3[w/4], screen, &posdetective);

         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            positionecran.x += 5;

           SDL_BlitSurface(image,NULL,screen,&positionecran);
posdetective.x+=1;
SDL_BlitSurface(petit, &frame3[w/4], screen, &posdetective);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
           
           positionecran.y -= 5;
            SDL_BlitSurface(image,NULL,screen,&positionecran);
posdetective.y-=1;
SDL_BlitSurface(petit, &frame3[w/4], screen, &posdetective);

         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          positionecran.y += 5;
            //affichage d image
            SDL_BlitSurface(image,NULL,screen,&positionecran);

         }
        break; case SDL_QUIT:

        break;
      }
    }}
 Mix_FreeMusic(music);
  SDL_FreeSurface(image);

}
