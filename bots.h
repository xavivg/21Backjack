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
    int nBots;
    char nombre;
    int fichas;
    char caracter;
    int carta_maxima;
    int manos_ganadas;
    int manos_perdidas;
    int *fichas_partida;
    ListaCarta cartas;
} Bots;

Bots BOTS_crea();


#endif //INC_21BLACKJACK_BOTS_H
