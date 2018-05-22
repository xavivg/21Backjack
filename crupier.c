#include "crupier.h"

Crupier CRUPIER_crea() {
    Crupier c;
    c.cartas = LISTACARTA_crea();
    c.cartas = LISTACARTA_vesInicio(c.cartas);
    return c;
}