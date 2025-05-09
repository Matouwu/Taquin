#include <stdio.h>

#include "taquin.h"
#include "graphic.h"


int main(){
    Plateau *p = create_plat();

    /* Create the window*/
    MLV_create_window("Jeu de Taquin","TAQUIN", WINDOW_SIZE, WINDOW_SIZE);
    MLV_actualise_window();

    /* Game starter pack */
    InitializationPlateau(p);
    graphic_init(p);

    /* Game loop */
    int x, y;
    while(1){
      MLV_wait_mouse(&x, &y);
      printf("%i\n",near_black(p,&x, &y));
      if(near_black(p,&x, &y)){
        Square *a = create_square();
      }

    }







    MLV_free_window();
    return EXIT_SUCCESS;
}