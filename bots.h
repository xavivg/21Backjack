//
// Created by xaviv on 22/05/2018.
//

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
} Bot;

void BOT_crea(Bot *arrayBOT);
int BOT_numBots();
void BOT_insertaNombre(Bot *b, char *nombre);
void BOT_insertaFichas(Bot *b, int fichas);
void BOT_insertaCaracter(Bot *b, char caracter);
void BOT_insertaCartaMax(Bot *b, int cartaMax);
void BOT_insertaCartas(Bot *b, ListaCarta cartas);
char * BOT_consultaNombre(Bot b);
int BOT_consultaFichas(Bot b);
char BOT_consultaCaracter(Bot b);
int BOT_consultaCartaMax(Bot b);
ListaCarta BOT_consultaCartas(Bot b);
#endif //INC_21BLACKJACK_BOTS_H
