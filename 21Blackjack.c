#include <stdio.h>
#include "baraja.h"
#include "partida.h"
void mostrar_menu_jugador() {
    printf("\n Escull:\n");
    printf("\n 1. Demanar cartes");
    printf("\n 2. Plantarse");
    printf("\n 3. Rendirse");
    printf("\n 4. Abandonar partida\n");
}
void blackjack(Baraja b) {
    printf("\n Inici joc\n");
    int game = 0;char carta ;int i = 0;int opcio = 0;

    while (game != -1) {
        int nBots = BOT_numBots();
        Bot *arrayBOT[nBots];
        //arrayBots = malloc( nBots * sizeof(Bot));
        Partida p = PARTIDA_crea(b);
        p.arrayBots = *arrayBOT;
        printf("\n- Crupier\n");
        printf("\n- %s\n", p.jugador.nombre);
        printf("\n Num bots = %d",nBots);
        for(int i = 0; i<nBots;i++){
            printf("\n- %s\n",p.arrayBots[i].nombre);
        }
        printf("\n21Blackjack - Jugar\n");
        //Partida_carta_bots();
        for(i=0;i<2;i++){
            carta = PARTIDA_add_carta_crupier(&p);//no hauria de retornar cap carta....
            carta = PARTIDA_add_carta_jugador(&p);
        }
        PARTIDA_show_carta_crupier(&p, 0);
        PARTIDA_show_carta_jugador(&p, 1);
        //Partida_carta_jugador
        //cartas repartidas, primeras apuestas
       int apuestaJ =  PARTIDA_apuesta_jugador(&p);
        //apuestas realizadas, evaluacion
        printf("\n--------------------------------------\n");
        int num_cartasJ = PARTIDA_conversor_jugador(&p);
        int num_cartasC = PARTIDA_conversor_crupier(&p);
        while (opcio != 4) {
            mostrar_menu_jugador();
            printf("\nOpcio: ");
            scanf("%d", &opcio);
            printf("\n");

            switch (opcio) {

                case 1:
                    num_cartasJ = PARTIDA_conversor_jugador(&p);
                    if(num_cartasJ>21){
                        printf("T'has passat!, Suma de cartes = %d",num_cartasJ);
                        opcio = 2;
                    }
                    else{
                        PARTIDA_add_carta_jugador(&p);
                        PARTIDA_show_carta_jugador(&p, 1);
                    }

                    break;
                case 2:
                    //pasa turno a crupier
                    printf("\n%s Es planta!\n",  p.jugador.nombre);//get nombre jugador de plantilla
                    num_cartasJ = PARTIDA_conversor_jugador(&p);
                    num_cartasC = PARTIDA_conversor_crupier(&p);
                    PARTIDA_turno_crupier(&p, num_cartasC, num_cartasJ);
                    opcio=4;
                    break;
                case 3:
                    printf("\n T'has rendit!\n");
                    opcio=4;
                    break;
                default:
                    printf("\nEscull una de les opcions!\n");
                    break;
            }
        }
        printf("\nPartida acabada!\n");
        PARTIDA_comprobacion(&p, num_cartasC, num_cartasJ, apuestaJ);

       game = -1;
    }



    /* BOTS
     * while (game != -1) {
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