#include "crupier.h"

Crupier CRUPIER_crea() {
    Crupier c;
    c.cartas = LISTACARTA_crea();
    c.cartas = LISTACARTA_vesInicio(c.cartas);
    return c;
}
void * CRUPIER_add_carta(Crupier *crupier, char carta){
    crupier->cartas = LISTACARTA_inserta(crupier->cartas, carta);
}
ListaCarta CRUPIER_get_cartas(Crupier *crupier){
    return crupier->cartas;
}