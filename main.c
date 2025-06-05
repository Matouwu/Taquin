#include <stdio.h>
#include "plateau.h"
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

    Square *black = pos_black(p);


    /* Game loop */
    int x, y;
    while(1){
        MLV_wait_mouse(&x, &y);
        x = x/IMG_PART;
        y = y/IMG_PART;
        Square *click = create_square(x, y);
        int near = near_black(p,black,click);
        printf("near = %d\n",near);
        printf("x= %d, y=%d\n", x, y);
        if(near){
            swap_square(p, click, black);
            printf("After swap :\n");
            display_plat(p);
        }
    }



    free_plat(p);
    MLV_free_window();
    return EXIT_SUCCESS;
}