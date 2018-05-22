// programa en si

#include <stdio.h>
#include "baraja.h"
#include "partida.h"

void blackjack(Baraja b) {
    printf("\nLet's begin!\n");
    int game = 0;
    Partida p = PARTIDA_crea(b);
    printf("%d", p.baraja.nCartas);
    //llegir arxiu del jugador
    p.jugador.nombre = 'Xavi';
    p.jugador.fichas = 100;
    //legir arxiu dels bots
    while (game != -1) {
        printf("\nJugadores de la partida:\n");
        printf("- Crupier\n");
        /*for(int i = 0; i<p.bots.nBots;i++){
            printf("\n- %c\n",p.bots.nombre);
        }*/
        printf("\n- %c : %d \n", p.jugador.nombre, p.jugador.fichas);
        printf("\n Tiempo de realizar apuestas. %c, cuanto quieres apostar esta partida?\n", p.jugador.nombre);
        scanf("%d", &p.jugador.fichas_partida);
        printf("\n----------\n");
        //repartir cartas
        PARTIDA_addCarta(&p.crupier.cartas, &b);
        p.crupier.cartas = LISTACARTA_vesInicio(p.crupier.cartas);
        char c = LISTACARTA_consulta(p.crupier.cartas);
        printf("\nCrupier : [%c] \n", c);
        CRUPIER_addCarta(&p, &b);
        CRUPIER_muestraCarta(&p);

        printf("\n%c : [%c] \n", p.jugador.nombre, c);
    }
}