#include <stdlib.h>
#include <time.h>
#include "baraja.h"

Baraja BARAJA_crea(int numero){
    Baraja b;
    char cartas[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
    int r = 0;
    int total = numero * 13 * 4; //guarda en una variable el num de cartas que entrarán en la baraja
    b.cartas[total];//array de cartas totales segun la baraja
    b.nCartas = 0;
        //fer un bucle segons el numero de barajas que volen crear la pila
    srand(time(NULL));
        for(int j=0;j<total;j++){

             r =  rand() % 13;
             BARAJA_push(&b, cartas[r]);

        }
        if(b.nCartas == total){
            printf("\n Pila generada correctamente de %d cartas \n", total);
        } else{
            printf("\n Hubo un error al crear la pila \n");
        }
    return b;
}
void BARAJA_push(Baraja *b, char carta){//agregacion de carta a la pila baraja
        (*b).cartas[(*b).nCartas] = carta;
         printf("%c ", (*b).cartas[b->nCartas]);// si no es fa el printf aqui, surten caracters raros
        (*b).nCartas++;

}
//Stuff
void BARAJA_destruye(Baraja *b){
    b->nCartas = 0;
    free(b->cartas);
}
char BARAJA_carta(Baraja *b){
    char carta = b->cartas[b->nCartas-1];
    b->nCartas--;
    return carta;
}