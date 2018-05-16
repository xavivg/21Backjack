#include "jugador.h"

Jugador JUGADOR_crea() {
    Jugador j;
    return j;
}

void JUGADOR_elimina(Jugador j) {
    free(j);
}