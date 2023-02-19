#include "enigme.h"
#include "fonction.h"
#include "option.h"
#include "stage1.h"
#define speed 6
#include <string.h>

void enigme3(SDL_Surface **ecran,int **continuer,Mix_Music **intro,Mix_Chunk **effet,Mix_Chunk **effet2,Mix_Music **musique,int **mute,SDL_Rect **posvolb,Mix_Chunk **dying,int *victory,int *choix)
{
	SDL_Surface *fond=NULL,*gameover=NULL,*solution=NULL,*heroactu=NULL,*hurt=NULL,*idlel=NULL,*idler=NULL,*sol1=NULL,*sol2=NULL,*sol3=NULL,*herod=NULL,*herog=NULL,*platforme1=NULL,*platforme2=NULL,*platforme3=NULL,*bulle1=NULL,*bulle2=NULL,*enigme=NULL,*platforme=NULL,*platformenormal=NULL,*platformepiege=NULL;
	SDL_Rect posfond,poshero,possolution,posgameover,posenigme,framed[8],frame2[8],possol1,possol2,possol3,posplatforme,posbulle,posplatforme1,posvictory,posplatforme2,posplatforme3,posplatformen1,posplatformen2,posplatformen3,posplatformep1,posplatformep2,posplatformep3;
	poshero.x=1200;
	poshero.y=460;
	posfond.x=0;
	posfond.y=0;
	
	SDL_Color couleur ={145,0,0};
	posgameover.x=500;
	posgameover.y=150;
	posvictory.x=200;
	posvictory.y=150;
	possol1.x=110;
	possol1.y=460;
	
	possol2.x=460;
	possol2.y=460;
	
	possol3.x=810;
	possol3.y=460;
	
	posplatformen1.x=50;
	posplatformen1.y=620;
	posplatformen1.w=250;
	posplatformen1.h=68;
	
	posplatformen2.x=400;
	posplatformen2.y=620;
	posplatformen2.w=250;
	posplatformen2.h=68;
	
	posplatformen3.x=750;
	posplatformen3.y=620;
	posplatformen3.w=250;
	posplatformen3.h=68;
	
	posenigme.x=400;
	posenigme.y=0;
	posbulle.x=800;
	posbulle.y=250;
	possolution.x=800;
	possolution.y=250;
	
	posplatformep1.x=50;
	posplatformep1.y=543;
	posplatformep1.w=251;
	posplatformep1.h=145;
	
	posplatformep2.x=400;
	posplatformep2.y=543;
	posplatformep2.w=251;
	posplatformep2.h=145;
	
	posplatformep3.x=750;
	posplatformep3.y=543;
	posplatformep3.w=251;
	posplatformep3.h=145;
	
 	int boucle=1,a=0,posans=460,nb=0,x=0,y=0,e=2,j=0,i=0,CAR3=0,CAR2=0,CAR1=0;
	SDL_Event event;
	solution=IMG_Load("image/enigme/solution.png");
	sol1=IMG_Load("image/decoration/sol1.png");
	sol2=IMG_Load("image/decoration/sol2.png");
	sol3=IMG_Load("image/decoration/sol3.png");
	enigme=IMG_Load("image/enigme/riddle.png");
	bulle1=IMG_Load("image/enigme/bulle1.png");
	bulle2=IMG_Load("image/enigme/bulle2.png");
	hurt=IMG_Load ("image/perso/hert.png");
	platformepiege=IMG_Load("image/decoration/platformepiege.png");
	platformenormal=IMG_Load("image/decoration/platformenormal.png");
	idler=IMG_Load("image/perso/idler.png");
	idlel=IMG_Load("image/perso/idlel.png");
 	herod=IMG_Load("image/perso/wr1.png");
 	herog=IMG_Load("image/perso/wl1.png");
    	heroactu=idlel;
    	for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+250;
			j=0;
		}
		framed[ i ].x=x;
		framed[ i ].y=y;
    		framed[ i ].w =140;
    		framed[ i ].h = 250;
    		x=x+140;
    		j++;
	}
    	x=0;
    	y=0;
    	j=0;
    	for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+250;
			j=0;
		}
		frame2[ i ].x=x;
		frame2[ i ].y=y;
    		frame2[ i ].w =250;
    		frame2[ i ].h = 250;
    		x=x+250;
    		j++;
	}
    	i=0;
    	SDL_Color couleur2 ={226,206,206};
 	TTF_Font *fonts = NULL;
 	fond=IMG_Load ("image/stage/enigme.png");
 	fonts = TTF_OpenFont("fonts/Takota.ttf", 900);
 	SDL_BlitSurface(fond, NULL,*ecran, &posfond);
 	SDL_BlitSurface(bulle1, NULL, *ecran, &posbulle);
 	SDL_BlitSurface(heroactu, &framed[0], *ecran, &poshero);
 	SDL_Flip(*ecran);
 	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
 	SDL_Delay(4000);
 	Uint8 *keystates = SDL_GetKeyState( NULL );
 	fonts = TTF_OpenFont("fonts/Takota.ttf", 70);
	posplatforme1=posplatformen1;
	posplatforme2=posplatformen2;
	posplatforme3=posplatformen3;
	platforme1=platformenormal;
	platforme3=platformenormal;
	platforme2=platformenormal;
	int tempsActuel = 0;
	while ((boucle)&&((*continuer)))
	{
		tempsActuel = SDL_GetTicks();
		while (SDL_PollEvent(&event))
       		switch(event.type)
       		{
       			case SDL_QUIT:
            			(*continuer) = 0;
            		break;
            		case SDL_VIDEORESIZE:
				*ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
    			break;
    			case SDL_KEYDOWN:
            		switch (event.key.keysym.sym)
            		{
            		case SDLK_u:
            		//stage0(*ecran,*continuer,*intro,*effet,*effet2,*musique,*mute,*posvolb);
            		boucle=0;
            		break;
            		case SDLK_TAB:
            		option(*ecran,*effet,*effet2,*musique,*mute,*continuer,*posvolb,choix);
            		break;
            		case SDLK_j:
            		if (collision(poshero,posplatformen1)==1)
            		{
				*victory=0;	
            			Mix_PlayChannel( -1, *dying, 0 ) ;
            			platforme1=platformepiege;
            			posplatforme1=posplatformep1;
            			i=0;
            			heroactu=hurt;
				
            			for (j=0; j<43; j++)
            			{
            				//animation(&heroactu,hurt,&i);
            				SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 					SDL_BlitSurface(sol1, NULL, *ecran, &possol1);
 					SDL_BlitSurface(sol2, NULL, *ecran, &possol2);
 					SDL_BlitSurface(sol3, NULL, *ecran, &possol3);
 					SDL_BlitSurface(platforme1, NULL, *ecran, &posplatforme1);
 					SDL_BlitSurface(platforme2, NULL, *ecran, &posplatforme2);
 					SDL_BlitSurface(platforme3, NULL, *ecran, &posplatforme3);
 					SDL_BlitSurface(enigme, NULL, *ecran, &posenigme);
 					SDL_BlitSurface(heroactu,&frame2[j/6], *ecran, &poshero);
 					SDL_Flip(*ecran);
            			}
            			gameover=TTF_RenderText_Blended(fonts, "WRONG ANSWER", couleur);
            			SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 				SDL_BlitSurface(sol1, NULL, *ecran, &possol1);
 				SDL_BlitSurface(sol2, NULL, *ecran, &possol2);
 				SDL_BlitSurface(sol3, NULL, *ecran, &possol3);
 				SDL_BlitSurface(platforme1, NULL, *ecran, &posplatforme1);
 				SDL_BlitSurface(platforme2, NULL, *ecran, &posplatforme2);
 				SDL_BlitSurface(platforme3, NULL, *ecran, &posplatforme3);
 				SDL_BlitSurface(heroactu,&frame2[8], *ecran, &poshero);
 				SDL_BlitSurface(gameover,NULL, *ecran, &posgameover);
 				SDL_Flip(*ecran);
 				SDL_Delay(4000);
 				boucle=0;
            			
            		}
            		
            	        if (collision(poshero,posplatformen2)==1)
            		{	
            		
            			gameover=TTF_RenderText_Blended(fonts, "GOOD JOB!", couleur);
            			*victory=1;
                                        SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 				        SDL_BlitSurface(gameover,NULL, *ecran, &posgameover);
 				        SDL_Flip(*ecran);
 				        SDL_Delay(4000);

            			boucle=0;
            		}
            		
            		if (collision(poshero,posplatformen3)==1)
            		{       
            		        *victory=0;
            			Mix_PlayChannel( -1, *dying, 0 ) ;
            			platforme3=platformepiege;
            			posplatforme3=posplatformep3;
            			i=0;
            			heroactu=hurt;
            			for (j=0; j<43; j++)
            			{
            				//animation(&heroactu,hurt,&i);
					SDL_BlitSurface(sol1, NULL, *ecran, &possol1);
 					SDL_BlitSurface(sol2, NULL, *ecran, &possol2);
 					SDL_BlitSurface(sol3, NULL, *ecran, &possol3);
            				SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 					SDL_BlitSurface(platforme1, NULL, *ecran, &posplatforme1);
 					SDL_BlitSurface(platforme2, NULL, *ecran, &posplatforme2);
 					SDL_BlitSurface(platforme3, NULL, *ecran, &posplatforme3);
 					SDL_BlitSurface(enigme, NULL, *ecran, &posenigme);
 					SDL_BlitSurface(heroactu,&frame2[j/6], *ecran, &poshero);
 					SDL_Flip(*ecran);
            			}
            			gameover=TTF_RenderText_Blended(fonts, "WRONG ANSWER", couleur);
            			SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 				SDL_BlitSurface(sol1, NULL, *ecran, &possol1);
 				SDL_BlitSurface(sol2, NULL, *ecran, &possol2);
 				SDL_BlitSurface(sol3, NULL, *ecran, &possol3);
 				SDL_BlitSurface(platforme1, NULL, *ecran, &posplatforme1);
 				SDL_BlitSurface(platforme2, NULL, *ecran, &posplatforme2);
 				SDL_BlitSurface(platforme3, NULL, *ecran, &posplatforme3);
 				SDL_BlitSurface(heroactu,&frame2[8], *ecran, &poshero);
 				SDL_BlitSurface(gameover,NULL, *ecran, &posgameover);
 				SDL_Flip(*ecran);
 				
 				SDL_Delay(4000);
 				boucle=0;


            		break;
            		}
            		}
            	}
            	if(keystates == SDL_GetKeyState(NULL))
		{
		if(e==1)
		animation(&heroactu,idler,&i);
		if(e==2)
		animation(&heroactu,idlel,&i);
		}
            	if(keystates[SDLK_k])
		{
            			if (a==0 || CAR3==1 || CAR2==1 || CAR1==1)
            			{
            				posans=poshero.y;
            				a=1;
            			}
		}
		if(keystates[SDLK_d])
		{
			        e=1;
            			animation(&heroactu,herod,&i);
				poshero.x+=speed;
		}
		if(keystates[SDLK_q])
		{
            			e=2;           			
            			animation(&heroactu,herog,&i); 
            			poshero.x-=speed;
		}
		if (poshero.x+poshero.w>=(*ecran)->w)
		{
			poshero.x-=speed;
		}
            	        if (collision(poshero,posplatformen1)==0)
            		{
            			platforme1=platformenormal;
            			posplatforme1=posplatformen1;
            		}
            		if (collision(poshero,posplatformen3)==0)
            		{
            			platforme3=platformenormal;
            			posplatforme3=posplatformen3;
            		}
            		if (a==1)
		{
			poshero.y-=9;
			if (poshero.y<=posans-160)
			{
				a=2;
			}
		}
		else if (a==2 && CAR3==0 && CAR2==0 && CAR1==0)
		{
			poshero.y+=9;
			if (poshero.y>=460)
			{
				a=0;
			}
		}
		//collision avec 1ere platforme
		if (collision(poshero,posplatforme1)==1 && e==1 && a==0) 
			{ 
			poshero.x-=speed;
			}
		if (collision(poshero,posplatforme1)==1 && e==2 && a==0) 
			{ 
			poshero.x+=speed;
			}
		if (collision(poshero,posplatforme1)==1 && a==2)
			{
			CAR3=1;
			} 
		if (collision(poshero,posplatforme1)==0)
			{
			CAR3=0;
			}
		//collision 2eme platforme
		if (collision(poshero,posplatforme2)==1 && e==1 && a==0) 
			{ 
			poshero.x-=speed;
			}
		if (collision(poshero,posplatforme2)==1 && e==2 && a==0) 
			{ 
			poshero.x+=speed;
			}
		if (collision(poshero,posplatforme2)==1 && a==2)
			{
			CAR2=1;
			} 
		if (collision(poshero,posplatforme2)==0)
			{
			CAR2=0;
			}  
		//collision 1ere platforme
		if (collision(poshero,posplatforme3)==1 && e==1 && a==0) 
			{ 
			poshero.x-=speed;
			}
		if (collision(poshero,posplatforme3)==1 && e==2 && a==0) 
			{ 
			poshero.x+=speed;
			}
		if (collision(poshero,posplatforme3)==1 && a==2)
			{
			CAR1=1;
			} 
		if (collision(poshero,posplatforme3)==0)
			{
			CAR1=0;
			}  
		if (tempsActuel >=5000)
		{
			SDL_BlitSurface(solution, NULL, *ecran, &possolution);
		}  
       		SDL_BlitSurface(fond, NULL, *ecran, &posfond);
 		SDL_BlitSurface(platforme1, NULL, *ecran, &posplatforme1);
 		SDL_BlitSurface(platforme2, NULL, *ecran, &posplatforme2);
 		SDL_BlitSurface(platforme3, NULL, *ecran, &posplatforme3);
 		SDL_BlitSurface(sol1, NULL, *ecran, &possol1);
 		SDL_BlitSurface(sol2, NULL, *ecran, &possol2);
 		SDL_BlitSurface(sol3, NULL, *ecran, &possol3);
 		SDL_BlitSurface(enigme, NULL, *ecran, &posenigme);
 		SDL_BlitSurface(heroactu,&framed[i/4], *ecran, &poshero);
 		SDL_BlitSurface(gameover,NULL, *ecran, &posgameover);
 		SDL_Flip(*ecran);
	}
}
