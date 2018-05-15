#ifndef INC_21BACKJACK_BARAJA_H
#define INC_21BACKJACK_BARAJA_H

#include <stdio.h>

#define MAX 52

typedef struct{
    int elementos[MAX]; //Per decidir si serà array de char o array de int
    int cuantos;
}Baraja;

Baraja BARAJA_crea(int numero);//es pasa el numero de barajas 1-4 para hacer la mezcla
void BARAJA_push(Baraja *p, int elemento);
//void BARAJA_pop(Baraja *p);
//void BARAJA_top(Baraja p);
//int BARAJA_vacia(Baraja p);
//void BARAJA_destruye(Baraja *p);


#endif //INC_21BACKJACK_BARAJA_H
