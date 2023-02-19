#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "xo.h"
/**
* @file main.c
* @brief playing xo
* @author wiem trifi
* @version 0.1
* @date juin 01, 2019
*
* playing xo with computer
*
*/

void main(void)
{
    initialiser();
    initialiserMatrice();
    choisirXO();
    ecranblanc();
    afficherEcran();
    jouer();

}
