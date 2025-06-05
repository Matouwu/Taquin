/*
// Created by isabelle-zhan on 05/06/25.
*/

#ifndef PLATEAU_H
#define PLATEAU_H

#define WINDOW_SIZE 512*2
#define IMG_PART (WINDOW_SIZE/NB_COL)

#define NB_COL 4     /* colonne */
#define NB_ROW 4     /* ligne */

typedef struct square {
    int row;
    int col;
} Square;
typedef struct plateau{
    Square bloc[NB_COL][NB_ROW];
} Plateau;

Square *create_square(int row, int col);
void free_square(Square *s);
void display_square(Square *s);

Plateau *create_plat();
void free_plat(Plateau *p);
void display_plat(Plateau *p);

Square* pos_black(Plateau *p);
int near_black(Plateau *p,Square *black, Square *click);

#endif /*PLATEAU_H*/
