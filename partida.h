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
} Partida;

Partida PARTIDA_crea(Baraja b);
char PARTIDA_add_carta_crupier(Partida *p);
void PARTIDA_show_carta_crupier(Partida *p, int t);// si t = 0; nomes mostra 1 carta, si t es 1, es mostren totes
char PARTIDA_add_carta_jugador(Partida *p);
char PARTIDA_add_carta_bots(Partida *p, Bot *bot);
void PARTIDA_show_carta_jugador(Partida *p, int t);// si t = 0; nomes mostra 1 carta, si t es 1, es mostren totes
void PARTIDA_show_carta_bots(Partida *p, Bot *bot);
int PARTIDA_apuesta_jugador(Partida *p);
int PARTIDA_apuesta_bots(Bot *bot);
int PARTIDA_equivalencia(char carta, int vtotal);
int PARTIDA_conversor_jugador(Partida *p);
int PARTIDA_conversor_crupier(Partida *p);
int PARTIDA_conversor_bots(Partida *p, Bot *bot);
void PARTIDA_accion_jugador();
char PARTIDA_get_nombre_jugador(Partida *p);
//int PARTIDA_get_nFichas(Partida *p);
void PARTIDA_carga_jugador(Partida *p);
void PARTIDA_turno_crupier(Partida *p, int num_cartasC, int num_cartasJ);
void PARTIDA_turno_bots(Partida *p, Bot *arrayBots, int num_cartasC, int num_cartasJ);
void PARTIDA_comprobacion(Partida *p, Bot *arrayBots, int *apuestaB, int *num_cartasB, int num_cartasC, int num_cartasJ, int apuestaJ);
#endif //INC_21BACKJACK_PARTIDA_H
