//fonctions
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include "option.h"
#include "sound.h"
#include "debut.h"
#include "stage1.h"
#include "multi.h"
#include "intro.h"
#include "debut.h"
#include "stage2.h"
#include <SDL/SDL_rotozoom.h>
#define TEMPS 30

#define speed 6
void positionninja(int *i,int *k)
{
    if((*k)==2)
        (*i)--;
    if((*k)==1)
        (*i)++;
    if((*i)==100)
        (*k)=2;
    if((*i)==0)
        (*k)=1;
}
void roto_zoom(SDL_Surface **ecran,SDL_Surface **surface,SDL_Surface **Rotation,SDL_Rect *pos)
{
    double angle=0, zoom=1;
    int sens=1,continuer=1,tempsPrecedent = 0, tempsActuel = 0;
    SDL_Event event;
    while(continuer)
    {
        while (SDL_PollEvent(&event))
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_n:
                    continuer=0;
                    break;
                }
            }
        tempsActuel = SDL_GetTicks();

        if (tempsActuel - tempsPrecedent > TEMPS)

        {

            angle+=2;
            tempsPrecedent = tempsActuel;

        }
        else

        {

            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));

        }

        *Rotation = rotozoomSurface(*surface, angle, zoom, 1);

        (*pos).x =  (*Rotation)->w / 2;

        (*pos).y =  (*Rotation)->h / 2;

        SDL_BlitSurface(*surface, NULL, *ecran, pos);

        SDL_FreeSurface(*Rotation);
        if(zoom >= 3)
        {
            sens = 0;
        }

        else if(zoom <= 0.5)
        {
            continuer = 0;
        }



        if(sens == 0)
        {
            zoom -= 0.02;
        }

        else
        {
            zoom += 0.02;
        }
        SDL_Flip(*ecran);
    }
}
void scrolling2 (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *poshpup1,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3,Sint16 *pose4,Sint16 *pose5,Sint16 *pose6,Sint16 *pose7,Sint16 *pose8,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9,Sint16 *posninjaa, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e)
{
    if (e==1)
    {
        (*camera)+=speed;
        (*poshero)+=speed;
        if((*poshero)>=1366/3 && (*camera)<1366*7-650) //fixe personnage, deplacement decor
        {
            (*posenigme1)-=speed;
            (*postrap1)-=speed;
            (*posterre1)-=speed;
            (*posterre2)-=speed;
            (*posterre3)-=speed;
            (*posterre4)-=speed;
            (*posterre5)-=speed;
            (*posterre6)-=speed;
            (*posterre7)-=speed;
            (*posterre8)-=speed;
            (*posterre9)-=speed;
            (*posninjaa)-=speed;
            (*poshpup)-=speed;
            (*poshpup1)-=speed;
            (*posmagicien)-=speed;
            (*posrock1)-=speed;
            (*poshero)-=speed;
            (*posback)-=speed;
            (*pospolice)-=speed;
            (*pose1)-=speed;
            (*pose2)-=speed;
            (*pose3)-=speed;
            (*pose4)-=speed;
            (*pose5)-=speed;
            (*pose6)-=speed;
            (*pose7)-=speed;
            (*pose8)-=speed;
        }
        if((*poshero)>=((1366/4)*3 +150)) //collision ecran droite
        {
            (*poshero)-=speed;
            (*camera)-=speed;
        }
    }
    else if (e==2)
    {
        (*camera)-=speed;
        (*poshero)-=speed;
        if((*poshero)<=(*ecran)->w/5)
        {
            (*posenigme1)+=speed;
            (*posterre1)+=speed;
            (*posterre2)+=speed;
            (*posterre3)+=speed;
            (*posterre4)+=speed;
            (*posterre5)+=speed;
            (*posterre6)+=speed;
            (*posterre7)+=speed;
            (*posterre8)+=speed;
            (*posterre9)+=speed;
            (*posninjaa)+=speed;
            (*posmagicien)+=speed;
            (*poshpup)+=speed;
            (*poshpup1)+=speed;
            (*postrap1)+=speed;
            (*posrock1)+=speed;
            (*pose1)+=speed;
            (*pose2)+=speed;
            (*pose3)+=speed;
            (*pose4)+=speed;
            (*pose5)+=speed;
            (*pose6)+=speed;
            (*pose7)+=speed;
            (*pose8)+=speed;
            (*posback)+=speed;
            (*pospolice)+=speed;
            (*poshero)+=speed;
            if((*camera)<0)
            {
                (*poshero)+=speed;
                (*camera)+=speed;
            }
        }
        if ((*posback)>0)
        {
            (*posenigme1)=9250;
            (*posterre1)=1300;
            (*posterre2)=1800;
            (*posterre3)=2300;
            (*posterre4)=3300;
            (*posterre5)=3800;
            (*posterre6)=4300;
            (*posterre7)=5300;
            (*posterre8)=5800;
            (*posterre9)=6300;
            (*posninjaa)=7500;
            (*posmagicien)=9500;
            (*poshpup)=2360;
            (*poshpup1)=5360;
            (*postrap1)=2800;
            (*posrock1)=500;
            (*pospolice)=800;
            (*pose1)=1000;
            (*pose2)=2000;
            (*pose3)=3000;
            (*pose4)=4000;
            (*pose5)=5000;
            (*pose6)=6000;
            (*pose7)=7000;
            (*pose8)=8000;
            (*posback)=0;
            (*poshero)-=speed;
            if ((*poshero)<0)
            {
                (*poshero)+=speed;
            }
        }
    }
}
void scrolling (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3,Sint16 *pose4,Sint16 *pose5,Sint16 *pose6,Sint16 *pose7,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e)
{
    if (e==1)
    {
        (*camera)+=speed;
        (*poshero)+=speed;
        if((*poshero)>=1366/3 && (*camera)<1366*5) //fixe personnage, deplacement decor
        {
            (*posenigme1)-=speed;
            (*postrap1)-=speed;
            (*posterre1)-=speed;
            (*posterre2)-=speed;
            (*posterre3)-=speed;
            (*posterre4)-=speed;
            (*posterre5)-=speed;
            (*posterre6)-=speed;
            (*posterre7)-=speed;
            (*posterre8)-=speed;
            (*posterre9)-=speed;
            (*poshpup)-=speed;
            (*posmagicien)-=speed;
            (*posrock1)-=speed;
            (*poshero)-=speed;
            (*posback)-=speed;
            (*pospolice)-=speed;
            (*pose1)-=speed;
            (*pose2)-=speed;
            (*pose3)-=speed;
            (*pose4)-=speed;
            (*pose5)-=speed;
            (*pose6)-=speed;
            (*pose7)-=speed;
        }
        if((*poshero)>=((1366/4)*3 +150)) //collision ecran droite
        {
            (*poshero)-=speed;
            (*camera)-=speed;
        }
    }
    else if (e==2)
    {
        (*camera)-=speed;
        (*poshero)-=speed;
        if((*poshero)<=(*ecran)->w/5)
        {
            (*posenigme1)+=speed;
            (*posterre1)+=speed;
            (*posterre2)+=speed;
            (*posterre3)+=speed;
            (*posterre4)+=speed;
            (*posterre5)+=speed;
            (*posterre6)+=speed;
            (*posterre7)+=speed;
            (*posterre8)+=speed;
            (*posterre9)+=speed;
            (*posmagicien)+=speed;
            (*poshpup)+=speed;
            (*postrap1)+=speed;
            (*posrock1)+=speed;
            (*pose1)+=speed;
            (*pose2)+=speed;
            (*pose3)+=speed;
            (*pose4)+=speed;
            (*pose5)+=speed;
            (*pose6)+=speed;
            (*pose7)+=speed;
            (*posback)+=speed;
            (*pospolice)+=speed;
            (*poshero)+=speed;
            if((*camera)<0)
            {
                (*poshero)+=speed;
                (*camera)+=speed;
            }
        }
        if ((*posback)>0)
        {
            (*posenigme1)=6700;
            (*posterre1)=1300;
            (*posterre2)=1800;
            (*posterre3)=2300;
            (*posterre4)=3300;
            (*posterre5)=3800;
            (*posterre6)=4300;
            (*posterre7)=5300;
            (*posterre8)=5800;
            (*posterre9)=6300;
            (*posmagicien)=7500;
            (*poshpup)=2360;
            (*postrap1)=2800;
            (*posrock1)=500;
            (*pospolice)=800;
            (*pose1)=1000;
            (*pose2)=2000;
            (*pose3)=3000;
            (*pose4)=4000;
            (*pose5)=5000;
            (*pose6)=6000;
            (*pose7)=7000;
            (*posback)=0;
            (*poshero)-=speed;
            if ((*poshero)<0)
            {
                (*poshero)+=speed;
            }
        }
    }
}
void animation ( SDL_Surface **a, SDL_Surface *b, int *i)
{
    (*i)++;
    if ((*i)==32)
    {
        (*i)=0;
    }
    (*a)=b;
}

