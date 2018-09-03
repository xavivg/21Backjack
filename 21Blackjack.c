#include <stdio.h>
#include "baraja.h"
#include "partida.h"
void mostrar_menu_jugador() {
    printf("\n El teu torn\n");
    printf("\n Escull:\n");
    printf("\n 1. Demanar cartes");
    printf("\n 2. Plantarse");
    printf("\n 3. Rendirse");
    printf("\n 4. Abandonar partida\n");
}
void blackjack(Baraja b) {
    printf("\n Inici joc\n");
    int game = 0;
    char carta;
    int i = 0;
    int opcio = 0;
    int nBots = BOT_numBots();
    Bot *arrayBots = (Bot *) malloc(sizeof(Bot) * nBots);
    BOT_crea(arrayBots);
    while (game != -1) {
        int nBots = BOT_numBots();
        Partida p = PARTIDA_crea(b);
        printf("\n- Crupier\n");
        printf("\n- %s\n", p.jugador.nombre);
        printf("\n Num bots = %d\n", nBots);
        for (int i = 0; i < nBots; i++) {
            printf("\n- %s\n", arrayBots[i].nombre);
        }
        printf("\n21Blackjack - Jugar\n");
        //Partida_carta_bots();
        for (i = 0; i < 2; i++) {
            carta = PARTIDA_add_carta_crupier(&p);//no hauria de retornar cap carta....
            carta = PARTIDA_add_carta_jugador(&p);
            for (int j = 0; j < nBots; j++) {
                carta = PARTIDA_add_carta_bots(&p, &arrayBots[j]);
            }
        }

        //Partida_carta_jugador
        //cartas repartidas, primeras apuestas

        int *apuestaB = (int) malloc(sizeof(int) * nBots);
        for (int j = 0; j < nBots; j++) {
            apuestaB[j] = PARTIDA_apuesta_bots(&arrayBots[j]);
        }
        int apuestaJ = PARTIDA_apuesta_jugador(&p);
        PARTIDA_show_carta_crupier(&p, 0);
        PARTIDA_show_carta_jugador(&p, 1);
        for (int j = 0; j < nBots; j++) {
            PARTIDA_show_carta_bots(&p, &arrayBots[j], 0);
        }
        //apuestas realizadas, evaluacion
        printf("\n--------------------------------------\n");
        int num_cartasJ = PARTIDA_conversor_jugador(&p);
        int num_cartasC = PARTIDA_conversor_crupier(&p);
        PARTIDA_turno_bots(&p, arrayBots, num_cartasC, num_cartasJ);
        int *num_cartasB = (int) malloc(sizeof(int) * nBots);
        for (int k = 0; k < nBots; ++k) {
            num_cartasB[k] = PARTIDA_conversor_bots(&p, &arrayBots[k]);
        }
        while (opcio != 4) {
            mostrar_menu_jugador();
            printf("\nOpcio: ");
            scanf("%d", &opcio);
            printf("\n");

            switch (opcio) {

                case 1:
                    num_cartasJ = PARTIDA_conversor_jugador(&p);
                    if (num_cartasJ > 21) {
                        printf("T'has passat!, Suma de cartes = %d", num_cartasJ);
                        opcio = 2;
                    } else {
                        PARTIDA_add_carta_jugador(&p);
                        PARTIDA_show_carta_jugador(&p, 1);
                    }

                    break;
                case 2:
                    //pasa turno a crupier
                    printf("\n%s Es planta!\n", p.jugador.nombre);
                    num_cartasJ = PARTIDA_conversor_jugador(&p);
                    num_cartasC = PARTIDA_conversor_crupier(&p);
                    PARTIDA_turno_crupier(&p, num_cartasC, num_cartasJ);
                    opcio = 4;
                    break;
                case 3:
                    printf("\n T'has rendit!\n");
                    opcio = 4;
                    break;
                default:
                    printf("\nEscull una de les opcions!\n");
                    break;
            }
        }
        printf("\nPartida acabada!\n");
        PARTIDA_comprobacion(&p, arrayBots, apuestaB, &num_cartasB, num_cartasC, num_cartasJ, apuestaJ);
        PARTIDA_guarda_jugador(&p);
        //PARTIDA_guarda_bots();
        game = -1;
    }

}
void Estadistica_Jugador() {
    int i = 1;
    Jugador j = JUGADOR_crea();
    printf("\n--- Estadistiques ---\n");
    printf("\n Nom: %s \n",j.nombre);
    int total = j.manos_ganadas + j.manos_perdidas + j.manos_empatadas;
    float ganadas = ((float)j.manos_ganadas / total) * 100;
    float empatadas = ((float)j.manos_empatadas / total) * 100;
    float perdidas = ((float)j.manos_perdidas / total )* 100;
    printf("\n Partidas guanyades %d (%.1f%%)\n",j.manos_ganadas, ganadas);
    printf("\n Partidas perdudes %d (%.1f%%)\n",j.manos_perdidas, perdidas);
    printf("\n Partidas empatades %d (%.1f%%)\n",j.manos_empatadas, empatadas);
    j.fichas_partida = LISTAFICHAS_vesInicio(j.fichas_partida);
    while(!LISTAFICHAS_final(j.fichas_partida)){
        printf("\n Fitxes partida %d: %d\n",i,LISTAFICHAS_consulta(j.fichas_partida));
        j.fichas_partida = LISTAFICHAS_avanza(j.fichas_partida);
        i++;
    }
}