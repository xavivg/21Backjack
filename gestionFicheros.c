#include "gestionFicheros.h"

void cargaJugador() {
    FILE *f;
    f = fopen("fichero_usuario.bj", "r");

    if (f == NULL ) {
        printf("\nError en obrir fitxer...\n");
    } else {
        Jugador j;
        char aux;
        fgets(j.nombre, 25, f);
        while (!feof(f)) {
            strtok(j.nombre, "\n");
            fscanf(f, "%d", &j.fichas);
            fscanf(f, "%c", &aux);
            fscanf(f, "%d", &j.manos_ganadas);
            fscanf(f, "%c", &aux);
            fscanf(f, "%d", &j.manos_perdidas);
            fscanf(f, "%c", &aux);
        }
        printf("%s\n",j.nombre);
        printf("%d\n",j.fichas);
        printf("%d\n",j.manos_ganadas);
        printf("%d\n",j.manos_perdidas);
        fclose(f);
    }
}