void animation2 ( SDL_Surface **a, SDL_Surface *b, int *i)
{
    (*i)++;
    if ((*i)==64)
    {
        (*i)=0;
    }
    (*a)=b;
}

void animation3 ( SDL_Surface **a, SDL_Surface *b, int *i)
{
    (*i)++;
    if ((*i)==16)
    {
        (*i)=0;
    }
    (*a)=b;
}

int collision(SDL_Rect hero,SDL_Rect autre)
{
    if((autre.x <= hero.x + hero.w)&& (autre.x + autre.w >= hero.x)&& (autre.y <= hero.y + hero.h)&& (autre.y +autre.h>= hero.y))
        return 1;
    else
        return 0;
}
int Collision(int x,int y,SDL_Rect C)
{
    int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
    if (d2>C.w/2*C.w/2)
        return 0;
    else
        return 1;
}
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
    SDL_Color color ;
    Uint32 col = 0 ;

    //determine position
    char* pPosition = ( char* ) surface->pixels ;

    //offset by y
    pPosition += ( surface->pitch * y ) ;

    //offset by x
    pPosition += ( surface->format->BytesPerPixel * x ) ;

    //copy pixel data
    memcpy ( &col, pPosition, surface->format->BytesPerPixel ) ;

    //convert color
    SDL_GetRGB ( col, surface->format, &color.r, &color.g, &color.b ) ;
    return ( color ) ;
}

