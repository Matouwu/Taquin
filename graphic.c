#include <stdio.h>
#include "graphic.h"

#define IMG_PART (WINDOW_SIZE/NB_COL)


void graphic_init(Plateau *p){
    MLV_Image* img = MLV_load_image("data/totoro.jpg");
    MLV_resize_image(img,WINDOW_SIZE,WINDOW_SIZE);

    int i,j;
    for(i=0; i < NB_ROW ; i++){
      for(j=0; j < NB_COL; j++){
        MLV_draw_partial_image(img,IMG_PART*((p->bloc)[i][j].row),IMG_PART*((p->bloc)[i][j].col),IMG_PART-4,IMG_PART-4,j*IMG_PART+4,i*IMG_PART+4);
        if((p->bloc)[i][j].row == 3 && (p->bloc)[i][j].col == 3){
          MLV_draw_filled_rectangle(j*IMG_PART+4, i*IMG_PART+4, IMG_PART-4, IMG_PART-4, MLV_COLOR_BLACK);
        }
      }
    }
    MLV_actualise_window();
}
Square pos_black(Plateau *p){
  Square black;
  int i,j;
  for (i=0; i < NB_ROW; i++){
    for (j=0; j < NB_COL; j++){
      if (((p->bloc)[i][j].row)==3 && ((p->bloc)[i][j].col)==3) {
        black.row = i;
        black.col = j;
      }
    }
  }
  return black;
}


int near_black(Plateau *p,int *x, int *y){
  *x=*x/IMG_PART;
  *y=*y/IMG_PART;
  return ((p->bloc)[*y+1][*x].row==3 && (p->bloc)[*y+1][*x].col==3)
         || ((p->bloc)[*y-1][*x].row==3 && (p->bloc)[*y-1][*x].col==3)
         || ((p->bloc)[*y][*x+1].row==3 && (p->bloc)[*y][*x+1].col==3)
         || ((p->bloc)[*y][*x-1].row==3 && (p->bloc)[*y][*x-1].col==3);
}
