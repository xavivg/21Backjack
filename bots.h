#ifndef INC_21BLACKJACK_BOTS_H
#define INC_21BLACKJACK_BOTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bots.h"
#include "listaCarta.h"

typedef struct {
    char *nombre;
    int fichas;
    char caracter;
    int carta_maxima;
    ListaCarta cartas;
} Bots;

Bots BOTS_crea();
void BOTS_insertaNombre(Bots *b, char *nombre);
void BOTS_insertaFichas(Bots *b, int fichas);
void BOTS_insertaCaracter(Bots *b, char caracter);
void BOTS_insertaCartaMax(Bots *b, int cartaMax);
void BOTS_insertaCartas(Bots *b, ListaCarta cartas);
char * BOTS_consultaNombre(Bots b);
int BOTS_consultaFichas(Bots b);
char BOTS_consultaCaracter(Bots b);
int BOTS_consultaCartaMax(Bots b);
ListaCarta BOTS_consultaCartas(Bots b);

#endif //INC_21BLACKJACK_BOTS_H