int hover(SDL_Rect pos,int x,int y)
{
    Uint8 p;
    if((x >= pos.x) && (x <= pos.x + pos.w) && ( y >= pos.y) && (y <= pos.y + pos.h))
        return 1;
    else
        return 0;
}

int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

    SDL_Color col;
    if(d==0)//imin
    {
        col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
    }
    else  if(d==1)//issarr
    {
        col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
    }
    else  if(d==2)//lfou9
    {
        col=GetPixel(calque,posperso.x+(perso->w/2)+decalage,posperso.y);
    }
    else  if(d==3)//louta
    {
        col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
    }
    //printf("%d    %d   %d\n",col.r,col.b,col.g );
    if ((col.r==255)&&(col.b==255)&&(col.g==255))
    {
        return 1;
    }
    else
        return 0;
}


void chargerTous(SDL_Surface **ecran,SDL_Surface **star,SDL_Surface **shab1,SDL_Surface **shab2,SDL_Surface **shab3,SDL_Surface **menu,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textecredits,SDL_Surface **textequit,Mix_Music **musique,Mix_Chunk **effet,Mix_Chunk **sonspell,Mix_Chunk **dying,Mix_Chunk **hit, Mix_Chunk **effet2,TTF_Font **police,TTF_Font **police1,SDL_Color couleur)
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_WM_SetIcon(IMG_Load("image/icon.png"), NULL);
    (*ecran) = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE); //|SDL_FULLSCREEN);
    SDL_WM_SetCaption("Phunyuka", NULL);
    //(*star)=IMG_Load("image/star.png");
    (*shab1)=IMG_Load("image/shab1.png");
    (*shab2)=IMG_Load("image/shab2.png");
    (*shab3)=IMG_Load("image/shab3.png");
    (*menu) = IMG_Load("image/1.png");


    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    (*effet) = Mix_LoadWAV("music/boutonn.wav");
    (*effet2) = Mix_LoadWAV("music/boutofff.wav");
    (*sonspell)= Mix_LoadWAV("music/sonspell.wav");
    //(*hit)=Mix_LoadWAV("music/
    (*dying)=Mix_LoadWAV("music/hero dying2.wav");
    (*musique) = Mix_LoadMUS("music/menu.mp3");

    (*police) = TTF_OpenFont("fonts/Takota.ttf", 50);
    (*police1)= TTF_OpenFont("fonts/calibri.ttf", 20);
    (*texteplay) = TTF_RenderText_Blended((*police), "NEW GAME", couleur);
    (*textemulti) = TTF_RenderText_Blended((*police), "CONTINUE", couleur);
    (*texteoption) = TTF_RenderText_Blended((*police), "OPTION", couleur);
   // (*textecredits) = TTF_RenderText_Blended((*police), "CREDITS", couleur);
    (*textequit) = TTF_RenderText_Blended((*police), "QUIT", couleur);
}
void remplirlesposition(SDL_Rect *positionFond,SDL_Rect *posquit,SDL_Rect *posmulti,SDL_Rect *posoption,SDL_Rect *poscredits, SDL_Rect *posplay,SDL_Rect *posstar,SDL_Rect *poscquit,SDL_Rect *poscmulti,SDL_Rect *poscoption,SDL_Rect *poscplay,SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3,SDL_Rect *posvolb)
{
    posvolb->x=660;
    posvolb->y=363;
    posshab1->x=10;
    posshab1->y=40;
    posshab2->x=500;
    posshab2->y=200;
    posshab3->x=1170;
    posshab3->y=190;
    posstar->x=655;
    posstar->y=130;
    positionFond->x = 0;
    positionFond->y =0;
    posplay->x=575;
    posplay->y=210;
    posquit->x=630;
    posquit->y=540;
    posmulti->x=575;
    posmulti->y=320;
    posoption->x=600;
    posoption->y=430;
    poscredits->x=700;
    poscredits->y=560;
    poscplay->x=600;
    poscplay->y=200;
    poscquit->x=260;
    poscquit->y=690;
    poscmulti->x=400;
    poscmulti->y=320;
    poscoption->x=310;
    poscoption->y=440;

}


