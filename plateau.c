/* Created by isabelle-zhan on 05/06/25. */
#include "plateau.h"

#include <stdlib.h>
#include <stdio.h>

/* Initializer function */
Square *create_square(int row, int col){
    Square *s = (Square *)malloc(sizeof(Square));
    s->row = row;
    s->col = col;
    return s;
}
void free_square(Square *s){
    free(s);
}
void display_square(Square *s){
    printf("(%i,%i)\n",s->row,s->col);
}

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
            printf("(%d,%d) ",(p->bloc)[i][j].col, (p->bloc)[i][j].row);
        }
        printf("\n");
    }
}

Square* pos_black(Plateau *p){
    int i,j;
    for (i=0; i < NB_ROW; i++){
        for (j=0; j < NB_COL; j++){
            if (((p->bloc)[i][j].row) == NB_ROW-1 && ((p->bloc)[i][j].col) == NB_COL-1) {
                return create_square(j,i);
            }
        }
    }
    return NULL;
}


int near_black(Plateau *p,Square *black, Square *click){
    printf("black : ");
    display_square(black);
    printf("click : ");
    display_square(click);
    return ((black->row == click->row+1 || black->row == click->row-1) && black->col == click->col)
        || ((black->col == click->col+1 || black->col == click->col-1) && black->row == click->row);
}