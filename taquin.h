#ifndef TAQUIN_H
#define TAQUIN_H

#include <MLV/MLV_all.h>

#define NB_COL 4     /* colonne */
#define NB_ROW 4     /* ligne */

typedef struct square {
    int row;
    int col;
} Square;

typedef struct plateau{
    Square bloc[NB_COL][NB_ROW];
} Plateau;

Plateau *create_plat();
void free_plat(Plateau *p);
void InitializationPlateau(Plateau *p);

#endif /*TAQUIN_H*/
