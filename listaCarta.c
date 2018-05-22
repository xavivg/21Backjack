#include "listaCarta.h"

ListaCarta LISTACARTA_crea() {
    ListaCarta l;

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

ListaCarta LISTACARTA_inserta(ListaCarta l, char elemento) {
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

ListaCarta LISTACARTA_elimina(ListaCarta l) {
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



char LISTACARTA_consulta(ListaCarta l) {
    char elemento;
    if (l.ant->sig == NULL) {
        printf("\nError al consultar, el PDI está al final...\n");
    } else {
        elemento = l.ant->sig->elemento;
    }
    return elemento;
}

ListaCarta LISTACARTA_avanza(ListaCarta l) {
    if (l.ant->sig == NULL) {
        printf("\nError al avanzar, el PDI está al final...\n");
    } else {
        l.ant = l.ant->sig;
    }
    return l;
}

ListaCarta LISTACARTA_vesInicio(ListaCarta l) {
    l.ant = l.pri;
    return l;
}

int LISTACARTA_final(ListaCarta l) {
    return l.ant->sig==NULL;
}

int LISTACARTA_vacia(ListaCarta l) {
    return l.pri->sig == NULL;
}

ListaCarta LISTACARTA_destruye(ListaCarta l) {
    Nodo *aux;

    while (l.pri!=NULL) {
        aux = l.pri;
        l.pri = l.pri->sig;
        free(aux);
    }

/*

	l = LISTACARTA_vesInicio(l);

	while (!LISTACARTA_vacia(l)) {
		l = LISTACARTA_elimina(l);
	}

	free(l.pri); // borramos el fantasma
	l.pri = l.ant = NULL;
*/
    return l;
}

ListaCarta LISTACARTA_unir(ListaCarta l1, ListaCarta l2){
    ListaCarta ltotal;
    ltotal = LISTACARTA_crea();
    ltotal = LISTACARTA_vesInicio(ltotal);
    l1 = LISTACARTA_vesInicio(l1);
    l2 = LISTACARTA_vesInicio(l2);
    int flag = 0;
    while(!LISTACARTA_final(l1)){
        while(!LISTACARTA_final(l2)){
            if(LISTACARTA_consulta(l1) == LISTACARTA_consulta(l2)){
                flag = 1;
            }
            l2=LISTACARTA_avanza(l2);
        }
        l2 = LISTACARTA_vesInicio(l2);
        if(flag != 1){
            LISTACARTA_inserta(ltotal, LISTACARTA_consulta(l2));
        }
        flag = 0;
        l1=LISTACARTA_avanza(l1);
    }
    ltotal = LISTACARTA_vesInicio(ltotal);
    l1 = LISTACARTA_vesInicio(l1);
    l2 = LISTACARTA_vesInicio(l2);
    while(!LISTACARTA_final(l2)){
        while(!LISTACARTA_final(l2)){
            if(LISTACARTA_consulta(l2) == LISTACARTA_consulta(l1)){
                flag = 1;
            }
            l2=LISTACARTA_avanza(l2);
        }
        l2 = LISTACARTA_vesInicio(l2);
        if(flag != 1){
            LISTACARTA_inserta(ltotal, LISTACARTA_consulta(l1));
        }
        flag = 0;
        l1=LISTACARTA_avanza(l1);
    }
    return ltotal;
}

int LISTACARTA_modificar(ListaCarta l, int * valor, int * posicion){
    Nodo *aux;
    int r = 1;
    int p = 0;
    l = LISTACARTA_vesInicio(l);
    while (!LISTACARTA_final(l)) {
        l=LISTACARTA_avanza(l);
        p++;
        if(p== *posicion){
            l= LISTACARTA_elimina(l);
            l = LISTACARTA_inserta(l, *valor);
            r = 0;
        }
    }
    return r;
}


