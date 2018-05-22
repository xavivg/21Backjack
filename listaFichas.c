#include "listaFichas.h"

ListaFichas LISTAFICHAS_crea() {
    ListaFichas l;

    l.pri = (Nodo*)malloc(sizeof(Nodo));
    if (l.pri == NULL) {
        printf("\nError al crear la lista...\n");
    } else {
        l.ant = l.pri;
        l.pri->sig = NULL;
        l.pri->elemento = -1; // FANTASMA, ELEMENTO_indefinido();
    }

    return l;
}

ListaFichas LISTAFICHAS_inserta(ListaFichas l, int elemento) {
    Nodo *aux;

    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al insertar en la lista...\n");
    } else {
        aux->elemento = elemento;
        aux->sig = l.ant->sig;
        l.ant->sig = aux;
        l.ant = aux; // para mantener el PDI
    }
    return l;
}

ListaFichas LISTAFICHAS_elimina(ListaFichas l) {
    Nodo *aux;

    if (l.ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        aux = l.ant->sig;
        l.ant->sig = aux->sig; // l.ant->sig->sig;
        free(aux);
    }
    return l;
}



int LISTAFICHAS_consulta(ListaFichas l) {
    int elemento;
    if (l.ant->sig == NULL) {
        printf("\nError al consultar, el PDI está al final...\n");
    } else {
        elemento = l.ant->sig->elemento;
    }
    return elemento;
}

ListaFichas LISTAFICHAS_avanza(ListaFichas l) {
    if (l.ant->sig == NULL) {
        printf("\nError al avanzar, el PDI está al final...\n");
    } else {
        l.ant = l.ant->sig;
    }
    return l;
}

ListaFichas LISTAFICHAS_vesInicio(ListaFichas l) {
    l.ant = l.pri;
    return l;
}

int LISTAFICHAS_final(ListaFichas l) {
    return l.ant->sig==NULL;
}

int LISTAFICHAS_vacia(ListaFichas l) {
    return l.pri->sig == NULL;
}

ListaFichas LISTAFICHAS_destruye(ListaFichas l) {
    Nodo *aux;

    while (l.pri!=NULL) {
        aux = l.pri;
        l.pri = l.pri->sig;
        free(aux);
    }

/*

	l = LISTAFICHAS_vesInicio(l);

	while (!LISTAFICHAS_vacia(l)) {
		l = LISTAFICHAS_elimina(l);
	}

	free(l.pri); // borramos el fantasma
	l.pri = l.ant = NULL;
*/
    return l;
}