#include <stdio.h>
#include <stdlib.h>
#include "taquin.h"

/*
 * Initializer function
 */
Plateau *create_plat(){
  Plateau *p = (Plateau *)malloc(sizeof(Plateau));
  return p;
}

void free_plat(Plateau *p){
  free(p);
}

void display_plat(Plateau *p){
  int i, j;
  for (i=0; i < NB_COL; i++){
    for (j=0; j < NB_ROW; j++){
     printf("(%d,%d) ", (p->bloc)[i][j].row,(p->bloc)[i][j].col);
    }
    printf("\n");
  }
}

void swap_square(Plateau *p, Square *a, Square *b){

}

void random_swap(Plateau *p){
  int i, j;
  int temp_row, temp_col;
  int temp_i, temp_j;

  for (i=0; i < NB_ROW; i++){
    for (j=0; j < NB_COL; j++){
      if (((p->bloc)[i][j].row)==3 && ((p->bloc)[i][j].col)==3) {
        temp_i = i;
        temp_j = j;
      }
    }
  }
  i = temp_i;
  j = temp_j;

  int side = MLV_get_random_integer(0,2);
  if(side==0){
    if(i+1>=NB_ROW){
      temp_i = i-1;
    }
    else if(i-1<0){
      temp_i = i+1;
    } else {
      int vertical = MLV_get_random_integer(0,2);
      switch(vertical){
        case 0:
          temp_i = i-1;
          break;
        default:
          temp_i = i+1;
          break;
      }
    }
    temp_row = (p->bloc)[temp_i][j].row;
    temp_col = (p->bloc)[temp_i][j].col;
    (p->bloc)[temp_i][j].row = (p->bloc)[i][j].row;
    (p->bloc)[temp_i][j].col = (p->bloc)[i][j].col;
    (p->bloc)[i][j].row = temp_row;
    (p->bloc)[i][j].col = temp_col;
  } else {
    if(j+1>=NB_COL){
      temp_j = j-1;
    }
    else if(j-1<0){
      temp_j = j+1;
    } else {
      int horizontal = MLV_get_random_integer(0,2);
      switch(horizontal){
        case 0:
          temp_j = j-1;
        break;
        default:
          temp_j = j+1;
        break;
      }
    }

    temp_row = (p->bloc)[i][temp_j].row;
    temp_col = (p->bloc)[i][temp_j].col;
    (p->bloc)[i][temp_j].row = (p->bloc)[i][j].row;
    (p->bloc)[i][temp_j].col = (p->bloc)[i][j].col;
    (p->bloc)[i][j].row = temp_row;
    (p->bloc)[i][j].col = temp_col;
  }
}

void InitializationPlateau(Plateau *p){
  /* Initialize bloc number */
  int i, j;
  for (i = 0; i < NB_ROW; i++){
    for (j = 0; j < NB_COL; j++){
      ((p->bloc)[i][j].row) = i;
      ((p->bloc)[i][j].col) = j;
    }
  }

  /* Random the bloc */
  display_plat(p);
  printf("\n\n");
  int round = MLV_get_random_integer(1000, 2000);
  for(i=0; i<round; i++){
    random_swap(p);
  }
  display_plat(p);
}
