#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <MLV/MLV_all.h>
#include "taquin.h"


#define WINDOW_SIZE 512*2


void graphic_init(Plateau *p);
Square pos_black(Plateau *p);
int near_black(Plateau *p,int *x, int *y);

#endif /*GRAPHIC_H*/