void transparent(int *a,int*b)
{
    (*a)+=(*b);
    if (((*a)==254)||((*a)==0))
        (*b)=-(*b);

}
void affichagetextmenu(TTF_Font **police,TTF_Font **police1,SDL_Color couleur,SDL_Color couleur2,SDL_Event event,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textecredits,SDL_Surface  **textequit,SDL_Surface **commentaireplay,SDL_Surface  **commentaireoption,SDL_Surface **commentairemulti,SDL_Surface **commentairequit,Mix_Chunk *effet,int *son,int *mute)
{
    FILE * fichier =NULL;


    if (event.motion.x<835  && event.motion.x>575 && event.motion.y<290 && event.motion.y>200)
    {
        TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
        (*texteplay)= TTF_RenderText_Blended((*police), "NEW GAME", couleur2);
        TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
       // (*commentaireplay) = TTF_RenderText_Blended((*police1), "play new game", couleur);
        if ((*son)==0 && *mute==0)
        {
            (*son)=1;
            Mix_PlayChannel( -1, effet, 0 ) ;
        }
    }
    else if (event.motion.x<830  && event.motion.x>575 && event.motion.y<400 && event.motion.y>340)
    {
        TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
        (*textemulti)= TTF_RenderText_Blended((*police), "CONTINUE", couleur2);
        TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
       //  (*commentairemulti)= TTF_RenderText_Blended((*police1), "continue game", couleur);
        if ((*son)==0 && *mute==0)
        {
            (*son)=1;
            Mix_PlayChannel( -1, effet, 0 ) ;
        }
    }
    else if (event.motion.x<820  && event.motion.x>600 && event.motion.y<520 && event.motion.y>450)
    {
        TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
        (*texteoption) = TTF_RenderText_Blended((*police), "OPTION", couleur2);
        TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
     //     (*commentaireoption)= TTF_RenderText_Blended((*police1), "go to menu option", couleur);
        if ((*son)==0 && *mute==0)
        {
            (*son)=1;
            Mix_PlayChannel( -1, effet, 0 ) ;
        }
    }
    else if (event.motion.x<830  && event.motion.x>630 && event.motion.y<640 && event.motion.y>560)
    {
        TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
        (*textequit) = TTF_RenderText_Blended((*police), "QUIT", couleur2);
        TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
      //   (*commentairequit)= TTF_RenderText_Blended((*police1), "leave game", couleur);
        if ((*son)==0 && *mute==0)
        {
            (*son)=1;
            Mix_PlayChannel( -1, effet, 0 ) ;
        }
    }
    else
    {
        (*son)=0;
        TTF_SetFontStyle((*police), TTF_STYLE_NORMAL);
        (*texteplay)= TTF_RenderText_Blended((*police), "NEW GAME", couleur);
        (*textemulti)= TTF_RenderText_Blended((*police), "CONTINUE", couleur);
        (*texteoption)= TTF_RenderText_Blended((*police), "OPTION", couleur);
     //   (*textecredits)= TTF_RenderText_Blended((*police), "4: CREDITS", couleur);
        (*textequit)= TTF_RenderText_Blended((*police), "QUIT", couleur);
        (*commentaireplay)= NULL;
        (*commentaireoption)= NULL ;
           (*commentairequit)= NULL;
           (*commentairemulti) =NULL;
    }
}
void buttons(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix)
{
    int boucle;
    FILE* fichier = NULL;
    int e=0;
    if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<835 && event.motion.x>575 && event.motion.y<290 && event.motion.y>200)
    {
        bouton_newgame (ecran, event,effet,effet2,continuer,musique,mute,posvolb,intro,sonspell,dying,hit,victory,choix);
    }
    if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<830  && event.motion.x>575 && event.motion.y<400 && event.motion.y>340)
    {
        fichier = fopen("Xstage", "r");
        if (fichier != NULL)
        {
            fscanf(fichier,"%d",&e);
            if (e==1)
            {
                stage1s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                if ((*victory)==1)
                {
                    stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                }
                /*if ((*victory)==1)
                {
                	stage3
                }*/
            }
            else if (e==2)
            {
                stage2s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                /*if ((*victory)==1)
                {
                	stage3
                }*/
            }
            /*else if (e==3)
            {
            	stage3
            }*/
        }
    }
    if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<820  && event.motion.x>600 && event.motion.y<520 && event.motion.y>450)
    {
        if ((*mute)==0)
        {
            Mix_PlayChannel( -1, effet2, 0 ) ;
        }
        option(ecran,effet,effet2,musique,mute,continuer,posvolb,choix);
    }
    else if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<830  && event.motion.x>630 && event.motion.y<640 && event.motion.y>560)
    {
        if ((*mute)==0)
        {
            Mix_PlayChannel( -1, effet2, 0 ) ;
        }
        (*continuer) = 0;
    }
}
void buttons1(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix)
{
    int e=0;
    FILE* fichier = NULL;
    switch (event.key.keysym.sym)
    {
    case SDLK_KP1:
        bouton_newgame (ecran, event,effet,effet2,continuer,musique,mute,posvolb,intro,sonspell,dying,hit,victory,choix);
        break;
    case SDLK_KP2:
        fichier = fopen("Xstage", "r");
        if (fichier != NULL)
        {
            fscanf(fichier,"%d",&e);
            if (e==1)
            {
                stage1s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                if ((*victory)==1)
                {
                    stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                }
                /*if ((*victory)==1)
                {
                	stage3
                }*/
            }
            else if (e==2)
            {
                stage2s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                /*if ((*victory)==1)
                {
                	stage3
                }*/
            }
            /*else if (e==3)
            {
            	stage3
            }*/
        }
        break;
    case SDLK_KP3:
        option(ecran,effet,effet2,musique,mute,continuer,posvolb,choix);
        break;
    case SDLK_KP4:
        (*continuer)=0;
        break;
    }

}
void positionenemie(int *i,int *k)
{
    if((*k)==2)
        (*i)--;
    if((*k)==1)
        (*i)++;
    if((*i)==20)
        (*k)=2;
    if((*i)==0)
        (*k)=1;
}
void positionshab(SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3, int *direction,int *direction2,int *direction3)
{
    posshab1->x=posshab1->x+(*direction);
    if(posshab1->x==200 || posshab1->x==10)
        (*direction)=-(*direction);
    posshab2->x=posshab2->x+(*direction2);
    if(posshab2->x==500 || posshab2->x==700)
        (*direction2)=-(*direction2);
    posshab3->x=posshab3->x+(*direction3);
    if(posshab3->x==1170 || posshab3->x==1250)
        (*direction3)=-(*direction3);
}

