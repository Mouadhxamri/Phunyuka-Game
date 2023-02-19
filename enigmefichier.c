#include "enigmefihier.h"

int enigme1(SDL_Surface **ecran,int *victory)
{ 
	enigme  e;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
    	srand(time(NULL));
	init_enigme(&e);
	
	 while (run)
	 {
	     running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
      generate_afficher ( *ecran  , image ,&e,&alea) ;
			s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
      	while(running){

				 afficher_resultat (*ecran,s,r,&e) ;
					if (r==s)
					(*victory)=1;
else
(*victory)=0;
			      	 SDL_WaitEvent(&event);
					running=0;
					run=0;
                    
                      } 	
   }
	return 0;
}
