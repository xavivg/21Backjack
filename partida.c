
#include "partida.h"

Partida PARTIDA_crea(Baraja b){
    Partida p;
    p.jugador = JUGADOR_crea();
    p.crupier = CRUPIER_crea();
    p.bots = BOTS_crea();
    p.baraja = b;
    return p;
}

