#include "option.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
void positionninja(int *i,int *k);
void roto_zoom(SDL_Surface **ecran,SDL_Surface **surface,SDL_Surface **Rotation,SDL_Rect *pos);
void animation3 ( SDL_Surface **a, SDL_Surface *b, int *i);
int hover(SDL_Rect pos,int x,int y);
void bouton_newgame (SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix);
void scrolling2 (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *poshpup1,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3 ,Sint16 *pose4 ,Sint16 *pose5 ,Sint16 *pose6 ,Sint16 *pose7 ,Sint16 *pose8 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9,Sint16 *posninjaa, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e);
void scrolling (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3 ,Sint16 *pose4 ,Sint16 *pose5 ,Sint16 *pose6 ,Sint16 *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e);
void animation2 ( SDL_Surface **a, SDL_Surface *b, int *i);
int collision(SDL_Rect hero,SDL_Rect autre);
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d);
void animation ( SDL_Surface **a, SDL_Surface *b, int *i);
void chargerTous(SDL_Surface **ecran,SDL_Surface **star,SDL_Surface **shab1,SDL_Surface **shab2,SDL_Surface **shab3,SDL_Surface **menu,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textecredits,SDL_Surface **textequit,Mix_Music **musique,Mix_Chunk **effet,Mix_Chunk **sonspell,Mix_Chunk **dying,Mix_Chunk **hit, Mix_Chunk **effet2,TTF_Font **police,TTF_Font **police1,SDL_Color couleur);
void remplirlesposition(SDL_Rect *positionFond,SDL_Rect *posquit,SDL_Rect *posmulti,SDL_Rect *posoption,SDL_Rect *poscredits, SDL_Rect *posplay,SDL_Rect *posstar,SDL_Rect *poscquit,SDL_Rect *poscmulti,SDL_Rect *poscoption,SDL_Rect *poscplay,SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3,SDL_Rect *posvolb);
void buttons(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix);
void buttons1(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory,int *choix);
void charger2(Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3 ,SDL_Rect *pose4 ,SDL_Rect *pose5 ,SDL_Rect *pose6 ,SDL_Rect *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera, int *continuer, int *stage, int *tsec, int *tmin, int *hp, int *cmpsc,Sint16 *posninja, SDL_Rect *pose8,Sint16 *poshpup1,Sint16 *posninjaa);
void transparent(int *a,int*b);
void affichagetextmenu(TTF_Font **police,TTF_Font **police1,SDL_Color couleur,SDL_Color couleur2,SDL_Event event,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textecredits,SDL_Surface  **textequit,SDL_Surface **commentaireplay,SDL_Surface  **commentaireoption,SDL_Surface **commentairemulti,SDL_Surface **commentairequit,Mix_Chunk *effet,int *son,int *mute);
void positionshab(SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3, int *direction,int *direction2,int *direction3);
void positionenemie(int *i,int *k);
void Pause1(SDL_Surface *ecran,Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3 ,SDL_Rect *pose4 ,SDL_Rect *pose5 ,SDL_Rect *pose6 ,SDL_Rect *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,int *continuer, int tsec, int tmin, int hp, int cmpsc );
void charger(Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3 ,SDL_Rect *pose4 ,SDL_Rect *pose5 ,SDL_Rect *pose6 ,SDL_Rect *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera, int *continuer, int *stage, int *tsec, int *tmin, int *hp,int *cmpsc);
void Pause2(SDL_Surface *ecran,Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3 ,SDL_Rect *pose4 ,SDL_Rect *pose5 ,SDL_Rect *pose6 ,SDL_Rect *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,int *continuer, int tsec, int tmin, int hp, int cmpsc ,Sint16 *posninja, SDL_Rect *pose8,Sint16 *poshpup1,Sint16 *posninjaa);




