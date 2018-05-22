#ifndef INC_21BACKJACK_JUGADOR_H
#define INC_21BACKJACK_JUGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCarta.h"

typedef struct {
    char *nombre;
    int fichas;
    int manos_ganadas;
    int manos_perdidas;
    int *fichas_partida;
    ListaCarta cartas;
} Jugador;

Jugador JUGADOR_crea();

#endif //INC_21BACKJACK_JUGADOR_H
