#include <stdio.h>
#include "plateau.h"
#include "taquin.h"
#include "graphic.h"


int main(){
    Plateau *p = create_plat();

    /* Create the window */
    MLV_create_window("TaquIsa Game","TAQUISA", WINDOW_SIZE, WINDOW_SIZE);
    MLV_actualise_window();

    /* Game starter pack */
    InitializationPlateau(p);
    graphic_init(p);

    /* Game loop */
    Square *black = pos_black(p);
    int x, y;
    while(!end_game(p)){
        MLV_wait_mouse(&x, &y);
        x = x/IMG_PART;
        y = y/IMG_PART;

        Square *click = create_square(x, y);
        int near = near_black(black,click);
        if(near){
            swap_square(p, black, click);
            printf("After swap :\n");
            display_plat(p);
            graphic_init(p);
            MLV_actualise_window();
        }
    }
    printf("==================================================\n");
    printf("========================FINI======================\n");
    printf("==================================================\n");
    graphic_win();


    free_plat(p);
    MLV_free_window();
    return EXIT_SUCCESS;
}