#ifndef INC_21BLACKJACK_LISTAFICHAS_H
#define INC_21BLACKJACK_LISTAFICHAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int elemento;
    struct N *sig;
}Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ant;
}ListaFichas;


ListaFichas LISTAFICHAS_crea();
ListaFichas LISTAFICHAS_inserta(ListaFichas l, int elemento);
ListaFichas LISTAFICHAS_elimina(ListaFichas l);
int LISTAFICHAS_consulta(ListaFichas l);
ListaFichas LISTAFICHAS_avanza(ListaFichas l);
ListaFichas LISTAFICHAS_vesInicio(ListaFichas l);
int LISTAFICHAS_final(ListaFichas l);
int LISTAFICHAS_vacia(ListaFichas l);
ListaFichas LISTAFICHAS_destruye(ListaFichas l);

#endif //INC_21BLACKJACK_LISTAFICHAS_H
