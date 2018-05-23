#ifndef INC_21BLACKJACK_LISTAFICHAS_H
#define INC_21BLACKJACK_LISTAFICHAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct A {
    int elemento;
    struct A *sig;
}Node;

typedef struct {
    Node *pri;
    Node *ant;
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
