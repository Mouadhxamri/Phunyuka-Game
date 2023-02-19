#include "stage1.h"
#include "option.h"
#include "sound.h"
#include "fonction.h"
#include "enigme.h"
#define TEMPS 30
#define speed  6

void Blit(SDL_Surface* source,SDL_Surface* dest,int x,int y)
{
    SDL_Rect R;
    R.x = x;
    R.y = y;
    SDL_BlitSurface(source,NULL,dest,&R);
}
//stage0
void stage0(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell)
{
    /*
    	SDL_Surface *background=NULL,*herod=NULL,*herog=NULL,*heroactu=NULL,*blaka=NULL, *attackr=NULL,*attackl=NULL,*magicien=NULL,*idler=NULL,*idlel=NULL,*bulle=NULL,*baguette=NULL,*troll=NULL,*spell=NULL;
    	SDL_Rect posback,poshero,posmagicien,framed[8],posbulle,bullanim[8],posbaguette,postroll,posspell,posblaka;
    	int boucle=1,i=0,a=0,p=0,posans=460,k=-1,y=0,x=0,j=0,e=2,intspell=0,nbrspell=0,animmage=0;
    	SDL_Event event;
     	Uint8 *keystates = SDL_GetKeyState( NULL );
     	postroll.x=35;
     	postroll.y=460;
     	posblaka.x=1000;
     	posblaka.y=410;

     	posbaguette.x=160;
     	posbaguette.y=550;
    	poshero.x=1150;
    	poshero.y=460;
    	posback.x=0;
    	posback.y=0;
    	posbulle.x=150;
    	posbulle.y=360;
    	posmagicien.x=0;
    	posmagicien.y=460;
    	blaka=IMG_Load("image/decoration/blaka.png");
    	spell=IMG_Load("image/decoration/spell.png");
    	baguette=IMG_Load("image/magicien/baguette.png");
    	idler=IMG_Load ("image/perso/idlers.png");
    	idlel=IMG_Load ("image/perso/idlels.png");
    	troll=IMG_Load ("image/magicien/troll.png");
    	background=IMG_Load ("image/stage/maison.png");
    	bulle=IMG_Load ("image/magicien/bulle.png");
    	herod=IMG_Load ("image/perso/wr.png");
    	herog=IMG_Load ("image/perso/wl.png");
    	attackr=IMG_Load ("image/perso/ar.png");
    	attackl=IMG_Load ("image/perso/al.png");
    	magicien=IMG_Load ("image/magicien/mp.png");
    	SDL_BlitSurface(background, NULL, ecran, &posback);

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
    			y=y+153;
    			j=0;
    		}
    		bullanim[ i ].x=x;
    		bullanim[ i ].y=y;
        		bullanim[ i ].w =232;
        		bullanim[ i ].h = 153;
        		x=x+232;
        		j++;
    	}
        	heroactu=idlel;
            SDL_BlitSurface(magicien, &framed[0], ecran, &posmagicien);
    	SDL_BlitSurface(heroactu, &framed[0], ecran, &poshero);
    	i=0;
    	for (j=0 ; j<600; j++)
    	{
    	        animation(&heroactu,idlel,&i);
    	        SDL_BlitSurface(background, NULL, ecran, &posback);
    	        SDL_BlitSurface(magicien, &framed[i/4], ecran, &posmagicien);
    		SDL_BlitSurface(bulle, &bullanim[j/150], ecran, &posbulle);
    		SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
    		SDL_Flip(ecran);

    	}
    	SDL_Flip(ecran);
    while ((boucle)&&((*continuer)))
        	{
            	while (SDL_PollEvent(&event))
           		switch(event.type)
            	{
           			case SDL_QUIT:
                		(*continuer) = 0;
                		break;
                		case SDL_VIDEORESIZE:
    				ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
        				break;
                		case SDL_KEYDOWN:
                		switch (event.key.keysym.sym)
                		{
                			break;
    				case SDLK_TAB:
    				option(ecran,effet,effet2,musique,mute,continuer,posvolb);
    				break;

                		}

                		break;
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
                			if (a==0)
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
    		if(keystates[SDLK_j]&&intspell==0)
    		{
    			if(p==1&&poshero.y>=460)
    			{
    				posspell.y=poshero.y+30;
    		        	posspell.x=poshero.x+poshero.h/2;
    		        	if(e==1)
    		        	{
    		        		intspell=1;
    		        		heroactu=attackr;
    		        		Mix_PlayChannel( -1, sonspell, 0 ) ;
    		               	 	while (k<28)
    		                	{
    		               			k++;
    		                		SDL_BlitSurface(background, NULL, ecran, &posback);
    		                		SDL_BlitSurface(blaka,NULL,ecran,&posblaka);
           	 	                		SDL_BlitSurface(heroactu, &framed[k/4], ecran, &poshero);
           	 					SDL_BlitSurface(magicien, &framed[k/4], ecran, &posmagicien);
           	 	                		SDL_Flip(ecran);
    		                	}
    		                	heroactu=herod;
    		        }
    		       	 	if(e==2)
    		        	{
    					posspell.y=poshero.y+30;
    		        		posspell.x=poshero.x-poshero.h/2;

    		        		intspell=2;
    		                	heroactu=attackl;
    		                	Mix_PlayChannel( -1, sonspell, 0 ) ;
    		        	 	while (k<28)
    		                	{
    		                		k++;
    		                		SDL_BlitSurface(background, NULL, ecran, &posback);
    		                		SDL_BlitSurface(blaka,NULL,ecran,&posblaka);
           	 	                		SDL_BlitSurface(heroactu, &framed[k/4], ecran, &poshero);
           	 					SDL_BlitSurface(magicien, &framed[k/4], ecran, &posmagicien);
           	 	                		SDL_Flip(ecran);
    		               	 	}
    		               	 	heroactu=herog;
    		        	}
    			}
    		}
    		k=-1;
    			animmage++;
            		if (animmage==32)
            		{
                		animmage=0;
            		}
    		if (a==1)
    		{
    			poshero.y-=9;
    			if (poshero.y<=posans-160)
    			{
    				a=2;
    			}
    		}
    		else if (a==2)
    		{
    			poshero.y+=9;
    			if (poshero.y>=posans)
    			{
    				a=0;
    			}
    		}

    		if(poshero.x<400 && p==0)
    		{
    			poshero.y=460;
    			for (j=100; j<350; j+=5)
    			{
    				posbaguette.x=j;
    				SDL_BlitSurface(background, NULL, ecran, &posback);
    				animation(&heroactu,idlel,&i);
           	 	                SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
           	 			SDL_BlitSurface(magicien, &framed[i/4], ecran, &posmagicien);
           	 			SDL_BlitSurface(baguette,NULL,ecran,&posbaguette);
           	 	                SDL_Flip(ecran);
    			}
    			herod=IMG_Load ("image/perso/wr1.png");
    	                herog=IMG_Load ("image/perso/wl1.png");
    	                idler=IMG_Load ("image/perso/idler.png");
    	                idlel=IMG_Load ("image/perso/idlel.png");
    	                heroactu=idlel;
    	                SDL_BlitSurface(background, NULL, ecran, &posback);
           	 	        SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
           	 		SDL_BlitSurface(magicien, &framed[i/4], ecran, &posmagicien);
           	 	        SDL_Flip(ecran);
    			for (j=4 ; j<7; j++)
    			{
    				SDL_BlitSurface(bulle, &bullanim[j], ecran, &posbulle);
    				SDL_Flip(ecran);
    				SDL_Delay(4000);
    			}
    	                p=1;
    		}


    		if(poshero.x<1100 && poshero.x>1000 && p==1)
    		{
    			boucle=0;
    		}

    		if(poshero.x+poshero.w>=ecran->w-poshero.w/2)
    		{
    			poshero.x-=speed;
    		}

    		if(collision(posspell,posmagicien)==1)
    		{
    			SDL_BlitSurface(troll, NULL, ecran, &postroll);
    			SDL_Flip(ecran);
    			SDL_Delay(500);
    			posspell.x=poshero.x;
    		}

            	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
           	 	SDL_BlitSurface(background, NULL, ecran, &posback);
           	 	if (intspell==1)
    		{
    		SDL_BlitSurface(spell,NULL, ecran, &posspell);
    		posspell.x+=25;
    		nbrspell++;
    		}
    		if (intspell==2)
    		{
                    SDL_BlitSurface(spell,NULL, ecran, &posspell);
    		posspell.x-=25;
    		nbrspell++;
    		}
    		if(nbrspell==28||(collision(posspell,posmagicien)==1))
    		{
    		intspell=0;
    		nbrspell=0;
    		}
    		if(p==1)
    		SDL_BlitSurface(blaka,NULL,ecran,&posblaka);
           	 	SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
           	 	SDL_BlitSurface(magicien, &framed[animmage/4], ecran, &posmagicien);
       	    	SDL_Flip(ecran);
        	}
        	/*SDL_FreeSurface(herod);
        	SDL_FreeSurface(herog);
        	SDL_FreeSurface(heroactu);
        	SDL_FreeSurface(police);
        	SDL_FreeSurface(attackr);
        	SDL_FreeSurface(attackl);
        	SDL_FreeSurface(magicien);
        	SDL_FreeSurface(idle);
        	SDL_FreeSurface(background);*/
}

