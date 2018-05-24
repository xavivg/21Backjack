#include <stdio.h>
#include "baraja.h"
#include "partida.h"
void mostrar_menu_jugador() {
    //passar nom fent un get name
    printf("\nPepito, elije:\n");
    printf("\n 1. Pedir cartas");
    printf("\n 2. Plantarse");
    printf("\n 3. Rendirse");
    printf("\n 4. Abandonar partida\n");
}
void blackjack(Baraja b) {
    printf("\nLet's begin!\n");
    int game = 0;char carta ;int i = 0;int opcio = 0;
    Partida p = PARTIDA_crea(b);

    printf("%d", BARAJA_numeroCartas(b));
    //llegir arxiu del jugador
    //legir arxiu dels bots
    while (game != -1) {
        printf("- Crupier\n");
     /*   for(int i = 0; i<p.bots.nBots;i++){
            printf("\n- %c\n",p.bots.nombre);
        }*/
        printf("\n21Blackjack - Jugar");

        //Partida_carta_bots();
        for(i=0;i<2;i++){
            carta = PARTIDA_add_carta_crupier(&p);//no hauria de retornar cap carta....
            carta = PARTIDA_add_carta_jugador(&p);
        }
        PARTIDA_show_carta_crupier(&p, 0);
        PARTIDA_show_carta_jugador(&p, 1);
        //Partida_carta_jugador
        //cartas repartidas, primeras apuestas
        PARTIDA_conversor(&p);
        //apuestas realizadas, evaluacion
        printf("--------------------------------------");
        while (opcio != 4) {
            mostrar_menu_jugador();
            printf("\nOpcion: ");
            scanf("%d", &opcio);
            printf("\n");
            switch (opcio) {
                case 1:
                    PARTIDA_add_carta_jugador(&p);
                    PARTIDA_show_carta_jugador(&p, 1);
                    break;
                case 2:
                    //pasa turno a crupier
                    break;
                case 3:
                    //pasa turno a crupier
                    break;
            }
        }
       game = -1;
    }



    /*while (game != -1) {
        printf("\nJugadores de la partida:\n");
        printf("- Crupier\n");
        for(int i = 0; i<p.bots.nBots;i++){
            printf("\n- %c\n",p.bots.nombre);
        }
        printf("\n- %c : %d \n", p.jugador.nombre, p.jugador.fichas);
        printf("\n Tiempo de realizar apuestas. %c, cuanto quieres apostar esta partida?\n", p.jugador.nombre);
        scanf("%d", &p.jugador.fichas_partida);
        printf("\n----------\n");
        PARTIDA_addCarta(&p.crupier.cartas, &b);
        p.crupier.cartas = LISTACARTA_vesInicio(p.crupier.cartas);
        char c = LISTACARTA_consulta(p.crupier.cartas);
        printf("\nCrupier : [%c] \n", c);

        printf("\n%c : [%c] \n", p.jugador.nombre, c);
    }*/
}