#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <MLV/MLV_all.h>
#include "taquin.h"

#define IMAGE MLV_load_image("data/totoro.jpg");


void graphic_init(Plateau *p);
void graphic_win();

#endif /*GRAPHIC_H*/
