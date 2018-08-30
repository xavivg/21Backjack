#include "jugador.h"

Jugador JUGADOR_crea() {
   /* Jugador j;
    j.fichas = 0;
    j.nombre = "";
    j.cartas = LISTACARTA_crea();
    j.cartas = LISTACARTA_vesInicio(j.cartas);
    j.fichas_partida = LISTAFICHAS_crea();
    j.fichas_partida = LISTAFICHAS_vesInicio(j.fichas_partida);
    j.manos_ganadas = 0;
    j.manos_perdidas = 0;
    j.manos_empatadas = 0;
    return j;*/

    FILE *f;
    f = fopen("fichero_usuario.bj", "rw");

    if (f == NULL) {
        printf("\nError al obrir el fitxer de l'usuari...\n");
    } else {
        Jugador j;
        char aux;

        char *nombre = malloc(sizeof(char) * 1024);
        fgets(nombre, 25, f);
        strtok(nombre, "\n");
        j.nombre = nombre;
        printf(" Hola %s\n", JUGADOR_consultaNombre(j));

        int fichas;
        fscanf(f, "%d", &fichas);
        j.fichas = fichas;
        printf(" tens = %d fitxes \n", JUGADOR_consultaFichas(j));

        int manos_ganadas, manos_perdidas, manos_empatadas;


        fscanf(f, "%d", &manos_ganadas);
        j.manos_ganadas = manos_ganadas;


        fscanf(f, "%d", &manos_perdidas);
        j.manos_perdidas = manos_perdidas;
        fscanf(f, "%d", &manos_empatadas);
        j.manos_empatadas = manos_empatadas;


        int partidas = j.manos_ganadas + j.manos_perdidas + j.manos_empatadas;
        int fichas_partida;

        //REVISAR ERROR (segmentation fault)
        ListaCarta x  = LISTACARTA_crea();
        j.cartas = x;
        ListaFichas a = LISTAFICHAS_crea();

        printf(" Numero de partides realitzades : %d \n", partidas);
          for (int i = 0; i < partidas; i++) {
               fscanf(f, "%d", &fichas_partida);
               LISTAFICHAS_inserta(a, fichas_partida);
           }
        j.fichas_partida = a;
        fclose(f);
        return j;
    }






}

void JUGADOR_insertaNombre(Jugador *j, char *nombre) {
    (*j).nombre = nombre;
}

void JUGADOR_insertaFichas(Jugador *j, int fichas) {
    (*j).fichas = fichas;
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
      j->fichas_partida = LISTAFICHAS_inserta((*j).fichas_partida, fichasPartida);
      j->fichas_partida = LISTAFICHAS_avanza((*j).fichas_partida);
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