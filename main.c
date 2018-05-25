#include <stdio.h>
#include "baraja.h"
#include "gestionFicheros.h"
#include "21Blackjack.c"


void mostrarMenu() {
    printf("\n21 Blackjack\n");
    printf("\n 1. Generar pila de cartas");
    printf("\n 2. Jugar");
    printf("\n 3. Mostrar estadisticas");
    printf("\n 4. Salir\n");
}
void main() {
    cargaBots();
    int opcio = 0;int numero = 0; Baraja b;char enter = 0;
    while (opcio != 4) {

        mostrarMenu();
        printf("\nOpcion: ");
        scanf("%d", &opcio);
        printf("\n");

        switch (opcio) {
            case 1:
                //generar pila de cartas function
                printf("\nDe cuantas barajas deseas crear la pila? \n");
                scanf("%d",&numero);
                while(numero<1 || numero>4){
                    printf("\nNumero incorrecto, del 1 al 4 \n");
                    scanf("%d",&numero);
                }
                b =  BARAJA_crea(numero);
                break;
            case 2:
                if(b.cartas[1] == NULL) {
                    printf(" \n La baraja aun no ha sido creada, no puedes jugar sin crearla primero \n");
                    /*printf("Pulsa enter para continuar...\n");
                    while (enter != '\r' && enter != '\n') { enter = getchar(); }  */
                }else{
                  blackjack(b);
                }
                break;
            case 3:
                break;
            case 4:
                printf(" \n Adios! \n");
                BARAJA_destruye(&b);
                break;
            default:
                printf("\nEsta no es una opcion valida!\n");
                break;
        }
    }
}