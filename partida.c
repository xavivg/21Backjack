#include <stdio.h>
#include "partida.h"
#include "baraja.h"
#include "listaCarta.h"

Partida PARTIDA_crea(Baraja b){
    Partida p;
    p.jugador = JUGADOR_crea();
    p.crupier = CRUPIER_crea();
    p.bots = BOTS_crea();
    p.baraja = b;
    return p;
}
void PARTIDA_addCarta(ListaCarta *cartas, Baraja *b){
    char carta  = BARAJA_carta(b);

    *cartas = LISTACARTA_inserta(*cartas, carta);
}