void bouton_newgame (SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix)
{
    SDL_Surface *backgr=NULL, *newg=NULL, *multi=NULL,*picnew=NULL,*picmulti=NULL,*back=NULL;
    SDL_Rect posbackgr, posnewg, posmulti,pospicnew,pospicmulti,posback;
    TTF_Font *police = NULL;
    backgr=IMG_Load ("image/menu.png");
    int boucle=1,r=0,j=0,u=0;
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    SDL_Color couleur = {255, 255, 255}, couleur2 = {255,0,0};
    police = TTF_OpenFont("fonts/Takota.ttf", 70);
    pospicnew.x=280;
    pospicnew.y=130;
    posmulti.x=770;
    posmulti.y=120;
    posbackgr.x=0;
    posbackgr.y=0;
    posnewg.x=210;
    posnewg.y=520;
    pospicmulti.x=860;
    pospicmulti.y=520;
    posback.x=600;
    posback.y=650;
    SDL_BlitSurface(backgr,NULL,ecran,&posbackgr);
    picnew =IMG_Load ("image/perso/newgame.png");
    picmulti =IMG_Load ("image/perso/multi.png");
    newg = TTF_RenderText_Blended(police, "NEW GAME", couleur);
    multi = TTF_RenderText_Blended(police, "MULTI", couleur);
    back = TTF_RenderText_Blended(police, "BACK", couleur);

    SDL_BlitSurface(picnew,NULL,ecran,&pospicnew);
    SDL_BlitSurface(picmulti,NULL,ecran,&posmulti);
    SDL_BlitSurface(newg,NULL,ecran,&posnewg);
    SDL_BlitSurface(multi,NULL,ecran,&pospicmulti);
    SDL_BlitSurface(back,NULL,ecran,&posback);
    SDL_Flip(ecran);
    int x,y,son=0;
    SDL_Delay(800);
    while ((*continuer) && boucle )
    {
        SDL_GetMouseState(&x,&y);
        while (SDL_PollEvent(&event))
            switch(event.type)
            {
            case SDL_QUIT:
                *continuer=0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_KP1:
                   // debut(ecran);
                    //stage0(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell);
                    if (*continuer==1)
                    {
                        stage1(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                    }
                    if ((*victory)==1)
                    {
                        stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                    }
                    break;

                case SDLK_KP2:
                    Multi(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,choix);
                    break;

                case SDLK_KP0:
                    boucle=0;
                    break;
                }

            }
        if (hover(pospicnew,x,y)==1 || hover(posnewg,x,y)==1)
        {
            TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
            newg = TTF_RenderText_Blended(police, "NEW GAME", couleur2);
            if (son==0 && *mute==0)
            {
                son=1;
                Mix_PlayChannel( -1, effet, 0 ) ;
            }
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                //debut(ecran);
                //stage0(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell);
                //if (*continuer==1)
                //{
                //stage1(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
                //}
                //if ((*victory)==1)
                //{
                stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory,choix);
                //}
                //if (*continuer==1)
                //multi(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit);*/
            }
        }
        else if (hover(pospicmulti,x,y)==1 || hover(posmulti,x,y)==1)
        {
            TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
            multi = TTF_RenderText_Blended(police, "MULTI", couleur2);
            if (son==0 && *mute==0)
            {
                son=1;
                Mix_PlayChannel( -1, effet, 0 ) ;
            }
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                Multi(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,choix);
            }
        }
        else if (hover(posback,x,y)==1)
        {
            TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
            back = TTF_RenderText_Blended(police, "BACK", couleur2);
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                boucle=0;
            }
        }
        else
        {
            son=0;
            TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
            newg = TTF_RenderText_Blended(police, "NEW GAME", couleur);
            multi = TTF_RenderText_Blended(police, "MULTI", couleur);
            back = TTF_RenderText_Blended(police, "BACK", couleur);
        }
        SDL_BlitSurface(backgr,NULL,ecran,&posbackgr);
        SDL_BlitSurface(picnew,NULL,ecran,&pospicnew);
        SDL_BlitSurface(picmulti,NULL,ecran,&posmulti);
        SDL_BlitSurface(newg,NULL,ecran,&posnewg);
        SDL_BlitSurface(multi,NULL,ecran,&pospicmulti);
        SDL_BlitSurface(back,NULL,ecran,&posback);
        SDL_Flip(ecran);
    }


}
void Pause1(SDL_Surface *ecran,Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3,SDL_Rect *pose4,SDL_Rect *pose5,SDL_Rect *pose6,SDL_Rect *pose7,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,int *continuer, int tsec, int tmin, int hp, int cmpsc )

