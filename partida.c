
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
        printf("\n");
    }

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



