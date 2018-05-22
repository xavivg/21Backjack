#include "jugador.h"
#include "crupier.h"
#include "baraja.h"
#include "bots.h"

#ifndef INC_21BACKJACK_PARTIDA_H
#define INC_21BACKJACK_PARTIDA_H

typedef struct {
    Jugador jugador;
    Crupier crupier;
    Baraja baraja;
    Bots bots;
}Partida;

Partida PARTIDA_crea(Baraja b);
void PARTIDA_addCarta(ListaCarta *cartas, Baraja *b);
#endif //INC_21BACKJACK_PARTIDA_H
