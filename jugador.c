#include "jugador.h"

Jugador JUGADOR_crea() {
    Jugador j;
    j.fichas = 0;
    j.nombre = "";
    j.cartas = LISTACARTA_crea();
    j.cartas = LISTACARTA_vesInicio(j.cartas);
    j.fichas_partida = LISTAFICHAS_crea();
    j.fichas_partida = LISTAFICHAS_vesInicio(j.fichas_partida);
    j.manos_ganadas = 0;
    j.manos_perdidas = 0;
    j.manos_empatadas = 0;
    return j;
}

void JUGADOR_insertaNombre(Jugador *j, char *nombre) {
    (*j).nombre = nombre;
}

void JUGADOR_insertaFichas(Jugador *j, int fichas) {
    (*j).fichas = fichas;
    printf("\n te quedan: %d\n",fichas);
}

void JUGADOR_insertaManosGanadas(Jugador *j, int manosGanadas) {
    (*j).manos_ganadas = manosGanadas;
}

void JUGADOR_insertaManosPerdidas(Jugador *j, int manosPerdidas) {
    (*j).manos_perdidas = manosPerdidas;
}

void JUGADOR_insertaManosEmpatadas(Jugador *j, int manosEmpatadas) {
    (*j).manos_empatadas = manosEmpatadas;
}

void JUGADOR_insertaFichasPartida(Jugador *j, int fichasPartida) {
    (*j).fichas_partida = LISTAFICHAS_inserta((*j).fichas_partida, fichasPartida);
    (*j).fichas_partida = LISTAFICHAS_avanza((*j).fichas_partida);
}

char * JUGADOR_consultaNombre(Jugador j) {
    return j.nombre;
}

int JUGADOR_consultaFichas(Jugador j) {
    return j.fichas;
}

int JUGADOR_consultaManosGanadas(Jugador j) {
    return j.manos_ganadas;
}

int JUGADOR_consultaManosPerdidas(Jugador j) {
    return j.manos_perdidas;
}

int JUGADOR_consultaManosEmpatadas(Jugador j) {
    return j.manos_empatadas;
}

int JUGADOR_consultaFichasPartida(Jugador j, int numPartida) {
    j.fichas_partida = LISTAFICHAS_vesInicio(j.fichas_partida);
    for (int i = 0; i < numPartida; i++) {
        j.fichas_partida = LISTAFICHAS_avanza(j.fichas_partida);
    }
    int fichas = LISTAFICHAS_consulta(j.fichas_partida);
    return fichas;
}

void * JUGADOR_add_carta(Jugador *jugador, char carta){
    jugador->cartas = LISTACARTA_inserta(jugador->cartas, carta);
}
ListaCarta JUGADOR_get_cartas(Jugador *jugador){
    return jugador->cartas;
}
/*void JUGADOR_elimina(Jugador j) {
    free(j);
}*/