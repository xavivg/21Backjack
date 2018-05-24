#include "gestionFicheros.h"
#include "jugador.h"

void cargaJugador() {
    FILE *f;
    f = fopen("fichero_usuario.bj", "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
        Jugador j;
        char aux;

        char *nombre = malloc(sizeof(char) * 1024);
        fgets(nombre, 25, f);
        strtok(nombre, "\n");
        JUGADOR_insertaNombre(&j, nombre);
        printf("%s\n", JUGADOR_consultaNombre(j));

        int fichas;
        fscanf(f, "%d", &fichas);
        JUGADOR_insertaFichas(&j, fichas);
        printf("%d\n", JUGADOR_consultaFichas(j));

        int manos_ganadas, manos_perdidas, manos_empatadas;
        fscanf(f, "%d", &manos_ganadas);
        JUGADOR_insertaManosGanadas(&j, manos_ganadas);
        printf("%d\n", JUGADOR_consultaManosGanadas(j));
        fscanf(f, "%d", &manos_perdidas);
        JUGADOR_insertaManosPerdidas(&j, manos_perdidas);
        printf("%d\n", JUGADOR_consultaManosPerdidas(j));
        fscanf(f, "%d", &manos_empatadas);
        JUGADOR_insertaManosEmpatadas(&j, manos_empatadas);
        printf("%d\n", JUGADOR_consultaManosEmpatadas(j));

        int partidas = j.manos_ganadas + j.manos_perdidas + j.manos_empatadas;
        int fichas_partida;

        //REVISAR ERROR (segmentation fault)
        for (int i = 0; i < partidas; i++) {
            fscanf(f, "%d", &fichas_partida);
            JUGADOR_insertaFichasPartida(&j, fichas_partida);
            printf("%d", JUGADOR_consultaFichasPartida(j, i));
        }

        fclose(f);
    }
}
