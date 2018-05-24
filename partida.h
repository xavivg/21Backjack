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
    int nBots;
    Bots *bots;
}Partida;

Partida PARTIDA_crea(Baraja b);
char PARTIDA_add_carta_crupier(Partida *p);
void PARTIDA_show_carta_crupier(Partida *p, int t);// si t = 0; nomes mostra 1 carta, si t es 1, es mostren totes
char PARTIDA_add_carta_jugador(Partida *p);
void PARTIDA_show_carta_jugador(Partida *p, int t);// si t = 0; nomes mostra 1 carta, si t es 1, es mostren totes
void PARTIDA_apuesta_jugador(Partida *p);
void PARTIDA_accion_jugador();
#endif //INC_21BACKJACK_PARTIDA_H
