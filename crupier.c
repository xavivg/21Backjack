#include "crupier.h"
#include "partida.h"

Crupier CRUPIER_crea() {
    Crupier c;
    c.cartas = LISTACARTA_crea();
    c.cartas = LISTACARTA_vesInicio(c.cartas);
    return c;
}
void CRUPIER_addCarta(Partida *p, Baraja *b){
    char carta  = BARAJA_carta(b);
    (*p).crupier.cartas = LISTACARTA_inserta((*p).crupier.cartas, carta);
}
char CRUPIER_muestraCarta(Partida *p){
    (*p).crupier.cartas = LISTACARTA_vesInicio((*p).crupier.cartas);
    char carta = LISTACARTA_consulta((*p).crupier.cartas);
    return carta;
}