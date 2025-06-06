#include <stdio.h>
#include "graphic.h"


void graphic_init(Plateau *p){
    MLV_Image* img = MLV_load_image("data/totoro.jpg");
    MLV_resize_image(img,WINDOW_SIZE,WINDOW_SIZE);

    int i,j;
    for(i=0; i < NB_ROW ; i++){
      for(j=0; j < NB_COL; j++){
        MLV_draw_partial_image(img,IMG_PART*((p->bloc)[i][j].col),IMG_PART*((p->bloc)[i][j].row),IMG_PART-4,IMG_PART-4,j*IMG_PART+4,i*IMG_PART+4);
        if((p->bloc)[i][j].row == 3 && (p->bloc)[i][j].col == 3){
          MLV_draw_filled_rectangle(j*IMG_PART+4, i*IMG_PART+4, IMG_PART-4, IMG_PART-4, MLV_COLOR_BLACK);
        }
      }
    }
    MLV_actualise_window();
}

void graphic_win() {
  MLV_Image* frames[20];
  char filename[50];
  int i;

  /* Load animation pic + font*/
  for (i = 0; i < 19; i++) {
    sprintf(filename, "data/party-%d.png", i + 1);
    frames[i] = MLV_load_image(filename);
    if (frames[i] == NULL) {
      fprintf(stderr, "Erreur de chargement de %s\n", filename);
      return;
    }
    MLV_resize_image_with_proportions(frames[i], WINDOW_SIZE/3, WINDOW_SIZE/3);
  }
  MLV_Font* font = MLV_load_font("data/Monday Darling.otf", 100);
  if (!font) {
    fprintf(stderr, "Erreur de chargement de la police.\n");
    return;
  }

  /* Animation player */
  while (1) {
    for(i = 0; i < 19; i++) {
      MLV_clear_window(MLV_COLOR_ALICE_BLUE);
      MLV_draw_image(frames[i], 0, 2*WINDOW_SIZE/3);
      MLV_draw_text_with_font (WINDOW_SIZE/4, WINDOW_SIZE/3,"!!! SUCCESSSSS !!!", font, MLV_COLOR_RED);
      MLV_actualise_window();
      MLV_wait_milliseconds(50);
    }
  }
}
