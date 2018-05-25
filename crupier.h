#ifndef INC_21BACKJACK_CRUPIER_H
#define INC_21BACKJACK_CRUPIER_H

#include "listaCarta.h"

typedef struct {
    ListaCarta cartas;
}Crupier;

Crupier CRUPIER_crea();
void * CRUPIER_add_carta(Crupier *c, char carta);
ListaCarta CRUPIER_get_cartas(Crupier *crupier);
#endif //INC_21BACKJACK_CRUPIER_H