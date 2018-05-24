
#include "partida.h"
#include "crupier.h"
#include "jugador.h"

Partida PARTIDA_crea(Baraja b){
    Partida p;
    p.jugador = JUGADOR_crea();
    p.crupier = CRUPIER_crea();
    p.bots = BOTS_crea();
    p.baraja = b;
    return p;
}
char PARTIDA_add_carta_crupier(Partida *p){
    char carta = BARAJA_carta(&(*p).baraja);
    (*p).crupier.cartas = LISTACARTA_inserta((*p).crupier.cartas, carta);
    return carta;
}
char PARTIDA_add_carta_jugador(Partida *p){
    char carta = BARAJA_carta(&(*p).baraja);
    (*p).jugador.cartas = LISTACARTA_inserta((*p).jugador.cartas, carta);
    return carta;
}
void PARTIDA_show_carta_crupier(Partida *p, int t){
    char carta;
    (*p).crupier.cartas = LISTACARTA_vesInicio((*p).crupier.cartas);
    printf("\nCrupier ");
    if(t == 0){
        carta = LISTACARTA_consulta((*p).crupier.cartas);
        printf(" [%c]  [X] \n", carta);
    }
    else{
        while(!LISTACARTA_final((*p).crupier.cartas)){
            carta = LISTACARTA_consulta((*p).crupier.cartas);
            printf(" [%c] ", carta);
            (*p).crupier.cartas = LISTACARTA_avanza((*p).crupier.cartas);
        }
        printf("\n");
    }

}
void PARTIDA_show_carta_jugador(Partida *p, int t){
    char carta;
    (*p).jugador.cartas = LISTACARTA_vesInicio((*p).jugador.cartas);
    printf("\nJugador  ");
    if(t == 0){
        carta = LISTACARTA_consulta((*p).jugador.cartas);
        printf(" [%c]  [X] %dfch\n", carta, p->jugador.fichas);
    }
    else{
        while(!LISTACARTA_final((*p).jugador.cartas)){
            carta = LISTACARTA_consulta((*p).jugador.cartas);
            printf(" [%c] ", carta);
            (*p).jugador.cartas = LISTACARTA_avanza((*p).jugador.cartas);
        }
        printf(" \n                 (%d)\n",PARTIDA_conversor(p));
        printf("\n");
    }

}
int PARTIDA_equivalencia(char carta, int vtotal){
    int valor = 0;
    if(carta == '1'){
        valor = 1;
    }
    else if(carta == '2'){
        valor = 2;
    }
    else if(carta == '3'){
        valor = 3;
    }
    else if(carta == '4'){
        valor = 4;
    }
    else if(carta == '5'){
        valor = 5;
    }
    else if(carta == '6'){
        valor = 6;
    }
    else if(carta == '7'){
        valor = 7;
    }
    else if(carta == '8'){
        valor = 8;
    }
    else if(carta == '9'){
        valor = 9;
    }
    else if(carta == '0'){
        valor = 10;
    }
    else if(carta == 'J'){
        valor = 10;
    }
    else if(carta == 'Q'){
        valor = 10;
    }
    else if(carta == 'K'){
        valor = 10;
    }
    else if(carta == 'A'){
        if(vtotal<21) {
            valor = 1;
        }else{
            valor = 10;
        }
    }
    return valor;
}
int PARTIDA_conversor(Partida *p){
    int vtotal = 0;//valor total integer de las cartas
    (*p).jugador.cartas = LISTACARTA_vesInicio((*p).jugador.cartas);
    while(!LISTACARTA_final((*p).jugador.cartas)){
        vtotal = PARTIDA_equivalencia((LISTACARTA_consulta((*p).jugador.cartas)),vtotal) + vtotal;
        (*p).jugador.cartas = LISTACARTA_avanza((*p).jugador.cartas);
    }
    return vtotal;
}
void PARTIDA_apuesta_jugador(Partida *p){
    int apuesta = 0;
    printf("\nPepito, haz tu apuesta:");
    scanf("%d", &apuesta);
    (*p).jugador.fichas_partida = LISTAFICHAS_inserta((*p).jugador.fichas_partida, apuesta);
    (*p).jugador.fichas = (*p).jugador.fichas - apuesta;
    printf("\n te quedan: %d\n",(*p).jugador.fichas);
}

//stuff bots



