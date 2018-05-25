
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
    CRUPIER_add_carta(&p->crupier, carta);
    return carta;
}
char PARTIDA_add_carta_jugador(Partida *p){
    char carta = BARAJA_carta(&(*p).baraja);
    JUGADOR_add_carta(&p->jugador, carta);
    return carta;
}
void PARTIDA_show_carta_crupier(Partida *p, int t){
    char carta;
    ListaCarta cartas = CRUPIER_get_cartas(&(*p).crupier);
    cartas = LISTACARTA_vesInicio(cartas);
    printf("\nCrupier ");
    if(t == 0){
        carta = LISTACARTA_consulta(cartas);
        printf(" [%c]  [X] \n", carta);
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            printf(" [%c] ", carta);
            cartas = LISTACARTA_avanza(cartas);
        }
        printf("\n");
    }

}
void PARTIDA_show_carta_jugador(Partida *p, int t){
    char carta;int fichas=0;
    ListaCarta cartas = JUGADOR_get_cartas(&(*p).jugador);
    cartas = LISTACARTA_vesInicio(cartas);
    printf("\nJugador  ");
    if(t == 0){
        carta = LISTACARTA_consulta(cartas);
        fichas = JUGADOR_get_fichas(&(*p).jugador);
        printf(" [%c]  [X] %dfch\n", carta, fichas);//oju
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            printf(" [%c] ", carta);
            cartas = LISTACARTA_avanza(cartas);
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
    ListaCarta cartas = JUGADOR_get_cartas(&(*p).jugador);
    cartas = LISTACARTA_vesInicio(cartas);
    while(!LISTACARTA_final(cartas)){
        vtotal = PARTIDA_equivalencia((LISTACARTA_consulta(cartas)),vtotal) + vtotal;
        cartas = LISTACARTA_avanza(cartas);
    }
    return vtotal;
}
int PARTIDA_apuesta_jugador(Partida *p){
    int apuesta = 0;int fichas = JUGADOR_get_fichas(&(*p).jugador);
    printf("\nPepito, haz tu apuesta:");
    scanf("%d", &apuesta);
    while(apuesta>fichas) {
        printf("error, no tienes tantas fichas, prueba de nuevo");
        scanf("%d", &apuesta);
    }
    //Al final de cada partida, se guarda en listafichas el numero de fichas que tiene el jugador en ese momento
    fichas =  JUGADOR_set_fichas(&(*p).jugador, fichas);
    printf("\n te quedan: %d\n",fichas);
    return apuesta;
}

//stuff bots



