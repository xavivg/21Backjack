#include "crupier.h"

Crupier CRUPIER_crea() {
    Crupier c;
    ListaCarta x  = LISTACARTA_crea();
    c.cartas = x;
    return c;
}
void * CRUPIER_add_carta(Crupier *crupier, char carta){
    crupier->cartas = LISTACARTA_inserta(crupier->cartas, carta);
}
ListaCarta CRUPIER_get_cartas(Crupier *crupier){
    return crupier->cartas;
}