int arduinoWriteData(int x);
int arduinoReadData(int *x);
//stage1
void stage1(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit,int *victory,int *choix)
{

    SDL_Surface *health=NULL,*pause=NULL,*confirm=NULL,*cancel=NULL,*scoreS=NULL,*magicienpetit=NULL,*portal=NULL,*Rotation=NULL,*Rotation2=NULL,*Rotation3=NULL,*Rotation4=NULL,*surfacetestroto=NULL,*paragstage1=NULL,*magicien=NULL,*noir=NULL,*gameover=NULL,*attackr=NULL,*attackl=NULL,*hurt=NULL,*rock1=NULL,*rock2=NULL,*spell=NULL,*spellen=NULL,*vie=NULL, *trap1=NULL,*background=NULL,*herod=NULL,*herog=NULL,*heroactu=NULL,*hpup=NULL,*police=NULL,*enemie=NULL,*enemied=NULL,*enemieg=NULL,*enemie1=NULL,*enemied1=NULL,*enemieg1=NULL,*enematack=NULL,*enem1atack=NULL,*score=NULL,*scoreint=NULL,
                 *idlel=NULL,*petithero=NULL,*petitmagicien=NULL,*petithero2=NULL,*petitherog=NULL,*idler=NULL,*barre=NULL,*terre1=NULL,*terre2=NULL,*terre3=NULL,*jumpr=NULL,*jumpl=NULL,*surfacesecondes=NULL,*surfaceminutes=NULL
                                        ,*imgtime=NULL,*enigmestage1=NULL;
    SDL_Rect posback,poshero,pospause,posconfirm,poscancel,pospetithero,posmagicien,posbarre,posmagicienactu,posspell,posspellen,framed[8],frame2[8],frame3[8],pospolice,posportal,posgo,pose1,posscoreS,pose2,pose3,pose4,pose5,pose6,pose7,posenemie1,posenemie2,posenemie3,posenemie4,posenemie5,posenemie6,posenemie7,poshp,posrock1,posvie,posscore,poshpup,posminutes,possecondes,posnoir,
             posscoreint,posmagicienpetit,postrap1,posterre1,posterre2,posterre3,posterre4,posterre5,posterre6,posterre7,posterre8,posterre9,postime,posenigme1,posparagstage1;
    int boucle=1,i=0,jump=0,d1=6,e1=1,compteur1=0,hp=4,k=-1,posans,nbrspell=0,intspell=0,cmpsc=0,posactu=460,compteurmage=0;
    int CAR1=0,CAR2=0,CAR3=0,CAR4=0,CAR5=0,CAR6=0,CAR7=0,CAR8=0,CAR9=0,CAR10=0;
    int tempsPrecedent = 0, tempsActuel = 0,tsec=59,tmin=2;
    int y=0,enatack=0,spellenemie=0,nbrspellen=0;
    int x=0,bouclepause=1;
    int j=0,w=0;
    int camera=0;
    int directionhero=1;
    int coll=0,sens=1;
    int enig=0;
    int souri,mouvemmentsouri=0,scorefinal=0,rotozoom=0;
    int arduinoserial=0;
    int xdeb,xfinal,xresult;
    double angle=0, zoom=1,test=0;
    int stage=0;
    float minimap=0;
    SDL_Event event;
    SDL_Rect posdte;

    char str[128];
    SDL_Surface *vit;
    Uint32 dte,t_prev;
    Uint8 *keystates = SDL_GetKeyState( NULL );
    TTF_Font *fonts = NULL;
    SDL_TimerID timer;
    fonts = TTF_OpenFont("fonts/Takota.ttf", 60);
    SDL_Color couleur = {235,144,234};
    SDL_Color couleur1 = {145,0,0};
    SDL_Color couleurblanc = {255,255,255};
    char scr[12];
    char chhp[2];
    char secondes[2];
    char minutes[2];
    Mix_Music *stage1;
    paragstage1=IMG_Load("image/histoire/stage1.png");
    noir=IMG_Load("image/histoire/black.png");
    stage1 = Mix_LoadMUS("music/stage1.mp3");
    Mix_PlayMusic(stage1, -1);
    /*for (i=0; i<400;i++)
    	{
    		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    		SDL_BlitSurface(paragstage1, NULL, ecran, &posparagstage1);
    		SDL_Flip(ecran);
    		posparagstage1.y-=2;
    	}
    	SDL_Delay(3000);*/
//charger(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1,&pose2,&pose3,&pose4,&pose5,&pose6,&pose7,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,continuer,&stage,tsec,tmin,hp,cmpsc);
    /*FILE* fichier = NULL;
    fichier = fopen("xsauvegarde.txt", "r");
    fscanf(fichier,"%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %hd %hd %hd %hd %hd %hd %hd %d %d %d %d",&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x
    ,&camera,&pose1.y,&pose2.y,&pose3.y,&pose4.y,&pose5.y,&pose6.y,&pose7.y,&tsec,&tmin,&hp,&cmpsc);
    fclose(fichier);*/
    posdte.x=100;
    posdte.y=100;
    posnoir.x=0;
    posnoir.y=0;

    posgo.x=ecran->w/2-150;
    posgo.y=ecran->h/2;

    poshp.x=30;
    poshp.y=30;

    posvie.x=125;
    posvie.y=25;

    posscore.x=190;
    posscore.y=30;
    postime.x=350;
    postime.y=30;

    posminutes.x=450;
    posminutes.y=25;
    possecondes.x=500;
    possecondes.y=25;

    posportal.x=0;
    posportal.y=0;

    posmagicien.x=7500;
    posmagicien.y=460;
    posmagicienactu.x=7500;
    posmagicienactu.y=460;

    posmagicienpetit.x=1250;
    posmagicienpetit.y=10;

    pospetithero.x=800;
    pospetithero.y=10;

    posbarre.x=800;
    posbarre.y=60;
    posenigme1.x=7250;
    posenigme1.y=400;

    poshpup.x=2360;
    poshpup.y=200;

    posscoreint.x=270;
    posscoreint.y=25;

    posrock1.x=500;
    posrock1.y=650;
    posrock1.h=30;
    posrock1.w=81;


    posterre1.x=1300;
    posterre1.y=600;
    posterre1.w=201;
    posterre1.h=76;

    posterre2.x=1800;
    posterre2.y=550;
    posterre2.w=201;
    posterre2.h=76;

    posterre3.x=2300;
    posterre3.y=550;
    posterre3.w=201;
    posterre3.h=76;

    posterre4.x=3300;
    posterre4.y=600;
    posterre4.w=201;
    posterre4.h=76;

    posterre5.x=3800;
    posterre5.y=550;
    posterre5.w=201;
    posterre5.h=76;

    posterre6.x=4300;
    posterre6.y=550;
    posterre6.w=201;
    posterre6.h=76;

    posterre7.x=5300;
    posterre7.y=600;
    posterre7.w=201;
    posterre7.h=76;

    posterre8.x=5800;
    posterre8.y=550;
    posterre8.w=201;
    posterre8.h=76;

    posterre9.x=6300;
    posterre9.y=550;
    posterre9.w=201;
    posterre9.h=76;

    postrap1.x=2800;
    postrap1.y=650;
    postrap1.h=91;
    postrap1.w=53;

    posenemie1.x=1000;
    posenemie1.y=460;
    pose1.x=1000;
    pose1.y=460;


    posenemie2.x=2000;
    posenemie2.y=460;
    pose2.x=2000;
    pose2.y=460;

    posenemie3.x=3000;
    posenemie3.y=460;
    pose3.x=3000;
    pose3.y=460;

    posenemie4.x=4000;
    posenemie4.y=460;
    pose4.x=4000;
    pose4.y=460;


    posenemie5.x=5000;
    posenemie5.y=460;
    pose5.x=5000;
    pose5.y=460;

    posenemie6.x=6000;
    posenemie6.y=460;
    pose6.x=6000;
    pose6.y=460;

    posenemie7.x=7000;
    posenemie7.y=460;
    pose7.x=7000;
    pose7.y=460;


    poshero.x=0;
    poshero.y=460;


    posback.x=0;
    posback.y=0;

    SDL_Init(SDL_INIT_TIMER);
    //charger(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1,&pose2,&pose3,&pose4,&pose5,&pose6,&pose7,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,continuer,&stage,&tsec,&tmin,&hp,&cmpsc);

    pause=IMG_Load("image/stage/pause.png");
    confirm=IMG_Load("image/stage/confifm.png");
    cancel=IMG_Load("image/stage/cancel.png");
    petithero=IMG_Load("image/perso/petit.png");
    petitherog=IMG_Load("image/perso/petitg.png");
    magicienpetit=IMG_Load("image/magicien/magicienpetit.png");
    jumpr=IMG_Load ("image/perso/jumpr.png");
    jumpl=IMG_Load ("image/perso/jumpl.png");
    terre1=IMG_Load ("image/decoration/terre1.png");
    terre2=IMG_Load ("image/decoration/terre2.png");
    terre3=IMG_Load ("image/decoration/terre3.png");
    trap1=IMG_Load ("image/decoration/trap1.png");
    score=IMG_Load ("image/decoration/score.png");
    barre=IMG_Load ("image/decoration/barre.png");
    health=IMG_Load("image/health/heart.png");
    hpup=IMG_Load("image/health/hpup.png");
    enigmestage1=IMG_Load ("image/enigme/enigme.png");
    vie= TTF_RenderText_Blended(fonts, "4", couleur);
    imgtime=IMG_Load ("image/decoration/time.png");
    spell=IMG_Load ("image/decoration/spell.png");
    spellen=IMG_Load ("image/decoration/spellenemie.png");
    rock1=IMG_Load ("image/decoration/rock1.png");
    hurt=IMG_Load ("image/perso/hert.png");
    idler=IMG_Load ("image/perso/idler.png");
    idlel=IMG_Load ("image/perso/idlel.png");
    attackr=IMG_Load ("image/perso/ar.png");
    attackl=IMG_Load ("image/perso/al.png");
    enemied=IMG_Load ("image/enemies/en1wr.png");
    enemieg=IMG_Load ("image/enemies/en1wl.png");
    enemied1=IMG_Load ("image/enemies/en2wr.png");
    enemieg1=IMG_Load ("image/enemies/en2wl.png");
    enematack=IMG_Load ("image/enemies/en1al.png");
    enem1atack=IMG_Load ("image/enemies/en2al.png");
    police=IMG_Load ("image/test.png");
    background=IMG_Load ("image/stage/map1.png");
    herod=IMG_Load ("image/perso/wr1.png");
    herog=IMG_Load ("image/perso/wl1.png");
    magicien=IMG_Load("image/magicien/mp2.png");
    //portal=SDL_LoadBMP ("image/decoration/tabscore.bmp");
    SDL_BlitSurface(background, NULL, ecran, &posback);
    SDL_BlitSurface(health, NULL, ecran, &poshp);
    SDL_BlitSurface(vie, NULL, ecran, &posvie);
    SDL_BlitSurface(score, NULL, ecran, &posscore);
    SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
    SDL_BlitSurface(imgtime, NULL, ecran, &postime);
    SDL_BlitSurface(trap1, NULL, ecran, &postrap1);

    for (i=0; i<8; i++)
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
    i=0;
    x=0;
    y=0;
    j=0;
    for (i=0; i<8; i++)
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
    for (i=0; i<8; i++)
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
    heroactu=herod;
    SDL_BlitSurface(herod, &framed[i], ecran, &poshero);
    SDL_Flip(ecran);
    while ((boucle)&&((*continuer)))
    {
        t_prev=SDL_GetTicks();
        sprintf(secondes, "%d",tsec);
        surfacesecondes= TTF_RenderUTF8_Solid(fonts, secondes, couleur);
        sprintf(minutes, "%d",tmin);
        strcat(minutes,":");
        surfaceminutes=  TTF_RenderUTF8_Solid(fonts, minutes, couleur);
        sprintf(chhp, "%d",hp);
        vie= TTF_RenderText_Blended(fonts,chhp, couleur);
        sprintf(scr,"%d",cmpsc);
        scoreint=TTF_RenderText_Blended(fonts,scr, couleur);
        while (SDL_PollEvent(&event))
            xdeb=poshero.x;

        switch(event.type)
        {
        case SDL_QUIT:
            (*continuer) = 0;
            break;
        case SDL_VIDEORESIZE:
            ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_TAB:
                option(ecran,effet,effet2,musique,mute,continuer,posvolb,choix);
                break;

                //case SDLK_t:
                //keysHeld[event.key.keysym.sym]=1;
                break;
            case SDLK_n:
                roto_zoom(&ecran,&heroactu,&surfacetestroto,&poshero);
                //roto_zoom();
                break;

            case SDLK_ESCAPE:
                Pause1(ecran,&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&posenemie1,&posenemie2,&posenemie3,&posenemie4,&posenemie5,&posenemie6,&posenemie7,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,continuer,tsec,tmin,hp,cmpsc);
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            //souri
            //t_prev=SDL_GetTicks(); //dt a t=0s
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                souri=event.button.x;
                posactu=poshero.x;
                mouvemmentsouri=1;
            }
            break;
        }
        //clavier
        if(keystates == SDL_GetKeyState(NULL))
        {
            if(directionhero==1)
                animation(&heroactu,idler,&i);
            if(directionhero==2)
                animation(&heroactu,idlel,&i);
        }
        pospetithero.x=((-posback.x*500) / 7500) + 800;
        animation(&petithero2,petithero,&w);
        //animation(&magicienpetit,idlel,&w);
        if(keystates[SDLK_b])
        {
            boucle=0;
        }

        if(keystates[SDLK_k])//jump
        {
            if(jump==0||CAR1==1||CAR2==1||CAR3==1||CAR4==1||CAR5==1||CAR6==1||CAR7==1||CAR8==1||CAR9==1||CAR10==1)
            {
                if(directionhero==1)
                    heroactu=jumpr;
                if(directionhero==2)
                    heroactu=jumpl;
                posans=poshero.y;
                jump=1;
            }

        }
        if(keystates[SDLK_d])//right
        {
            directionhero=1;
            animation(&heroactu,herod,&i);
            if (coll==0)
            {
                scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
            }
            else
            {
                poshero.x+=speed;
            }

        }
        if(keystates[SDLK_q])//left
        {
            directionhero=2;
            animation(&heroactu,herog,&i);
            if (coll==0)
            {
                scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
            }
            else
            {
                poshero.x-=speed;
            }

        }
        if(keystates[SDLK_a] && keystates[SDLK_d])
        {
         directionhero=1;
                        animation(&heroactu,herod,&i);
                        if (coll==0)
                        {
                        scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
                        }
                        else
                        {
                            poshero.x+=(speed+5);
                        }


        } 
if(keystates[SDLK_a] && keystates[SDLK_q])//left
        {
                        directionhero=2;                    
                        animation(&heroactu,herog,&i);
                        if (coll==0)
                        {
                        scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
                        }
                        else
                        {
                            poshero.x-=(speed+5);
                        }
        
        }
/*if(keystates[SDLK_r] && keystates[SDLK_d])
        {
         directionhero=1;
                        animation(&heroactu,herod,&i);
                        if (coll==0)
                        {
                        scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
                        }
                        else
                        {
                            poshero.x+=1;
                            
                        }


        } */
        /*if(keystates[SDLK_r] && keystates[SDLK_q])
        {
         directionhero=2;
                        animation(&heroactu,herod,&i);
                        if (coll==0)
                        {
                        scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
                        }
                        else
                        {
                            poshero.x-=3;
                        }


        } */

        if(keystates[SDLK_j]&&intspell==0&&(jump==0||CAR1==1||CAR2==1||CAR3==1||CAR4==1||CAR5==1||CAR6==1||CAR7==1||CAR8==1||CAR9==1||CAR10==1))//attack
        {
            if(directionhero==1)
            {
                posspell.x=poshero.x+poshero.h/2;
                posspell.y=poshero.y+30;
                intspell=1;
                heroactu=attackr;
                Mix_PlayChannel( -1, sonspell, 0 ) ;
                while (k<28)
                {
                    positionenemie(&compteur1,&d1);
                    posenemie1.x=pose1.x+compteur1*speed;
                    posenemie2.x=pose2.x+compteur1*speed;
                    posenemie3.x=pose3.x+compteur1*speed;
                    posenemie4.x=pose4.x+compteur1*speed;
                    posenemie5.x=pose5.x+compteur1*speed;
                    posenemie6.x=pose6.x+compteur1*speed;
                    posenemie7.x=pose7.x+compteur1*speed;
                    if(d1==1)
                    {
                        animation(&enemie,enemied,&e1);
                        animation(&enemie1,enemied1,&e1);
                    }
                    if(d1==2)
                    {
                        animation(&enemie,enemieg,&e1);
                        animation(&enemie1,enemieg1,&e1);
                    }
                    k++;
                    Blit(background,ecran,posback.x,posback.y);
                    Blit(rock1,ecran,posrock1.x,posrock1.y);
                    Blit(hpup,ecran,poshpup.x,poshpup.y);
                    Blit(terre1,ecran,posterre1.x,posterre1.y);
                    Blit(terre1,ecran,posterre2.x,posterre2.y);
                    Blit(terre1,ecran,posterre3.x,posterre3.y);
                    Blit(terre2,ecran,posterre4.x,posterre4.y);
                    Blit(terre2,ecran,posterre5.x,posterre5.y);
                    Blit(terre2,ecran,posterre6.x,posterre6.y);
                    Blit(terre3,ecran,posterre7.x,posterre7.y);
                    Blit(terre3,ecran,posterre8.x,posterre8.y);
                    Blit(terre3,ecran,posterre9.x,posterre9.y);
                    Blit(trap1,ecran,postrap1.x,postrap1.y);
                    SDL_BlitSurface(health, NULL, ecran, &poshp);
                    SDL_BlitSurface(score, NULL, ecran, &posscore);
                    SDL_BlitSurface(vie, NULL, ecran, &posvie);
                    SDL_BlitSurface(imgtime, NULL, ecran, &postime);
                    SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
                    SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
                    SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie1);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie2);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie3);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie4);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie5);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie6);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie7);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie3);
         //           SDL_BlitSurface(magicien, &framed[k/4], ecran, &posmagicienactu);
                    SDL_BlitSurface(heroactu, &framed[k/4], ecran, &poshero);
                    SDL_BlitSurface(spellen,NULL, ecran, &posspellen);

                    SDL_BlitSurface(barre, NULL, ecran, &posbarre);
                    SDL_BlitSurface(petithero2, &frame3[w/4], ecran, &pospetithero);
                    SDL_BlitSurface(magicienpetit, &frame3[w/4], ecran, &posmagicienpetit);
                    if (spellenemie==1)
                    {
                        posspellen.x-=5;
                        nbrspellen++;
                        SDL_BlitSurface(spellen,NULL, ecran, &posspellen);
                    }
                    SDL_Flip(ecran);
                }
            }
            if(directionhero==2)
            {
                intspell=2;
                heroactu=attackl;
                Mix_PlayChannel( -1, sonspell, 0 ) ;
                posspell.x=poshero.x-poshero.h/2;
                posspell.y=poshero.y+30;
                while (k<28)
                {
                    k++;
                    positionenemie(&compteur1,&d1);
                    posenemie1.x=pose1.x+compteur1*speed;
                    posenemie2.x=pose2.x+compteur1*speed;
                    posenemie3.x=pose3.x+compteur1*speed;
                    posenemie4.x=pose4.x+compteur1*speed;
                    posenemie5.x=pose5.x+compteur1*speed;
                    posenemie6.x=pose6.x+compteur1*speed;
                    posenemie7.x=pose7.x+compteur1*speed;
                    if(d1==1)
                    {
                        animation(&enemie,enemied,&e1);
                        animation(&enemie1,enemied1,&e1);
                    }
                    if(d1==2)
                    {
                        animation(&enemie,enemieg,&e1);
                        animation(&enemie1,enemieg1,&e1);
                    }
                    Blit(background,ecran,posback.x,posback.y);
                    Blit(rock1,ecran,posrock1.x,posrock1.y);
                    Blit(hpup,ecran,poshpup.x,poshpup.y);
                    Blit(terre1,ecran,posterre1.x,posterre1.y);
                    Blit(terre1,ecran,posterre2.x,posterre2.y);
                    Blit(terre1,ecran,posterre3.x,posterre3.y);
                    Blit(terre2,ecran,posterre4.x,posterre4.y);
                    Blit(terre2,ecran,posterre5.x,posterre5.y);
                    Blit(terre2,ecran,posterre6.x,posterre6.y);
                    Blit(terre3,ecran,posterre7.x,posterre7.y);
                    Blit(terre3,ecran,posterre8.x,posterre8.y);
                    Blit(terre3,ecran,posterre9.x,posterre9.y);
                    Blit(trap1,ecran,postrap1.x,postrap1.y);
                    SDL_BlitSurface(health, NULL, ecran, &poshp);
                    SDL_BlitSurface(score, NULL, ecran, &posscore);
                    SDL_BlitSurface(vie, NULL, ecran, &posvie);
                    SDL_BlitSurface(imgtime, NULL, ecran, &postime);
                    SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
                    SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
                    SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie1);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie2);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie3);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie4);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie5);
                    SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie6);
                    SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie7);
            //        SDL_BlitSurface(magicien, &framed[k/4], ecran, &posmagicienactu);
                    SDL_BlitSurface(heroactu, &framed[k/4], ecran, &poshero);
                    SDL_BlitSurface(barre, NULL, ecran, &posbarre);
                    SDL_BlitSurface(petithero2, &frame3[w/4], ecran, &pospetithero);
                    SDL_BlitSurface(magicienpetit, &frame3[w/4], ecran, &posmagicienpetit);
                    if (spellenemie==1)
                    {
                        posspellen.x-=5;
                        nbrspellen++;
                        SDL_BlitSurface(spellen,NULL, ecran, &posspellen);
                    }
                    SDL_Flip(ecran);
                }
            }
        }


        //logique
        if (directionhero==2)
        {
            petithero2=petitherog;
        }
        else
        {
            petithero2=petithero;
        }
        //Mouvemment avec souris
        if(mouvemmentsouri==1)
        {
            if(abs(souri-posactu)<=6)
            {
                mouvemmentsouri=0;
            }

            else if(souri>posactu)
            {
                posactu+=speed;
                directionhero=1;
                animation(&heroactu,herod,&i);
                scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
            }
            else if(souri<posactu)
            {
                posactu-=speed;
                directionhero=2;
                animation(&heroactu,herog,&i);
                scrolling(&poshero.x,&posmagicien.x,&posenigme1.x,&poshpup.x,&posback.x,&pospolice.x,&pose1.x,&pose2.x,&pose3.x,&pose4.x,&pose5.x,&pose6.x,&pose7.x,&posrock1.x,&postrap1.x,&posterre3.x,&posterre1.x,&posterre2.x,&posterre4.x,&posterre5.x,&posterre6.x,&posterre7.x,&posterre8.x,&posterre9.x,&camera,&ecran,&heroactu,directionhero);
            }


        }

        //SDL_BlitSurface(vit,NULL,ecran,&posdte);

        //time
        if (!(tmin==0&&tsec==0))
        {
            tempsActuel = SDL_GetTicks();
            int dt=tempsActuel-tempsPrecedent;
            if(dt>=1000)
            {
                tsec--;
                tempsPrecedent=tempsActuel;
            }
            if(tsec==0 && tmin!=0)
            {
                tmin--;
                tsec=59;
            }
        }
        else
        {
            tmin=0;
            tsec=0;
        }

        k=-1;

        if (jump==1)
        {
            poshero.y-=9;
            if(directionhero==1)
                animation(&heroactu,jumpr,&i);
            if(directionhero==2)
                animation(&heroactu,jumpl,&i);
            if (poshero.y<=posans-200)
            {
                jump=2;
            }
        }
        else if (jump==2&&CAR1==0&&CAR2==0&&CAR3==0&&CAR4==0&&CAR5==0&&CAR6==0&&CAR7==0&&CAR8==0&&CAR9==0&&CAR10==0)
        {
            if(directionhero==1)
                animation(&heroactu,jumpr,&i);
            if(directionhero==2)
                animation(&heroactu,jumpl,&i);
            poshero.y+=9;
            if (poshero.y>=460)
            {
                jump=0;
            }
        }



        /*//animation des ennemies
        if(posenemie1.x-poshero.x<=550 && enatack==0 && posenemie1.y!=2000)
        {
                enemie=enematack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie1.x-posenemie1.h/2;
                posspellen.y=posenemie1.y+30;
        }
        else if(abs(poshero.x-posenemie2.x)<=550&&enatack==0&&posenemie2.y!=2000)
        {
                enemie=enematack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie2.x-posenemie2.h/2;
                posspellen.y=posenemie2.y+30;
        }
        else if(abs(poshero.x-posenemie3.x)<=550&&enatack==0&&posenemie3.y!=2000)
        {
                enemie1=enem1atack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie3.x-posenemie3.h/2;
                posspellen.y=posenemie3.y+30;
        }
        else if(abs(poshero.x-posenemie4.x)<=550&&enatack==0&&posenemie4.y!=2000)
        {
                enemie=enematack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie4.x-posenemie1.h/2;
                posspellen.y=posenemie4.y+30;
        }
        else if(abs(poshero.x-posenemie5.x)<=550&&enatack==0&&posenemie5.y!=2000)
        {
                enemie1=enem1atack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie5.x-posenemie5.h/2;
                posspellen.y=posenemie5.y+30;
        }
        else if(abs(poshero.x-posenemie6.x)<=550&&enatack==0&&posenemie6.y!=2000)
        {
                enemie=enematack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie6.x-posenemie6.h/2;
                posspellen.y=posenemie6.y+30;
        }
        else if(abs(poshero.x-posenemie7.x)<=550&&enatack==0&&posenemie7.y!=2000)
        {
                enemie1=enem1atack;
                enatack=1;
                e1=0;
                posspellen.x=posenemie7.x-posenemie7.h/2;
                posspellen.y=posenemie7.y+30;
        }
        else if(enatack==1)
        {
        if(e1<33)
        e1++;
                if(e1==32)
                {
                e1=0;
                enatack=0;
                spellenemie=1;
                }
        }*/

        positionenemie(&compteur1,&d1);
        if(d1==1)
        {
            animation(&enemie,enemied,&e1);
            animation(&enemie1,enemied1,&e1);
        }
        if(d1==2)
        {
            animation(&enemie,enemieg,&e1);
            animation(&enemie1,enemieg1,&e1);
        }



        posenemie1.x=pose1.x+compteur1*speed;
        posenemie2.x=pose2.x+compteur1*speed;
        posenemie3.x=pose3.x+compteur1*speed;
        posenemie4.x=pose4.x+compteur1*speed;
        posenemie5.x=pose5.x+compteur1*speed;
        posenemie6.x=pose6.x+compteur1*speed;
        posenemie7.x=pose7.x+compteur1*speed;


        //annimation magicien
        posmagicienactu.x=posmagicien.x;
        compteurmage++;
        if (compteurmage==24)
        {
            compteurmage=0;
        }
        //collision avec ennemies
        if ((collision(poshero,posenemie1)==1||collision(poshero,posenemie2)==1||collision(poshero,posenemie3)==1||collision(poshero,posenemie4)==1)||collision(poshero,posenemie5)==1 ||collision(poshero,posenemie6)==1||collision(poshero,posenemie7)==1)
        {
            arduinoserial=1;
            if(cmpsc!=0)
                cmpsc-=5;
            if(hp!=0)
                hp--;
            poshero.x-=100;
            camera-=100;
            mouvemmentsouri=0;
        }
        else
        {
            arduinoserial=1;
        }
        arduinoWriteData(arduinoserial);
        //collision avec rock1
        if (collision(poshero,posrock1)==1 && (directionhero==1) && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posrock1)==1 && (directionhero==2) && jump==0)
        {
            mouvemmentsouri=0;
            poshero.x+=speed;
            camera+=speed;
            coll=1;
        }
        if (collision(poshero,posrock1)==1 && jump==2)
        {
            CAR1=1;
        }
        if (collision(poshero,posrock1)==0)
        {
            CAR1=0;
        }

        if (collision(poshero,posrock1)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posrock1.y+6))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }

        //collision avec terre1
        if (collision(poshero,posterre1)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre1)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre1)==1 && jump==2)
        {
            CAR2=1;
            coll=0;
        }
        if (collision(poshero,posterre1)==0)
        {
            CAR2=0;
            coll=0;
        }
        if (collision(poshero,posterre1)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre1.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre2
        if (collision(poshero,posterre2)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre2)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre2)==1 && jump==2)
        {
            CAR3=1;
            coll=0;
        }
        if (collision(poshero,posterre2)==0)
        {
            CAR3=0;
            coll=0;
        }
        if (collision(poshero,posterre2)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre2.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre3
        if (collision(poshero,posterre3)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre3)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre3)==1 && jump==2)
        {
            CAR4=1;
            coll=0;
        }
        if (collision(poshero,posterre3)==0)
        {
            CAR4=0;
            coll=0;
        }
        if (collision(poshero,posterre3)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre3.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre4
        if (collision(poshero,posterre4)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre4)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre4)==1 && jump==2)
        {
            CAR5=1;
            coll=0;
        }
        if (collision(poshero,posterre4)==0)
        {
            CAR5=0;
            coll=0;
        }
        if (collision(poshero,posterre4)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre4.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre5
        if (collision(poshero,posterre5)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre5)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre5)==1 && jump==2)
        {
            CAR6=1;
            coll=0;
        }
        if (collision(poshero,posterre5)==0)
        {
            CAR6=0;
            coll=0;
        }
        if (collision(poshero,posterre5)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre5.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre6
        if (collision(poshero,posterre6)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre6)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre6)==1 && jump==2)
        {
            CAR7=1;
            coll=0;
        }
        if (collision(poshero,posterre6)==0)
        {
            CAR7=0;
            coll=0;
        }
        if (collision(poshero,posterre6)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre6.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre7
        if (collision(poshero,posterre7)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre7)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre7)==1 && jump==2)
        {
            CAR8=1;
            coll=0;
        }
        if (collision(poshero,posterre7)==0)
        {
            CAR8=0;
            coll=0;
        }
        if (collision(poshero,posterre7)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre7.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre8
        if (collision(poshero,posterre8)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre8)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre8)==1 && jump==2)
        {
            CAR9=1;
            coll=0;
        }
        if (collision(poshero,posterre8)==0)
        {
            CAR9=0;
            coll=0;
        }
        if (collision(poshero,posterre8)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre8.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec terre9
        if (collision(poshero,posterre9)==1 && directionhero==1 && jump==0)
        {
            poshero.x-=speed;
            camera-=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre9)==1 && directionhero==2 && jump==0)
        {
            poshero.x+=speed;
            camera+=speed;
            coll=1;
            mouvemmentsouri=0;
        }
        if (collision(poshero,posterre9)==1 && jump==2)
        {
            CAR10=1;
            coll=0;
        }
        if (collision(poshero,posterre9)==0)
        {
            CAR10=0;
            coll=0;
        }
        if (collision(poshero,posterre9)==1 && (jump==2||jump==1)&& (poshero.y+poshero.h>posterre9.y+speed))
        {
            if(directionhero==1)
            {
                poshero.x-=speed;
                camera-=speed;
            }
            if(directionhero==2)
            {
                poshero.x+=speed;
                camera+=speed;
            }
            if(poshero.y<460)
                poshero.y+=speed;
        }
        //collision avec trap1
        if(collision(poshero,postrap1)==1&&directionhero==1)
        {
            mouvemmentsouri=0;
            coll=1;
            poshero.x-=100;
            camera-=100;
            if(cmpsc>0)
                cmpsc-=5;
            if(hp!=0)
                hp--;
            Mix_PlayChannel( -1, dying, 0 ) ;
            heroactu=hurt;
            for (j=0; j<43; j++)
            {
                Blit(background,ecran,posback.x,posback.y);
                Blit(rock1,ecran,posrock1.x,posrock1.y);
                Blit(hpup,ecran,poshpup.x,poshpup.y);
                Blit(terre1,ecran,posterre1.x,posterre1.y);
                Blit(terre1,ecran,posterre2.x,posterre2.y);
                Blit(terre1,ecran,posterre3.x,posterre3.y);
                Blit(terre2,ecran,posterre4.x,posterre4.y);
                Blit(terre2,ecran,posterre5.x,posterre5.y);
                Blit(terre2,ecran,posterre6.x,posterre6.y);
                Blit(terre3,ecran,posterre7.x,posterre7.y);
                Blit(terre3,ecran,posterre8.x,posterre8.y);
                Blit(terre3,ecran,posterre9.x,posterre9.y);
                Blit(trap1,ecran,postrap1.x,postrap1.y);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie1);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie2);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie3);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie4);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie5);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie6);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie7);
                SDL_BlitSurface(heroactu, &frame2[j/10], ecran, &poshero);
                SDL_BlitSurface(vie, NULL, ecran, &posvie);
                SDL_BlitSurface(imgtime, NULL, ecran, &postime);
                SDL_BlitSurface(health, NULL, ecran, &poshp);
                SDL_BlitSurface(score, NULL, ecran, &posscore);
                SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
                SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
                SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);
                SDL_BlitSurface(barre, NULL, ecran, &posbarre);
                SDL_BlitSurface(petithero2, &frame3[w/4], ecran, &pospetithero);
                SDL_BlitSurface(magicienpetit, &frame3[w/4], ecran, &posmagicienpetit);
                SDL_Flip(ecran);
            }
        }
        if(collision(poshero,postrap1)==1&&directionhero==2)
        {
            mouvemmentsouri=0;
            coll=1;
            poshero.x+=100;
            camera+=100;
            if(cmpsc>0)
                cmpsc-=5;
            if(hp!=0)
                hp--;
            Mix_PlayChannel( -1, dying, 0 ) ;
            heroactu=hurt;
            for (j=0; j<43; j++)
            {
                Blit(background,ecran,posback.x,posback.y);
                Blit(rock1,ecran,posrock1.x,posrock1.y);
                Blit(hpup,ecran,poshpup.x,poshpup.y);
                Blit(terre1,ecran,posterre1.x,posterre1.y);
                Blit(terre1,ecran,posterre2.x,posterre2.y);
                Blit(terre1,ecran,posterre3.x,posterre3.y);
                Blit(terre2,ecran,posterre4.x,posterre4.y);
                Blit(terre2,ecran,posterre5.x,posterre5.y);
                Blit(terre2,ecran,posterre6.x,posterre6.y);
                Blit(terre3,ecran,posterre7.x,posterre7.y);
                Blit(terre3,ecran,posterre8.x,posterre8.y);
                Blit(terre3,ecran,posterre9.x,posterre9.y);
                Blit(trap1,ecran,postrap1.x,postrap1.y);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie1);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie2);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie3);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie4);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie5);
                SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie6);
                SDL_BlitSurface(enemie1, &framed[j/6], ecran, &posenemie7);
                SDL_BlitSurface(heroactu, &frame2[j/10], ecran, &poshero);
                SDL_BlitSurface(vie, NULL, ecran, &posvie);
                SDL_BlitSurface(imgtime, NULL, ecran, &postime);
                SDL_BlitSurface(health, NULL, ecran, &poshp);
                SDL_BlitSurface(score, NULL, ecran, &posscore);
                SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
                SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
                SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);
                SDL_BlitSurface(barre, NULL, ecran, &posbarre);
                SDL_BlitSurface(petithero2, &frame3[w/4], ecran, &pospetithero);
                SDL_BlitSurface(magicienpetit, &frame3[w/4], ecran, &posmagicienpetit);
                SDL_Flip(ecran);
            }
        }
        /*//collision de spell avec hero
        if(collision(posspellen,poshero)==1)
        {

        hp--;
        posspellen.y=2000;
        enatack=0;
        nbrspellen=0;
        }*/
        //collision de spell avec les ennemies
        if(collision(posspell,posenemie1)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie1.y=2000;
        }
        if(collision(posspell,posenemie2)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie2.y=2000;
        }
        if(collision(posspell,posenemie3)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie3.y=2000;
        }
        if(collision(posspell,posenemie4)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie4.y=2000;
        }
        if(collision(posspell,posenemie5)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie5.y=2000;
        }
        if(collision(posspell,posenemie6)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie6.y=2000;
        }
        if(collision(posspell,posenemie7)==1)
        {
            spellenemie=0;
            cmpsc+=10;
            posspell.x=0;
            intspell=0;
            nbrspell=0;
            posenemie7.y=2000;
        }
        //début enigme
        if (poshero.x + poshero.w < posmagicien.x && poshero.x + poshero.w > posmagicien.x-300 && enig==0 )
        {
            for(j=0; j<400; j++)
            {
                if (compteurmage==24)
                {
                    compteurmage=0;
                }
                compteurmage++;
                animation(&heroactu,idler,&i);
                Blit(background,ecran,posback.x,posback.y);
                SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
             //   SDL_BlitSurface(magicien, &framed[compteurmage/4], ecran, &posmagicienactu);
                SDL_BlitSurface(enigmestage1, &frame2[j/100], ecran, &posenigme1);
                Blit(terre3,ecran,posterre7.x,posterre7.y);
                Blit(terre3,ecran,posterre8.x,posterre8.y);
                Blit(terre3,ecran,posterre9.x,posterre9.y);
                SDL_Flip(ecran);
            }
            enigme3(&ecran, &continuer, &intro, &effet, &effet2, &musique, &mute, &posvolb,&dying,victory,choix);
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            boucle=0;
        }

        //hpup
        if(collision(poshero,poshpup)==1)
        {
            if(hp!=4)
            {
                hp++;
                poshpup.y=2000;
            }
        }

        //dying
        if (hp==0 || (*victory)!=2)
        {
            if(hp==0)
            {
                Mix_PlayChannel( -1, dying, 0 ) ;
                heroactu=hurt;
                for (j=0; j<43; j++)
                {
                    Blit(noir,ecran,posnoir.x,posnoir.y);
                    Blit(rock1,ecran,posrock1.x,posrock1.y);
                    Blit(hpup,ecran,poshpup.x,poshpup.y);
                    Blit(terre1,ecran,posterre1.x,posterre1.y);
                      Blit(terre1,ecran,posterre2.x,posterre2.y);
                      Blit(terre1,ecran,posterre3.x,posterre3.y);
                      Blit(terre2,ecran,posterre4.x,posterre4.y);
                      Blit(terre2,ecran,posterre5.x,posterre5.y);
                      Blit(terre2,ecran,posterre6.x,posterre6.y);
                      Blit(terre3,ecran,posterre7.x,posterre7.y);
                      Blit(terre3,ecran,posterre8.x,posterre8.y);
                      Blit(terre3,ecran,posterre9.x,posterre9.y);
                      Blit(trap1,ecran,postrap1.x,postrap1.y);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie1);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie2);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie3);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie4);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie5);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie6);
                      SDL_BlitSurface(enemie, &framed[j/6], ecran, &posenemie7);
                    SDL_BlitSurface(heroactu, &frame2[j/6], ecran, &poshero);
                    SDL_BlitSurface(vie, NULL, ecran, &posvie);
                    SDL_BlitSurface(imgtime, NULL, ecran, &postime);
                    SDL_BlitSurface(health, NULL, ecran, &poshp);
                    SDL_BlitSurface(score, NULL, ecran, &posscore);
                    SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
                    SDL_Flip(ecran);
                }
                gameover=TTF_RenderText_Blended(fonts, "GAME OVER", couleur1);
                Blit(noir,ecran,posnoir.x,posnoir.y);
                SDL_BlitSurface(heroactu, &frame2[7], ecran, &poshero);
                Blit(gameover,ecran,posgo.x,posgo.y);
                SDL_Flip(ecran);
                SDL_Delay(4000);
            }
            if((*victory)==0)
                hp=0;
            scorefinal =(hp*1000)+ (cmpsc * 100)+ (tmin * 100 ) +tsec;
            char charscore[4];
            sprintf(charscore, "%d",scorefinal);
            fonts = TTF_OpenFont("fonts/Takota.ttf", 90);
            SDL_Color couleur = {255,255,255};
            sprintf(chhp, "%d",hp);
            vie= TTF_RenderText_Blended(fonts,chhp, couleur);


            scoreS= TTF_RenderUTF8_Solid(fonts, charscore, couleur);
            vie= TTF_RenderUTF8_Solid(fonts, chhp, couleur);


            posscoreS.x=800;
            posscoreS.y=470;

            posscore.x=500;
            posscore.y=450;

            posvie.x=800;
            posvie.y=250;

            poshp.x=500;
            poshp.y=230;

            poshero.x=150;
            poshero.y=460;
            //score=IMG_Load ("image/decoration/score1.png");
            health=IMG_Load("image/health/heart1.png");
            SDL_BlitSurface(score, NULL, ecran, &posscore);
            SDL_BlitSurface(vie, NULL, ecran, &posvie);
            SDL_BlitSurface(health, NULL, ecran, &poshp);
            y=255;
            j=0;
            //for (j=0; j<=scorefinal + 2000; j+=9)
            while ( (j<= scorefinal +2000) && (y!=0) )
            {
                j+=9;
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                //SDL_BlitSurface(portal, NULL, ecran, &posportal);
                if (poshero.x<=1050)
                {
                    poshero.x+=4;
                    //animation2(&heroactu,herod,&i);
                    //SDL_SetAlpha (portal, SDL_SRCALPHA, y);
                    if (y!=0)
                    {
                        y-=0.1;
                    }
                }
                /*else
                {
                	animation2(&heroactu,idler,&i);
                }*/

                if (j>=scorefinal)
                {
                    sprintf(charscore, "%d",scorefinal);
                    scoreS= TTF_RenderUTF8_Solid(fonts, charscore, couleur);
                }
                else
                {
                    sprintf(charscore,"%d",j);
                    scoreS= TTF_RenderUTF8_Solid(fonts, charscore, couleur);
                }
                //SDL_BlitSurface(heroactu, &framed[i/8], ecran, &poshero);
                SDL_BlitSurface(score, NULL, ecran, &posscore);
                SDL_BlitSurface(vie, NULL, ecran, &posvie);
                SDL_BlitSurface(health, NULL, ecran, &poshp);
                SDL_BlitSurface(scoreS, NULL, ecran, &posscoreS);
                SDL_Flip(ecran);
            }
            SDL_Delay(3000);
            while (rotozoom!=1)
            {
                tempsActuel = SDL_GetTicks();
                if (tempsActuel - tempsPrecedent > TEMPS)
                {
                    angle+=10;
                    tempsPrecedent = tempsActuel;
                }
                else
                {
                    SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
                }
                Rotation = rotozoomSurface(health, 0, zoom, 1);
                //Rotation2 = rotozoomSurface(score, 0, zoom, 1);
                Rotation3 = rotozoomSurface(vie, 0, zoom, 1);
                //Rotation4 = rotozoomSurface(scoreS, 0, zoom, 1);

                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                //	SDL_BlitSurface(heroactu, &framed[i/8], ecran, &poshero);
                //SDL_BlitSurface(Rotation2, NULL, ecran, &posscore);
                SDL_BlitSurface(Rotation3, NULL, ecran, &posvie);
                SDL_BlitSurface(Rotation, NULL, ecran, &poshp);
                //SDL_BlitSurface(Rotation4, NULL, ecran, &posscoreS);*/
                SDL_Flip(ecran);

                SDL_FreeSurface(Rotation);
                if(zoom >= 1.4)
                {
                    sens = 0;
                }
                else if(zoom <= 0)
                {
                    rotozoom = 1;
                }

                if(sens == 0)
                {
                    zoom -= 0.02;
                }
                else
                {
                    zoom += 0.02;
                }
                SDL_Flip(ecran);
            }
            while(!Mix_FadeOutMusic(3000) && Mix_PlayingMusic())
            {
                SDL_Delay(100);
            }
            posscore.x=120;
            posscore.y=200;
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            while(!Mix_FadeOutMusic(4000) && Mix_PlayingMusic())
            {
                SDL_Delay(100);
            }
            //SDL_BlitSurface(score,NULL, ecran, &posscore);
            SDL_Flip(ecran);
            boucle=0;
        }




        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        Blit(background,ecran,posback.x,posback.y);
        /*// annimation de spell ennemie
        if(spellenemie==1)
        {
                SDL_BlitSurface(spellen,NULL, ecran, &posspellen);
                posspellen.x-=5;
                nbrspellen++;
        }
        if(nbrspellen==100)
        {
        nbrspellen=0;
        spellenemie=0;
        enatack=0;
        posspellen.y=2000;
          		}*/
        // annimation de spell hero
        if (intspell==1)
        {
            SDL_BlitSurface(spell,NULL, ecran, &posspell);
            posspell.x+=25;
            nbrspell++;
        }
        if (intspell==2)
        {
            SDL_BlitSurface(spell,NULL, ecran, &posspell);
            posspell.x-=25;
            nbrspell++;
        }

        if(nbrspell==28)
        {
            posspell.x=0;
            intspell=0;
            nbrspell=0;
        }

        if (boucle==0)
        {
            Mix_PlayMusic(musique, -1);
        }
        //printf("Vitesse: %d ms\n",dte);
        //printf("\n");
        /* sprintf(str,"%d",dte);
        vit=TTF_RenderText_Solid(fonts,str,couleurblanc);
        dte=SDL_GetTicks()-t_prev;*/
        //SDL_Flip(ecran);
        xresult=xfinal-xdeb;
        dte=(xresult/dte);
        sprintf(str,"Vitesse: %d",dte);
        vit=TTF_RenderText_Solid(fonts,str,couleurblanc);
        SDL_BlitSurface(vit,NULL,ecran,&posdte);
        dte=SDL_GetTicks()-t_prev;


        //SDL_Surface *TTF_RenderUTF8_Solid(fonts,const char *text,couleurblanc);
        //affichages
        Blit(rock1,ecran,posrock1.x,posrock1.y);
        Blit(terre1,ecran,posterre1.x,posterre1.y);
        Blit(terre1,ecran,posterre2.x,posterre2.y);
        Blit(terre1,ecran,posterre3.x,posterre3.y);
        Blit(terre2,ecran,posterre4.x,posterre4.y);
        Blit(terre2,ecran,posterre5.x,posterre5.y);
        Blit(terre2,ecran,posterre6.x,posterre6.y);
        Blit(terre3,ecran,posterre7.x,posterre7.y);
        Blit(terre3,ecran,posterre8.x,posterre8.y);
        Blit(terre3,ecran,posterre9.x,posterre9.y);
        Blit(hpup,ecran,poshpup.x,poshpup.y);
        Blit(trap1,ecran,postrap1.x,postrap1.y);
        SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie1);
        SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie2);
        SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie3);
        SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie4);
        SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie5);
        SDL_BlitSurface(enemie, &framed[e1/4], ecran, &posenemie6);
        SDL_BlitSurface(enemie1, &framed[e1/4], ecran, &posenemie7);
     //   SDL_BlitSurface(magicien, &framed[compteurmage/4], ecran, &posmagicienactu);
        SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
        SDL_BlitSurface(vie, NULL, ecran, &posvie);
        SDL_BlitSurface(imgtime, NULL, ecran, &postime);
        SDL_BlitSurface(health, NULL, ecran, &poshp);
        SDL_BlitSurface(score, NULL, ecran, &posscore);
        SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
        SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
        SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);
        SDL_BlitSurface(barre, NULL, ecran, &posbarre);
        SDL_BlitSurface(petithero2, &frame3[w/4], ecran, &pospetithero);
        SDL_BlitSurface(magicienpetit, &frame3[w/4], ecran, &posmagicienpetit);
        SDL_Flip(ecran);
    }


    /*SDL_FreeSurface(health);
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(attackr);
    SDL_FreeSurface(attackl);
    SDL_FreeSurface(herod);
    SDL_FreeSurface(herog);
    SDL_FreeSurface(heroactu);
    SDL_FreeSurface(police);
    SDL_FreeSurface(enemie);
    SDL_FreeSurface(enemied);
    SDL_FreeSurface(enemieg);*/
    SDL_FreeSurface(background);
}
int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