{
    SDL_Surface *pause=NULL,*confirm=NULL,*cancel=NULL,*confirm2=NULL,*cancel2=NULL,*Confirm=NULL,*Cancel=NULL;
    SDL_Rect pospause,posconfirm,poscancel;
    pospause.x=350;
    pospause.y=150;
    posconfirm.x=500;
    posconfirm.y=350;
    poscancel.x=800;
    poscancel.y=350;
    int boucle=1;
    int x=0,y=0,couleur1=0,couleur2=0,tmp=0,postmp[36];
    SDL_Event event;
    FILE* fichier = NULL;
    FILE* fichier2 = NULL;
    postmp[0]=*poshero;
    postmp[1]=*posmagicien;
    postmp[2]=*posenigme1;
    postmp[3]=*poshpup;
    postmp[4]=*posback;
    postmp[5]=*pospolice;
    postmp[6]=pose1->x;
    postmp[7]=pose2->x;
    postmp[8]=pose3->x;
    postmp[9]=pose4->x;
    postmp[10]=pose5->x;
    postmp[11]=pose6->x;
    postmp[12]=pose7->x;
    postmp[13]=*posrock1;
    postmp[14]=*postrap1;
    postmp[15]=*posterre3;
    postmp[16]=*posterre1;
    postmp[17]=*posterre2;
    postmp[18]=*posterre4;
    postmp[19]=*posterre5;
    postmp[20]=*posterre6;
    postmp[21]=*posterre7;
    postmp[22]=*posterre8;
    postmp[23]=*posterre9;
    postmp[24]=*camera;
    postmp[25]=pose1->y;
    postmp[26]=pose2->y;
    postmp[27]=pose3->y;
    postmp[28]=pose4->y;
    postmp[29]=pose5->y;
    postmp[30]=pose6->y;
    postmp[31]=pose7->y;
    postmp[32]=tsec;
    postmp[33]=tmin;
    postmp[34]=hp;
    postmp[35]=cmpsc;
    pause=IMG_Load("image/stage/pause.png");
    confirm=IMG_Load("image/stage/confirm.png");
    cancel=IMG_Load("image/stage/cancel.png");
    cancel2=IMG_Load("image/stage/canncel.png");
    confirm2=IMG_Load("image/stage/confim.png");
    Confirm=confirm;
    Cancel=cancel;
    while (boucle)
    {
        while (SDL_PollEvent(&event))
            SDL_GetMouseState(&x,&y);
        if (hover(posconfirm, x, y))
        {
            Confirm=confirm2;
            couleur1=1;
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                fichier = fopen("xsauvegarde.txt", "w");
                if (fichier != NULL)
                {
                    for (int i=0; i<36; i++)
                    {
                        tmp=(int)postmp[i];
                        fprintf(fichier, "%d ", tmp);
                    }
                    fclose(fichier);
                    fichier2 = fopen("Xstage", "w");
                    if (fichier2 != NULL)
                    {
                        fprintf(fichier, "1");
                    }
                    fclose(fichier2);
                    boucle=0;
                }
            }
        }
        else
            couleur1=0;
        if (hover(poscancel, x, y))
        {
            couleur2=1;
            Cancel=cancel2;
            if (event.button.button == SDL_BUTTON_LEFT)
                boucle=0;
        }
        else
            couleur2=0;
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                boucle= 0;
                break;
            }

        }
        if (couleur1==1)
        {
            Confirm=confirm2;
        }
        else
        {
            Confirm=confirm;
        }
        if (couleur2==1)
        {
            Cancel=cancel2;
        }
        else
        {
            Cancel=cancel;
        }
        SDL_BlitSurface(pause,NULL,ecran,&pospause);
        SDL_BlitSurface(Confirm,NULL,ecran,&posconfirm);
        SDL_BlitSurface(Cancel,NULL,ecran,&poscancel);
        SDL_Flip(ecran);
    }
}

