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

/*void JUGADOR_elimina(Jugador j) {
    free(j);
}*/