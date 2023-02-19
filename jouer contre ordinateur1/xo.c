/**
* @file xo.c
*/


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <time.h> /// Pour le hasard et pour l'attente
#include "xo.h"
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
//taille de la case est 100 taille de fenetre l enigme 300*300
#define X 'x'
#define O 'o'
#define VIDE '_'
char T[3][3];
char Joueur = 0,Ordinateur = 0;
SDL_Surface *ecran = NULL;
SDL_Surface *xp = NULL, *op = NULL;
SDL_Rect position;
TTF_Font *police = NULL;
SDL_Color couleur = {0, 0, 0}; //couleur noir
SDL_Color couleur2 = {255, 0, 0}; //couleur rouge
SDL_Surface *texte = NULL;
/**
* @brief To initialize the screen .
* @param ecran is the screen
*  @return Nothing
*/
void initialiser()
{
    ecran = SDL_SetVideoMode(300,300,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));    /// ecran blanc
    SDL_Flip(ecran);
}
/**
* @brief To initialize the matrix .
* @param  i and j are the parameters of the matrix
* @param  T is the matrix
*  @return Nothing

*/
void initialiserMatrice()
{
    int i = 0, j = 0;

    for (i = 0;i < 3;i++)
        for (j = 0;j < 3;j++)
        T[i][j] = VIDE; //chaine vide on va utliser l ecriture sur les cases
}
/**
* @brief To choose X or O .
* @param xp and op are the variables that represent  x and o
*  @return Nothing

*/
void choisirXO()
{ int continuer=1;
    SDL_Event event;

    TTF_Init();
    police = TTF_OpenFont("theme.ttf",50);
    xp = TTF_RenderText_Blended(police,"X",couleur); //variable pour "x"
    op = TTF_RenderText_Blended(police,"O",couleur2); // variable pour "o"
    texte = TTF_RenderText_Blended(police," X/O ? ",couleur); //choix de x ou o
    position.x = (ecran->w / 2) - (texte->w / 2);
    position.y = (ecran->h / 2) - (texte->h / 2);
    SDL_BlitSurface(texte,NULL,ecran,&position); // blit texte du choix en milieu
    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                exit(EXIT_SUCCESS);
            break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(EXIT_SUCCESS);
                    break;
                    case SDLK_x:  //si le choix est x le joueur recoit x et ordinateur o
                        Joueur = X;
                        Ordinateur = O;
                        return;
                    break;
                    case SDLK_o: //sinon le contraire
                        Joueur = O;
                        Ordinateur = X;
                        return;
                    break;
                    default: break;
                }
            break;
            default: break;
        }
    }
}
/**
* @brief To play the game
* @param  continuer is used for the loop of the game
*  @return Nothing

*/
void jouer()
{ int continuer =1;
    while (continuer)
    {
        jouerJoueur();
       ecranblanc();
        afficherEcran();
jouerOrdinateur();
        ecranblanc();
        afficherEcran();
      
          
    }
    ecranblanc();
   
  
    SDL_Flip(ecran);
    pause();
}
/**
* @brief function of the player
* @param continuer is used for the loop of the game
* @param x and y are used to limit the position of the mouse curser.
*  @return Nothing

*/
void jouerJoueur() //concernant le joueur
{
    SDL_Event event;
    int continuer = 1;
    int x = 0, y = 0;

    while (continuer == 1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                exit(EXIT_FAILURE);
            break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(EXIT_FAILURE);
                    break;
                    default: break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        x = event.button.x / 100; //limiter dans la casse
                        y = event.button.y / 100;
                        if (T[y][x] == VIDE) //si il n y rien tapper donc 0 
                        {
                            T[y][x] = Joueur;
                            continuer = 0;
                    
                        }
                    break;
                    default: break;
                }
            break;
            default: break;
        }
    }
}

/**
* @brief To show the screen.
* @param image is the background of the game
* @return Nothing
*/

void afficherEcran()
{ 
SDL_Surface *image = NULL;
 image = IMG_Load("fond.png"); 
position.x=0;
position.y=0;
SDL_BlitSurface(image,NULL,ecran,&position); //load du background
    int i = 0, j = 0;
  

  for (i = 0;i < 3;i++)
        for (j = 0;j < 3;j++)
        {
            position.x = j * 100 + 10; //+10 le petit espace noir entre les casses //ligne noir
            position.y = i * 100 + 10;
            if (T[i][j] == X)
            {
                SDL_BlitSurface(xp,NULL,ecran,&position); // si on clique x donc blit x
            }
            else if (T[i][j] == O)
            {
                SDL_BlitSurface(op,NULL,ecran,&position); // sinon o 
            }
        }
    SDL_Flip(ecran);
}
/**
* @brief To erase the screen
* @param ecran is the screen 
* @return Nothing
*/
void ecranblanc()
{
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); //remplir l écran avec le blanc   
    SDL_Flip(ecran); //refraichissement
}
/**
* @brief function of the computer 
* @param T is the matrix
* @return Nothing
*/

void jouerOrdinateur()
{
    int x = 0, y = 0; //matrice

    srand(time(NULL)); // aleatoire lol mara yhot o wla x fi position aleatoire
    do
    {
        x = (int) rand() % 3;
        y = (int) rand() % 3;
    }
    while (T[x][y] != VIDE);
    T[x][y] = Ordinateur;
   
}
/**
* @brief To pause the program.
* @return Nothing
*/
void pause()
{
     int continuer = 1;
    SDL_Event event;

    while (continuer == 1)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer = 0;
            break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                    break;
                    default:
                    break;
                }
            break;
            default:
            break;
        }
    }
}
/**
* @brief To free the memory
* @param ecran is the screen 
* @return Nothing
*/
void quitter()
{
   

    SDL_FreeSurface(ecran);
    SDL_FreeSurface(xp);
    SDL_FreeSurface(op);
}