void Pause2(SDL_Surface *ecran,Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3,SDL_Rect *pose4,SDL_Rect *pose5,SDL_Rect *pose6,SDL_Rect *pose7,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,int *continuer, int tsec, int tmin, int hp, int cmpsc,Sint16 *posninja, SDL_Rect *pose8,Sint16 *poshpup1,Sint16 *posninjaa)

{
    SDL_Surface *pause=NULL,*confirm=NULL,*cancel=NULL,*confirm2=NULL,*cancel2=NULL,*Confirm=NULL,*Cancel=NULL;
    SDL_Rect pospause,posconfirm,poscancel;
    pospause.x=350;
    pospause.y=150;
    posconfirm.x=500;
    posconfirm.y=350;
    poscancel.x=800;
    poscancel.y=350;
    int boucle=1;
    int x=0,y=0,couleur1=0,couleur2=0,tmp=0,postmp[40];
    SDL_Event event;
    FILE* fichier = NULL;
    FILE* fichier2 = NULL;
    postmp[0]=*poshero;
    postmp[1]=*posmagicien;
    postmp[2]=*posenigme1;
    postmp[3]=*poshpup;
    postmp[4]=*posback;
    postmp[5]=*pospolice;
    postmp[6]=pose1->x;
    postmp[7]=pose2->x;
    postmp[8]=pose3->x;
    postmp[9]=pose4->x;
    postmp[10]=pose5->x;
    postmp[11]=pose6->x;
    postmp[12]=pose7->x;
    postmp[13]=*posrock1;
    postmp[14]=*postrap1;
    postmp[15]=*posterre3;
    postmp[16]=*posterre1;
    postmp[17]=*posterre2;
    postmp[18]=*posterre4;
    postmp[19]=*posterre5;
    postmp[20]=*posterre6;
    postmp[21]=*posterre7;
    postmp[22]=*posterre8;
    postmp[23]=*posterre9;
    postmp[24]=*camera;
    postmp[25]=pose1->y;
    postmp[26]=pose2->y;
    postmp[27]=pose3->y;
    postmp[28]=pose4->y;
    postmp[29]=pose5->y;
    postmp[30]=pose6->y;
    postmp[31]=pose7->y;
    postmp[32]=tsec;
    postmp[33]=tmin;
    postmp[34]=hp;
    postmp[35]=*posninja;
    postmp[36]=pose8->x;
    postmp[37]=pose8->y;
    postmp[38]=*poshpup1;
    postmp[39]=*posninjaa;
    pause=IMG_Load("image/stage/pause2.png");
    confirm=IMG_Load("image/stage/confim2.png");
    cancel=IMG_Load("image/stage/cancel2.png");
    cancel2=IMG_Load("image/stage/cancel22.png");
    confirm2=IMG_Load("image/stage/confirm22.png");
    Confirm=confirm;
    Cancel=cancel;
    while (boucle)
    {
        while (SDL_PollEvent(&event))
            SDL_GetMouseState(&x,&y);
        if (hover(posconfirm, x, y))
        {
            Confirm=confirm2;
            couleur1=1;
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                fichier = fopen("xsauvegarde.txt", "w");
                if (fichier != NULL)
                {
                    for (int i=0; i<39; i++)
                    {
                        tmp=(int)postmp[i];
                        fprintf(fichier, "%d ", tmp);
                    }
                    fclose(fichier);
                    fichier2 = fopen("Xstage", "w");
                    if (fichier2 != NULL)
                    {
                        fprintf(fichier, "2");
                    }
                    fclose(fichier2);
                    boucle=0;
                }
            }

        }
        else
            couleur1=0;
        if (hover(poscancel, x, y))
        {
            couleur2=1;
            Cancel=cancel2;
            if (event.button.button == SDL_BUTTON_LEFT)
                boucle=0;
        }
        else
            couleur2=0;
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                boucle= 0;
                break;
            }

        }
        if (couleur1==1)
        {
            Confirm=confirm2;
        }
        else
        {
            Confirm=confirm;
        }
        if (couleur2==1)
        {
            Cancel=cancel2;
        }
        else
        {
            Cancel=cancel;
        }
        SDL_BlitSurface(pause,NULL,ecran,&pospause);
        SDL_BlitSurface(Confirm,NULL,ecran,&posconfirm);
        SDL_BlitSurface(Cancel,NULL,ecran,&poscancel);
        SDL_Flip(ecran);
    }
}


