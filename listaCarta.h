#ifndef INC_21BACKJACK_LISTACARTA_H
#define INC_21BACKJACK_LISTACARTA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    char elemento;
    struct N *sig;
}Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ant;
}ListaCarta;


ListaCarta LISTACARTA_crea();
ListaCarta LISTACARTA_inserta(ListaCarta l, char elemento);
ListaCarta LISTACARTA_elimina(ListaCarta l);
char LISTACARTA_consulta(ListaCarta l);
ListaCarta LISTACARTA_avanza(ListaCarta l);
ListaCarta LISTACARTA_vesInicio(ListaCarta l);
int LISTACARTA_final(ListaCarta l);
int LISTACARTA_vacia(ListaCarta l);
ListaCarta LISTACARTA_destruye(ListaCarta l);
ListaCarta LISTACARTA_unir(ListaCarta l1, ListaCarta l2);
int LISTACARTA_modificar(ListaCarta l, int * valor, int * posicion);

#endif //INC_21BACKJACK_LISTACARTA_H
