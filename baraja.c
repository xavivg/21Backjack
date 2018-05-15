#include "baraja.h"

Baraja BARAJA_crea(int numero){
    Baraja b;
    b.cuantos = 0;
    return b;
}
void BARAJA_push(Baraja *b, int elemento){//agregacion de carta a la pila baraja

        (*b).elementos[(*b)cuantos] = elemento;
        (*b).cuantos++;

}