#include "gestionFicheros.h"
#include "jugador.h"

Jugador cargaJugador() {
    FILE *f;
    f = fopen("fichero_usuario.bj", "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
        Jugador j;

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

        int partidas =
                JUGADOR_consultaManosGanadas(j) + JUGADOR_consultaManosPerdidas(j) + JUGADOR_consultaManosEmpatadas(j);
        int fichas_partida;

        //REVISAR ERROR (segmentation fault)
        for (int i = 0; i < partidas; i++) {
            fscanf(f, "%d", &fichas_partida);
            JUGADOR_insertaFichasPartida(&j, fichas_partida);
            printf("%d", JUGADOR_consultaFichasPartida(j, i));
        }

        fclose(f);
        return j;
    }
}

Bots *cargaBots() {
    FILE *f;
    f = fopen("fichero_bots.bj", "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
        int numBots;
        fscanf(f, "%d", &numBots);
        Bots bots[numBots];
        printf("%d\n", numBots);

        char aux;
        fscanf(f, "%c", &aux);

        char *nombre = malloc(sizeof(char) * 1024);
        fgets(nombre, 25, f);
        strtok(nombre, "\n");
        BOTS_insertaNombre(&bots[0], nombre);
        printf("%s\n", BOTS_consultaNombre(bots[0]));

        int i = 0;
        while (!feof(f)) {
            int fichas;
            fscanf(f, "%d", &fichas);
            BOTS_insertaFichas(&bots[i], fichas);
            printf("%d\n", BOTS_consultaFichas(bots[i]));

            char *caracter = malloc(sizeof(char) * 1024);
            char car;
            fscanf(f, "%s", caracter);
            if (strcmp(caracter, "Fuerte") == 0) {
                car = 'f';
            } else if (strcmp(caracter, "Debil") == 0) {
                car = 'd';
            } else if (strcmp(caracter, "Normal") == 0) {
                car = 'n';
            }
            BOTS_insertaCaracter(&bots[i], car);
            printf("%c\n", BOTS_consultaCaracter(bots[i]));

            int cartaMax;
            fscanf(f, "%d", &cartaMax);
            BOTS_insertaCartaMax(&bots[i], cartaMax);
            printf("%d\n", BOTS_consultaCartaMax(bots[i]));

            i++;

            fscanf(f, "%c", &aux);
            nombre = malloc(sizeof(char) * 1024);
            fgets(nombre, 25, f);
            strtok(nombre, "\n");
            BOTS_insertaNombre(&bots[i], nombre);
            printf("%s\n", BOTS_consultaNombre(bots[i]));
        }

        return bots;
    }

    fclose(f);
}
