#ifndef INC_21BACKJACK_CRUPIER_H
#define INC_21BACKJACK_CRUPIER_H

#include "listaCarta.h"
#include "partida.h"

typedef struct {
    ListaCarta cartas;
}Crupier;

Crupier CRUPIER_crea();
void CRUPIER_addCarta(Partida *p, Baraja *b);
char CRUPIER_muestraCarta(Partida *p);
#endif //INC_21BACKJACK_CRUPIER_H
