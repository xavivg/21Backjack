#include <stdio.h>

void main() {

    int opcio = 0;

    while (opcio != 4) {

        mostrarMenu();
        printf("\nOpcion: ");
        scanf("%d", &opcio);
        printf("\n");

        switch (opcio) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("\nEsta no es una opcion valida!\n");
                break;
        }
    }
}

void mostrarMenu() {
    printf("\n21 Blackjack\n");
    printf("\n 1. Generar pila de cartas");
    printf("\n 2. Jugar");
    printf("\n 3. Mostrar estadisticas");
    printf("\n 4. Salir\n");
}