void charger(Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3,SDL_Rect *pose4,SDL_Rect *pose5,SDL_Rect *pose6,SDL_Rect *pose7,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera, int *continuer, int *stage, int *tsec, int *tmin, int *hp, int *cmpsc)
{
    int postmp[37],pos=0,i=0;
    FILE* fichier = NULL;
    fichier = fopen("xsauvegarde.txt", "r");
    if (fichier != NULL)
    {
        while (fscanf(fichier,"%d ",&pos)!=EOF)
        {
            postmp[i]=pos;
            i++;
        }
        *poshero=postmp[0];
        *posmagicien=postmp[1];
        *posenigme1=postmp[2];
        *poshpup=postmp[3];
        *posback=postmp[4];
        *pospolice=postmp[5];
        pose1->x=postmp[6];
        pose2->x=postmp[7];
        pose3->x=postmp[8];
        pose4->x=postmp[9];
        pose5->x=postmp[10];
        pose6->x=postmp[11];
        pose7->x=postmp[12];
        *posrock1=postmp[13];
        *postrap1=postmp[14];
        *posterre3=postmp[15];
        *posterre1=postmp[16];
        *posterre2=postmp[17];
        *posterre4=postmp[18];
        *posterre5=postmp[19];
        *posterre6=postmp[20];
        *posterre7=postmp[21];
        *posterre8=postmp[22];
        *posterre9=postmp[23];
        *camera=postmp[24];
        pose1->y=postmp[25];
        pose2->y=postmp[26];
        pose3->y=postmp[27];
        pose4->y=postmp[28];
        pose5->y=postmp[29];
        pose6->y=postmp[30];
        pose7->y=postmp[31];
        *tsec=postmp[32];
        *tmin=postmp[33];
        *hp=postmp[34];
        *cmpsc=postmp[35];
    }
    fclose(fichier);
}

void charger2(Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3,SDL_Rect *pose4,SDL_Rect *pose5,SDL_Rect *pose6,SDL_Rect *pose7,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera, int *continuer, int *stage, int *tsec, int *tmin, int *hp, int *cmpsc,Sint16 *posninja, SDL_Rect *pose8,Sint16 *poshpup1, Sint16 *posninjaa)
{
    int postmp[40],pos=0,i=0;
    FILE* fichier = NULL;
    fichier = fopen("xsauvegarde.txt", "r");
    if (fichier != NULL)
    {

        while (fscanf(fichier,"%d ",&pos)!=EOF)
        {
            postmp[i]=pos;
            i++;
        }
        *poshero=postmp[0];
        *posmagicien=postmp[1];
        *posenigme1=postmp[2];
        *poshpup=postmp[3];
        *posback=postmp[4];
        *pospolice=postmp[5];
        pose1->x=postmp[6];
        pose2->x=postmp[7];
        pose3->x=postmp[8];
        pose4->x=postmp[9];
        pose5->x=postmp[10];
        pose6->x=postmp[11];
        pose7->x=postmp[12];
        *posrock1=postmp[13];
        *postrap1=postmp[14];
        *posterre3=postmp[15];
        *posterre1=postmp[16];
        *posterre2=postmp[17];
        *posterre4=postmp[18];
        *posterre5=postmp[19];
        *posterre6=postmp[20];
        *posterre7=postmp[21];
        *posterre8=postmp[22];
        *posterre9=postmp[23];
        *camera=postmp[24];
        pose1->y=postmp[25];
        pose2->y=postmp[26];
        pose3->y=postmp[27];
        pose4->y=postmp[28];
        pose5->y=postmp[29];
        pose6->y=postmp[30];
        pose7->y=postmp[31];
        *tsec=postmp[32];
        *tmin=postmp[33];
        *hp=postmp[34];
        *posninja=postmp[35];
        pose8->x=postmp[36];
        pose8->y=postmp[37];
        *poshpup1=postmp[38];
        *posninjaa=postmp[39];
    }
    fclose(fichier);
}
