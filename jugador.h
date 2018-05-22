#ifndef INC_21BACKJACK_JUGADOR_H
#define INC_21BACKJACK_JUGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaFichas.h"

typedef struct {
    char *nombre;
    int fichas;
    int manos_ganadas;
    int manos_perdidas;
    int manos_empatadas;
    ListaFichas fichas_partida;
} Jugador;

Jugador JUGADOR_crea();

#endif //INC_21BLACKJACK_JUGADOR_H
