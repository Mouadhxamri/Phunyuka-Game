#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "stage1.h"
#include "multi.h"
#include "option.h"
#include "sound.h"
#include "fonction.h"
#include "enigme.h"
#define speed  6

void Multi(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit,int *choix)
{
	SDL_Surface *background=NULL,*animwitch=NULL,*background2=NULL,*blackground=NULL,*spell=NULL,*spellen=NULL,*enemieattackl=NULL,*enemieattackr=NULL,*enemieidler=NULL,*enemieidlel=NULL,*gif[8]={NULL},*Gif=NULL,*hurt=NULL,*witch=NULL,*witchattack=NULL,*witchd=NULL,*witchg=NULL,*attackr=NULL,*attackl=NULL,*herod=NULL,*herog=NULL,*heroactu=NULL,*ennemie=NULL,*ennemied=NULL,*ennemieg=NULL,*idlel=NULL,*idler=NULL,*bande=NULL;
	SDL_Rect posbackg1,framedw[8],posgif,posspell,posspell1,posbackg2,poshero,posennemie,camera1,camera2,camera3,framed[8],frame2[8],posbande,posherosplit,posennemiesplit,poswitch;
	int boucle=1,j=0,i=0,x=0,y=0,e=1,e1=2,split=1,intspell=0,p=0,k=0,kk=0,jump=0,jump1=0,posansenemie=460,posans=460,heroattack=0,enemattack=0;
	int nbrspell=0,intspell1=0,nbrspell1=0;
	Uint8 *keystates = SDL_GetKeyState( NULL );
	bande =SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 786, 32, 0, 0, 0, 0);
	background=IMG_Load ("image/stage/map2.png");
	background2=IMG_Load ("image/stage/map3.png");
	herod=IMG_Load ("image/perso/wr1.png");
	herog=IMG_Load ("image/perso/wl1.png");
	ennemied=IMG_Load ("image/enemies/en1wr.png");
	ennemieg=IMG_Load ("image/enemies/en1wl.png");
	idler=IMG_Load ("image/perso/idler.png");
	idlel=IMG_Load ("image/perso/idlel.png");
	enemieidler=IMG_Load ("image/enemies/enemie1idler.png");
	enemieidlel=IMG_Load ("image/enemies/enemie1idlel.png");
	hurt=IMG_Load ("image/perso/hert.png");
	attackr=IMG_Load ("image/perso/ar.png");
	attackl=IMG_Load ("image/perso/al.png");
	enemieattackr=IMG_Load ("image/enemies/en1a.png");
	enemieattackl=IMG_Load ("image/enemies/en1al.png");
	witchattack=IMG_Load ("image/enemies/witchattack.png");
	witchg=IMG_Load ("image/enemies/witchwalkleft.png");
	witchd=IMG_Load ("image/enemies/witchwalkright.png");
	spell=IMG_Load ("image/decoration/spell.png");
	spellen=IMG_Load ("image/decoration/spellenemie.png");
	gif[0]=SDL_LoadBMP("image/gif/1.bmp");
	gif[1]=IMG_Load("image/gif/2.png");
	gif[2]=IMG_Load("image/gif/3.png");
	gif[3]=IMG_Load("image/gif/4.png");
	gif[4]=IMG_Load("image/gif/5.png");
	gif[5]=IMG_Load("image/gif/6.png");
	gif[6]=IMG_Load("image/gif/7.png");
	gif[7]=IMG_Load("image/gif/8.png");
	blackground=SDL_LoadBMP("image/stage/ok.bmp");
	animwitch=SDL_LoadBMP("image/enemies/witch.bmp");
	SDL_Event event;
	
	posgif.x=380;
	posgif.y=180;
	posbande.x=678;
	posbande.y=0;
	
	posennemiesplit.x=1400;
	posennemiesplit.y=460;
	
	posherosplit.x=0;
	posherosplit.y=460;
	
	posbackg1.x=0;
	posbackg1.y=0;
	
	posbackg2.x=683;
	posbackg2.y=0;
	
	poshero.x=0;
	poshero.y=460;
	
	posennemie.x=2800;
	posennemie.y=460;
	
	camera1.x=0;
	camera1.y=0;
	camera1.w=683;
	camera1.h=768;
	
	camera2.x=2500;
	camera2.y=0;
	camera2.w=683;
	camera2.h=768;
	
	camera3.x=0;
	camera3.y=0;
	camera3.w=1366;
	camera3.h=768;
	
	poswitch.x=620;
	poswitch.y=320;
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
    	x=0;
    	j=0;
    	y=0;
    	witch=witchd;
    	ennemie=ennemieg;
    	heroactu=herod;
    	//SDL_EnableKeyRepeat(10,70);
    	while ((boucle)&&((*continuer)))
    	{
    		while (SDL_PollEvent(&event))
       		switch(event.type)
        	{
        	
        		case SDL_QUIT:
            		(*continuer) = 0;
            		break;
        	}
        	if(keystates == SDL_GetKeyState(NULL))
		{
			if(heroattack==0)
			{
			if(e==1)
			animation(&heroactu,idler,&i);
			if(e==2)
			animation(&heroactu,idlel,&i);
			}
			if(enemattack==0)
			{
			if(e1==1)
               		animation3(&ennemie,enemieidler,&x);
			if(e1==2)
			animation3(&ennemie,enemieidlel,&x);
			}
		}
        	if(keystates[SDLK_q]&&heroattack==0)
            		{
            			e=2;
            			animation(&heroactu,herog,&i);
            			poshero.x-=5;
            			if (split==0)
            			{
            				posherosplit.x-=5;
            			}
            			if (poshero.x>200)
            			{
            				camera1.x-=5;
            				if (split==1)
            				{
            					camera3.x-=5;	
            				}
            			}
            		}
            		
            	if(keystates[SDLK_d]&&heroattack==0)
            		{
            			e=1;
            			animation(&heroactu,herod,&i);
            			poshero.x+=5;
            			if (split==0)
            			{
            				posherosplit.x+=5;
            			}
            			if (poshero.x>230)
            			{
            				camera1.x+=5;
            				if (split==1)
            				{
            					camera3.x+=5;
            				}
            			}
            			if (poshero.x>9600)
            			{
            				poshero.x-=5;
            			}
            		}
            		if(keystates[SDLK_LEFT]&&enemattack==0)
            		{
            			e1=2;
            			animation3(&ennemie,ennemieg,&x);
            			posennemie.x-=5;
            			if (split==0)
            			{
            				posennemiesplit.x-=5;
            			}
            			if (posennemie.x>200 && posennemie.x<9300)
            			{
            				camera2.x-=5;
            			}
            		}
            		//dying
            		if(keystates[SDLK_u]&&enemattack==0)
            		{
            		        heroactu=hurt;
            			for (int j=0; j<43; j++)
            			{
            				SDL_BlitSurface(background2,NULL, background, &posbackg1);
        				SDL_BlitSurface(background, &camera3, ecran, NULL);
					SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
       		                        SDL_BlitSurface(heroactu, &frame2[j/6], ecran, &posherosplit);	
   	    	                        SDL_Flip(ecran);
            			}
            			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            			SDL_BlitSurface(heroactu, &frame2[7], ecran, &posherosplit);
 				SDL_Flip(ecran);
				SDL_Delay(2000);
			}
            		if(keystates[SDLK_RIGHT]&&enemattack==0)
            		{
            			e1=1;
            			animation3(&ennemie,ennemied,&x);
            			posennemie.x+=5;
            			if (split==0)
            			{
            				posennemiesplit.x+=5;
            			}
            			if (posennemie.x>230)
            			{
            				camera2.x+=5;
            			}
            			if (posennemie.x>9600)
            			{
            				posennemie.x-=5;
            			}
			}
            			
            			
            	if(keystates[SDLK_j]&&heroattack==0&&nbrspell==0)
		{
			posspell.y=poshero.y+30;
			        if(e==1)
		        	posspell.x=poshero.x+poshero.h/2;
		        	if(e==2)
		        	posspell.x=poshero.x-poshero.h/2;
			heroattack=1;
			i=0;	
		}
	        if(keystates[SDLK_p]&&enemattack==0&&nbrspell1==0)
		{
		        posspell1.y=posennemie.y+30;
		                if(e==1)
		        	posspell1.x=posennemie.x+posennemie.h/2;
		        	if(e==2)
		        	posspell1.x=posennemie.x-posennemie.h/2;
			enemattack=1;
			x=0;	
		}
		if(keystates[SDLK_k]&&heroattack==0)//jump
		{
			if(jump==0)
			{
				posans=poshero.y;
            			jump=1;
			}

		}
		if(keystates[SDLK_m]&&enemattack==0)//jump
		{
			if(jump1==0)
			{
				posansenemie=posennemie.y;
            			jump1=1;
			}

		}
		//annimation attack 
		if(heroattack==1)
		{
		        if(e==1)
		        animation(&heroactu,attackr,&i);
		        if(e==2)
		        animation(&heroactu,attackl,&i);
		        if(i==31)
		        {
		        if(e==1)
		        intspell=1;
		        if(e==2)
		        intspell=2;
		        heroattack=0;
		        }
		}
		if(enemattack==1)
		{
		        if(e1==1)
		        animation3(&ennemie,enemieattackr,&x);
		        if(e1==2)
		        animation3(&ennemie,enemieattackl,&x);
		        if(x==15)
		         {
		        if(e1==1)
		        intspell1=1;
		        if(e1==2)
		        intspell1=2;
		        enemattack=0;
		        }
		}
		//annimation jump
		if (jump==1)
		{
			poshero.y-=9;
			if (poshero.y<=posans-200)
			{
				jump=2;
			}
		}
		else if (jump==2)
		{
		       
			poshero.y+=9;
				if (poshero.y>=460)
				{
					jump=0;
				}
		}
		if (jump1==1)
		{
			posennemie.y-=9;
			if (posennemie.y<=posansenemie-200)
			{
				jump1=2;
			}
		}
		else if (jump1==2)
		{
			posennemie.y+=9;
				if (posennemie.y>=460)
				{
					jump1=0;
				}
		}
        	if (camera1.x>=9100)
        	{
        		camera1.x-=5;
        		if (split==1)
        		{
        			camera3.x-=5;	
        		}	
        	}
        	if (camera2.x>=9100)
        	{
        		camera2.x-=5;
        	}
        	if (camera1.x<=0)
        	{
        		camera1.x+=5;
        		if (split==1)
        		{
        			camera3.x+=5;
        		}	
        	}
        	if (camera2.x<=0)
        	{
        		camera2.x+=5;
        	}
        	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        	if (posennemie.x-poshero.x<=1300 || poshero.x-posennemie.x>=1300)
        	{
        		split=0;
        	}
        	else
        	{
        		split=1;
        	}

        	if (split==0)
        	{
        		SDL_BlitSurface(background2,NULL, background, &posbackg1);
        		if (kk==0)
        			{
        			Gif=gif[0];
        		while (y!=255 || k!=255)
        		{
        			if (y<=80)
        			{
        				posennemiesplit.x-=5;
        				animation3(&ennemie,ennemieg,&x);
        				animation(&heroactu,idler,&i);
        			}

        			SDL_SetAlpha (blackground, SDL_SRCALPHA, y);
        			SDL_BlitSurface(background, &camera3, ecran, NULL);
        			SDL_BlitSurface(blackground,NULL, ecran, &posbackg1);
				SDL_BlitSurface(heroactu, &framed[i/4], ecran, &posherosplit);
				SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
        			y+=2;
        			if (y>=255)
        			y=255;
        			if (y>=200)
        			{
        			
        			SDL_SetAlpha (Gif, SDL_SRCALPHA, k);
        			SDL_BlitSurface(Gif, NULL, ecran, &posgif);
        			k+=2;
        			if (k>=255)
        			k=255;	
        			}
        			
        			SDL_Flip(ecran);
        		}
        		y=0;
        		while (y<255)
        		{
        		
        			for (k=0; k<8; k++)
        			{
        				Gif=gif[k];
        				SDL_BlitSurface(blackground,NULL, ecran, &posbackg1);
        				SDL_SetAlpha (animwitch, SDL_SRCALPHA, y);
        				SDL_BlitSurface(Gif,NULL, ecran, &posgif);
        				SDL_SetColorKey(animwitch, SDL_SRCCOLORKEY, SDL_MapRGB(animwitch->format, 255, 255, 255));
        				SDL_BlitSurface(heroactu, &framed[i/4], ecran, &posherosplit);
					SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
					SDL_BlitSurface(animwitch, NULL, ecran, &poswitch);
					SDL_Flip(ecran);
        			}
        		y+=8;
        		if (y>=255)
        		y=255;
        		}
        		y=255;
        		k=255;
        		Gif=gif[0];
        		while (y!=0 && k!=0)
        		{
        			if (poswitch.y!=460)
        			{
        				poswitch.y+=2;	
        			}
        			
        			k-=2;
				if (y<=0)
				y=0;
				if (k==1)
				{
					while (y!=1)
					{
						SDL_SetAlpha (blackground, SDL_SRCALPHA, y);
        					y-=2;
        					SDL_BlitSurface(background,&camera3, ecran, &posbackg1);
        					SDL_BlitSurface(blackground,NULL, ecran, &posbackg1);
        					SDL_BlitSurface(heroactu, &framed[i/4], ecran, &posherosplit);
						SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
						SDL_BlitSurface(witch, &framed[0], ecran, &poswitch);
						SDL_Flip(ecran);
					}
					k=0;
				
				}

        			SDL_SetAlpha (Gif, SDL_SRCALPHA, k);
        			SDL_BlitSurface(background,NULL, ecran, &posbackg1);
        			SDL_BlitSurface(blackground,NULL, ecran, &posbackg1);
				if (k>0)
				{
					 SDL_BlitSurface(Gif, NULL, ecran, &posgif);
				}
        			SDL_BlitSurface(heroactu, &framed[i/4], ecran, &posherosplit);
				SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
				SDL_BlitSurface(witch, &framed[0], ecran, &poswitch);
				SDL_Flip(ecran);
        		}
        	}

        		kk=1;
        		if (posherosplit.x>=camera3.w-posherosplit.w)
        		{
        			posherosplit.x-=5;
        		}
        		if (posennemiesplit.x>=camera3.w-posennemiesplit.w)
        		{
        			posennemiesplit.x-=5;
        		}
        		SDL_BlitSurface(background2,NULL, background, &posbackg1);
        		SDL_BlitSurface(background, &camera3, ecran, NULL);
			SDL_BlitSurface(heroactu, &framed[i/4], ecran, &posherosplit);
			SDL_BlitSurface(ennemie, &framed[x/2], ecran, &posennemiesplit);
			SDL_BlitSurface(witch, &framed[j/4], ecran, &poswitch);
        	}
        	else
        	{
        		SDL_BlitSurface(background, &camera1, ecran, &posbackg1);    	
        		SDL_BlitSurface(background, &camera2, ecran, &posbackg2);
			SDL_BlitSurface(background2,NULL, background, &posbackg2);
        		SDL_BlitSurface(background2,NULL, background, &posbackg1);
        		//animation spell hero
        		        if (intspell==1)
		                {
		                SDL_BlitSurface(spell,NULL, background, &posspell);
		                posspell.x+=25;
		                nbrspell++;
		                }
		                if (intspell==2)
		                {
                                 SDL_BlitSurface(spell,NULL, background, &posspell);
		                posspell.x-=25;
		                nbrspell++;
		                }
		                if(nbrspell==28)
		                {
		                posspell.y=2000;
		                intspell=0;
		                nbrspell=0;
		                }
		       //animation spell enemie         
		                if (intspell1==1)
		                {
		                SDL_BlitSurface(spellen,NULL, background, &posspell1);
		                posspell1.x+=25;
		                nbrspell1++;
		                }
		                if (intspell1==2)
		                {
                                 SDL_BlitSurface(spellen,NULL, background, &posspell1);
		                posspell1.x-=25;
		                nbrspell1++;
		                }
		                if(nbrspell1==28)
		                {
		                posspell1.y=2000;
		                intspell1=0;
		                nbrspell1=0;
		                }
        		
			SDL_BlitSurface(heroactu, &framed[i/4], background, &poshero);
			SDL_BlitSurface(ennemie, &framed[x/2], background, &posennemie);
        		SDL_BlitSurface(bande, NULL, ecran, &posbande);
        	}

        	SDL_Flip(ecran);
        }
}
