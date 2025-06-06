#ifndef TAQUIN_H
#define TAQUIN_H

#include <MLV/MLV_all.h>
#include "plateau.h"

void InitializationPlateau(Plateau *p);
void swap_square(Plateau *p, Square *a, Square *b);
int end_game(Plateau *p);



#endif /*TAQUIN_H*/
