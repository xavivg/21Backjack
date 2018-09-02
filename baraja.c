#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "baraja.h"

Baraja BARAJA_crea(int numero){
    Baraja b;
    char cartas[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
    int r = 0;
    int AS = 0;
    int dos = 0;
    int tres = 0;
    int cuatro = 0;
    int cinco = 0;
    int seis = 0;
    int siete = 0;
    int ocho = 0;
    int nueve = 0;
    int diez = 0;
    int J = 0;
    int Q = 0;
    int K = 0;
    bool anadir;
    int total = numero * 13 * 4; //guarda en una variable el num de cartas que entrarán en la baraja
    b.cartas[total];//array de cartas totales segun la baraja
    b.nCartas = 0;
        //fer un bucle segons el numero de barajas que volen crear la pila
    srand(time(NULL));
        for(int j=0;j<total;j++){
            anadir = false;
             r =  rand() % 13;

             if(cartas[r] == 'A'){
                 if(AS<=4){
                     anadir = true;
                     AS++;
                 }
             }
            if(cartas[r] == '2'){
                if(dos<=4){
                    anadir = true;
                    dos++;
                }
            }
            if(cartas[r] == '3'){
                if(tres<=4){
                    anadir = true;
                    tres++;
                }
            }
            if(cartas[r] == '4'){
                if(cuatro<=4){
                    anadir = true;
                    cuatro++;
                }
            }
            if(cartas[r] == '5'){
                if(cinco<=4){
                    anadir = true;
                    cinco++;
                }
            }
            if(cartas[r] == '6'){
                if(seis<=4){
                    anadir = true;
                    seis++;
                }
            }
            if(cartas[r] == '7'){
                if(siete<=4){
                    anadir = true;
                    siete++;
                }
            }
            if(cartas[r] == '8'){
                if(ocho<=4){
                    anadir = true;
                    ocho++;
                }
            }
            if(cartas[r] == '9'){
                if(nueve<=4){
                    anadir = true;
                    nueve++;
                }
            }
            if(cartas[r] == '0'){
                if(diez<=4){
                    anadir = true;
                    diez++;
                }
            }
            if(cartas[r] == 'J'){
                if(J<=4){
                    anadir = true;
                    J++;
                }
            }
            if(cartas[r] == 'Q'){
                if(Q<=4){
                    anadir = true;
                    Q++;
                }
            }
            if(cartas[r] == 'K'){
                if(K<=4){
                    anadir = true;
                    K++;
                }
            }
             if(anadir = true){
                 BARAJA_push(&b, cartas[r]);
             }

        }
        if(b.nCartas == total){
            printf("\n Pila generada correctamente de %d cartas \n", total);
        } else{
            printf("\n Hubo un error al crear la pila \n");
        }
    return b;
}
void BARAJA_push(Baraja *b, char carta){//agregacion de carta a la pila baraja
        (*b).cartas[(*b).nCartas] = carta;
        if(carta == '0'){
            printf("1%c ", (*b).cartas[b->nCartas]);
        }
        else{
            printf("%c ", (*b).cartas[b->nCartas]);// si no es fa el printf aqui, surten caracters raros
        }
        (*b).nCartas++;

}
//Stuff
int BARAJA_numeroCartas(Baraja b){
    return b.nCartas;
}



//end of stuff
void BARAJA_destruye(Baraja *b){
    b->nCartas = 0;
    free(b->cartas);
}
char BARAJA_carta(Baraja *b){
    char carta = b->cartas[b->nCartas-1];
    b->nCartas--;
    return carta;
}
Baraja BARAJA_comprueba(Baraja *b){
    int numero = 0;
    if(b->nCartas !=0){
        return *b;
    }
    else{
        printf("\nUps, la Baralla esta plena, de quantes baralles vols crear la pila? \n");
        scanf("%d",&numero);
        while(numero<1 || numero>4){
            printf("\nNumero incorrecte, del 1 al 4 \n");
            scanf("%d",&numero);
            *b = BARAJA_crea(numero);
        }
       return *b;
    }
}