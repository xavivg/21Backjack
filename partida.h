#ifndef INC_21BACKJACK_PARTIDA_H
#define INC_21BACKJACK_PARTIDA_H
#include <stdio.h>
#include "jugador.h"
#include "baraja.h"
#include "bots.h"
#include "listaCarta.h"
#include "crupier.h"

typedef struct {
    Jugador jugador;
    Crupier crupier;
    Baraja baraja;
    Bots bots;
}Partida;

Partida PARTIDA_crea(Baraja b);
void PARTIDA_addCarta(Partida *p, Baraja *b);
#endif //INC_21BACKJACK_PARTIDA_H
