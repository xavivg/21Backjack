#ifndef INC_21BACKJACK_JUGADOR_H
#define INC_21BACKJACK_JUGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCarta.h"
#include "listaFichas.h"

typedef struct {
    char *nombre;
    int fichas;
    int manos_ganadas;
    int manos_perdidas;
    int manos_empatadas;
    ListaFichas fichas_partida;
    ListaCarta cartas;
} Jugador;

Jugador JUGADOR_crea();
void JUGADOR_insertaNombre(Jugador *j, char *nombre);
void JUGADOR_insertaFichas(Jugador *j, int fichas);
void JUGADOR_insertaManosGanadas(Jugador *j, int manosGanadas);
void JUGADOR_insertaManosPerdidas(Jugador *j, int manosPerdidas);
void JUGADOR_insertaManosEmpatadas(Jugador *j, int manosEmpatadas);
void JUGADOR_insertaFichasPartida(Jugador *j, int fichasPartida);
char * JUGADOR_consultaNombre(Jugador j);
int JUGADOR_consultaFichas(Jugador j);
int JUGADOR_consultaManosGanadas(Jugador j);
int JUGADOR_consultaManosPerdidas(Jugador j);
int JUGADOR_consultaManosEmpatadas(Jugador j);
int JUGADOR_consultaFichasPartida(Jugador j, int numPartida);

#endif //INC_21BLACKJACK_JUGADOR_H
