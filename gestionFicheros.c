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

        fgets(j.nombre, 25, f);

        strtok(j.nombre, "\n");
        fscanf(f, "%d", &j.fichas);
        fscanf(f, "%d", &j.manos_ganadas);
        fscanf(f, "%d", &j.manos_perdidas);
        fscanf(f, "%d", &j.manos_empatadas);

        printf("%s\n", j.nombre);
        printf("%d\n", j.fichas);
        printf("%d\n", j.manos_ganadas);
        printf("%d\n", j.manos_perdidas);
        printf("%d\n", j.manos_empatadas);

        int partidas = j.manos_ganadas + j.manos_perdidas + j.manos_empatadas;
        int fichas;

        for (int i = 0; i < partidas; ++i) {
            fscanf(f, "%d", &fichas);
            LISTAFICHAS_inserta(j.fichas_partida, fichas);
            printf("%d\n", LISTAFICHAS_consulta(j.fichas_partida));
        }

        fclose(f);
    }
}