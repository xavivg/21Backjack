#ifndef INC_21BACKJACK_BARAJA_H
#define INC_21BACKJACK_BARAJA_H

#include <stdio.h>
#include "listaCarta.h"
#define MAX 208

typedef struct{
    char cartas[MAX];
    int nCartas;
}Baraja;

Baraja BARAJA_crea(int numero);

void BARAJA_push(Baraja *b, char carta);
//void BARAJA_pop(Baraja *p);
//void BARAJA_top(Baraja p);
//int BARAJA_vacia(Baraja p);
void BARAJA_destruye(Baraja *b);
char BARAJA_carta(Baraja *b);


#endif //INC_21BACKJACK_BARAJA_H
