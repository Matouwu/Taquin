#include <stdio.h>
#include "taquin.h"


void random_swap(Plateau *p){
    int round = MLV_get_random_integer(1000, 2000);
    int i;
    Square *black = pos_black(p);
    for(i=0; i<2; i++){
      Square *temp;
      int side = MLV_get_random_integer(0,4);
      switch (side){
        case 0: /* top */
          if( black->row-1 >= 0 ){
            temp = create_square(black->row-1, black->col);
            swap_square(p, black, temp);
          }
          break;
        case 1:
          if( black->col+1 < NB_COL ){
            temp = create_square(black->row, black->col+1);
            swap_square(p, black, temp);
          }
          break;
        case 2:
          if( black->row+1 < NB_ROW ){
            temp = create_square(black->row+1, black->col);
            swap_square(p, black, temp);
          }
          break;
        case 3:
          if( black->col-1 >= 0 ){
            temp = create_square(black->row, black->col-1);
            swap_square(p, black, temp);
          }
          break;
        default:
          printf("Illegal side\n");
      }
    }
}

void InitializationPlateau(Plateau *p){
  /* Initialize bloc number */
  int i, j;
  for (i = 0; i < NB_ROW; i++){
    for (j = 0; j < NB_COL; j++){
      ((p->bloc)[i][j].col) = j;
      ((p->bloc)[i][j].row) = i;
    }
  }

  /* Random the bloc */
  printf("===== Initiale Plateau :\n");
  display_plat(p);
  printf("\n\n");
  random_swap(p);
  printf("===== Change Plateau :\n");
  display_plat(p);
}


/*
 * Applicative function
 */
void swap_square(Plateau *p, Square *a, Square *b){
    int temp_row = (p->bloc)[a->row][a->col].row;
    int temp_col = (p->bloc)[a->row][a->col].col;
    (p->bloc)[a->row][a->col].row = (p->bloc)[b->row][b->col].row;
    (p->bloc)[a->row][a->col].col = (p->bloc)[b->row][b->col].col;
    (p->bloc)[b->row][b->col].row = temp_row;
    (p->bloc)[b->row][b->col].col = temp_col;

    a->col = b->col;
    a->row = b->row;
}

int end_game(Plateau *p) {
  int i, j;
  for (i = 0; i < NB_ROW; i++) {
    for (j = 0; j < NB_COL; j++) {
      if (p->bloc[i][j].col != j || p->bloc[i][j].row != i) {
        return 0;
      }
    }
  }
  return 1;
}

