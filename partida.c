
#include "partida.h"
#include "crupier.h"
#include "jugador.h"
#include "bots.h"

Partida PARTIDA_crea(Baraja b){
    Partida p;
    p.jugador = JUGADOR_crea();
    p.crupier = CRUPIER_crea();
    p.nBots = BOT_numBots();
    p.baraja = b;
    return p;
}
char PARTIDA_add_carta_crupier(Partida *p){
    p->baraja = BARAJA_comprueba(&p->baraja);
    char carta = BARAJA_carta(&(*p).baraja);
    CRUPIER_add_carta(&p->crupier, carta);
    return carta;
}
char PARTIDA_add_carta_jugador(Partida *p){
    p->baraja = BARAJA_comprueba(&p->baraja);
    char carta = BARAJA_carta(&(*p).baraja);
    JUGADOR_add_carta(&p->jugador, carta);
    return carta;
}
char PARTIDA_add_carta_bots(Partida *p, Bot *bot){
    p->baraja = BARAJA_comprueba(&p->baraja);
    int i = 0;char carta;
    carta = BARAJA_carta(&(*p).baraja);
    BOT_add_carta(bot, carta);
    return carta;
}
void PARTIDA_show_carta_crupier(Partida *p, int t){
    char carta;
    ListaCarta cartas = CRUPIER_get_cartas(&(*p).crupier);
    cartas = LISTACARTA_vesInicio(cartas);
    printf("\nCrupier ");
    if(t == 0){
        carta = LISTACARTA_consulta(cartas);
        if(carta== '0') {
            printf(" [1%c]  [X] \n", carta);
        }else{
            printf(" [%c]  [X] \n", carta);
        }
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            if(carta== '0'){
                printf(" [1%c] ", carta);
            }
            else{
                printf(" [%c] ", carta);
            }
            cartas = LISTACARTA_avanza(cartas);
        }
        printf("\n");
    }

}
void PARTIDA_show_carta_jugador(Partida *p, int t){
    char carta;int fichas=0;
    ListaCarta cartas = JUGADOR_get_cartas(&(*p).jugador);
    cartas = LISTACARTA_vesInicio(cartas);
    printf("\nJugador  %s",p->jugador.nombre);
    if(t == 0){
        carta = LISTACARTA_consulta(cartas);
        fichas = JUGADOR_consultaFichas((*p).jugador);
        if(carta== '0') {
            printf(" [1%c]  [X] %dfch\n", carta, fichas);//oju
        }
        else{
            printf(" [%c]  [X] %dfch\n", carta, fichas);//oju
        }
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            if(carta== '0'){
                printf(" [1%c] ", carta);
            }
            else{
                printf(" [%c] ", carta);
            }
            cartas = LISTACARTA_avanza(cartas);
        }
        printf(" \n                 (%d)\n",PARTIDA_conversor_jugador(p));
        printf("\n");
    }
}
void PARTIDA_show_carta_bots(Partida *p, Bot *bot,  int t){
    char carta;int fichas=0;int i=0;

    ListaCarta cartas = BOT_get_cartas(&(*bot));
    cartas = LISTACARTA_vesInicio(cartas);
    fichas = BOT_consultaFichas((*bot));
    if(bot->caracter != 'f'){
        fichas == 900;
    }
    if(bot->caracter == 'n'){
        fichas == 500;
    }
    if(bot->caracter == 'd'){
        fichas == 100;
    }
    printf("\nBot  %s", bot->nombre);

    if(t == 0){
        carta = LISTACARTA_consulta(cartas);
        if(carta== '0') {
            printf(" [1%c]  [X] %d fch\n", carta, fichas);//oju
        }
        else{
            printf(" [%c]  [X] %d fch\n", carta, fichas);//oju
        }
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            if(carta== '0'){
                printf(" [1%c] ", carta);
            }
            else{
                printf(" [%c] ", carta);
            }

            cartas = LISTACARTA_avanza(cartas);
        }
    }

    printf(" \n                 (%d)\n",PARTIDA_conversor_bots(p, bot));
    printf("\n");

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
        if(vtotal>10) {
            valor = 1;
        }else{
            valor = 11;
        }
    }
    return valor;
}
int PARTIDA_conversor_jugador(Partida *p){
    int vtotal = 0;//valor total integer de las cartas
    ListaCarta cartas = JUGADOR_get_cartas(&(*p).jugador);
    cartas = LISTACARTA_vesInicio(cartas);
    while(!LISTACARTA_final(cartas)){
        vtotal = PARTIDA_equivalencia((LISTACARTA_consulta(cartas)),vtotal) + vtotal;
        cartas = LISTACARTA_avanza(cartas);
    }
    return vtotal;
}
int PARTIDA_conversor_bots(Partida *p, Bot *bot){
    int vtotal = 0;//valor total integer de las cartas
    ListaCarta cartas = BOT_get_cartas(&(*bot));
    cartas = LISTACARTA_vesInicio(cartas);
    while(!LISTACARTA_final(cartas)){
        vtotal = PARTIDA_equivalencia((LISTACARTA_consulta(cartas)),vtotal) + vtotal;
        cartas = LISTACARTA_avanza(cartas);
    }
    return vtotal;
}
int PARTIDA_conversor_crupier(Partida *p){
    int vtotal = 0;//valor total integer de las cartas
    char carta= '0';
    ListaCarta cartas = CRUPIER_get_cartas(&(*p).crupier);
    cartas = LISTACARTA_vesInicio(cartas);
    while(!LISTACARTA_final(cartas)){
        vtotal = PARTIDA_equivalencia((LISTACARTA_consulta(cartas)),vtotal) + vtotal;
        cartas = LISTACARTA_avanza(cartas);
    }
    return vtotal;
}
int PARTIDA_apuesta_jugador(Partida *p){
    int apuesta = 0;int fichas = JUGADOR_consultaFichas((*p).jugador);
    printf("\n Fes la teva aposta:");
    scanf("%d", &apuesta);
    while(apuesta>fichas) {
        printf("error, no tens suficientes fitxes, proba de nou");
        scanf("%d", &apuesta);
    }
    //Al final de cada partida, se guarda en listafichas el numero de fichas que tiene el jugador en ese momento
    fichas = fichas-apuesta;
    JUGADOR_insertaFichas(&(*p).jugador, fichas);
    printf("Te quedan %d fichas", JUGADOR_consultaFichas((*p).jugador));
    return apuesta;
}
int PARTIDA_apuesta_bots(Bot *bot){
    int apuesta = 0;int fichas = BOT_consultaFichas((*bot));
    if(bot->caracter == 'f'){
        apuesta = 900;
    }
    if(bot->caracter == 'n'){
        apuesta = 500;
    }
    if(bot->caracter == 'd'){
        apuesta = 100;
    }
    while(apuesta>fichas) {
        printf("\n%s no te prous fitxes, es realitzara la aposta minima\n", bot->nombre);
        apuesta = fichas;
    }
    //Al final de cada partida, se guarda en listafichas el numero de fichas que tiene el jugador en ese momento
    fichas = fichas-apuesta;
    BOT_insertaFichas(&(*bot), fichas);
    //printf("\nAl bot %s li queden %d fitxes\n",bot->nombre, BOT_consultaFichas((*bot)));
    return apuesta;
}
char PARTIDA_get_nombre_jugador(Partida *p){
    return JUGADOR_consultaNombre(p->jugador);
}
/*int PARTIDA_get_nFichas(Partida p){
    return JUGADOR_consultaFichas(p.jugador);
}*/
void PARTIDA_carga_jugador(Partida *p){

}
void PARTIDA_juega_crupier(Partida *p){

}
void PARTIDA_turno_crupier(Partida *p, int num_cartasC, int num_cartasJ){
    printf("\nTorn del Crupier\n");
    while(num_cartasC < 17 || num_cartasC <= num_cartasJ) {
        PARTIDA_add_carta_crupier(p);
        num_cartasC = PARTIDA_conversor_crupier(p);
    }
    PARTIDA_show_carta_crupier(p, 1);
}
//stuff bots
void PARTIDA_turno_bots(Partida *p, Bot *arrayBots, int num_cartasC, int num_cartasJ){
    printf("\nTorn dels Bots\n");
    int num_cartasB = 0;
    int best_num_cartasB = 0;
    if(num_cartasC >= num_cartasJ){
        best_num_cartasB = num_cartasC;

    }
    else{
        best_num_cartasB = num_cartasJ;
    }
    for (int i = 0; i < p->nBots; ++i) {
        num_cartasB = PARTIDA_conversor_bots(p, &arrayBots[i].nombre);
        while(num_cartasB % 2 != 0 && num_cartasB <=arrayBots[i].carta_maxima && arrayBots[i].caracter =='n' && num_cartasB < 21){
            PARTIDA_add_carta_bots(p, &arrayBots[i]);
            num_cartasB = PARTIDA_conversor_bots(p, &arrayBots[i]);
        }
        while(num_cartasB <=arrayBots[i].carta_maxima && arrayBots[i].caracter =='d' && num_cartasB < 21){
            PARTIDA_add_carta_bots(p, &arrayBots[i]);
            num_cartasB = PARTIDA_conversor_bots(p, &arrayBots[i]);
        }
        while(num_cartasB <=arrayBots[i].carta_maxima && num_cartasB <=best_num_cartasB && arrayBots[i].caracter =='f' && num_cartasB < 21){
            PARTIDA_add_carta_bots(p, &arrayBots[i]);
            num_cartasB = PARTIDA_conversor_bots(p, &arrayBots[i]);
        }
        if(num_cartasB > best_num_cartasB){
            best_num_cartasB = num_cartasB;
        }
        PARTIDA_show_carta_bots(p, &arrayBots[i], 1);
    }
    printf("\n--------------------------------------\n");
}

//end of partifa

void PARTIDA_comprobacion(Partida *p, Bot *arrayBots, int *apuestaB, int *num_cartasB, int num_cartasC, int num_cartasJ, int apuestaJ){
    int fichas;
    printf("\n--------------------------------------\n");
    if(num_cartasJ<=21 && num_cartasJ != num_cartasC){
        if(num_cartasJ==21){
            printf("\n%s, Has conseguit guanyar!! 21 BLACKJACK!!!\n", p->jugador.nombre);
            p->jugador.manos_ganadas++;
            fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) + (apuestaJ*3);
            printf("\n Has guanyat %d fitxes\n",apuestaJ);
            printf("\n%s, Has conseguit guanyar!! 21 BLACKJACK!!!\n",fichas);
        }else{
            printf("\n%s, Has conseguit guanyar!!", p->jugador.nombre);
            printf("\n Has guanyat %d fitxes\n",apuestaJ);
            p->jugador.manos_ganadas++;
            fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) + (apuestaJ*2);
        }
    }
    else if(num_cartasJ<21 && num_cartasJ == num_cartasC){
        printf("%s, Has empatat amb el Crupier!", p->jugador.nombre);
        printf("\n Has recuperat %d fitxes\n",apuestaJ);
        p->jugador.manos_empatadas++;
        fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) + apuestaJ;
    }
    else{
        printf("%s, Has perdut la partida!", p->jugador.nombre);
        printf("\n Has perdut %d fitxes\n",apuestaJ);
        p->jugador.manos_perdidas++;
        fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) - apuestaJ;
    }
    printf("\n T'has quedat amb %d fitxes\n", fichas);
    p->jugador.fichas = fichas;
    ListaFichas x = LISTAFICHAS_inserta(p->jugador.fichas_partida, fichas);
    p->jugador.fichas_partida = x;

    for (int i = 0; i < p->nBots; ++i) {
        printf("\n--------------------------------------\n");
        if(num_cartasB[i]<=21 && num_cartasB[i] != num_cartasC){
            if(num_cartasB[i]==21){
                printf("\n%s, Has conseguit guanyar!! 21 BLACKJACK!!!\n", arrayBots[i].nombre);
                //p->jugador.manos_ganadas++;
                fichas =  arrayBots[i].fichas + (apuestaJ*3);
                printf("\n Has guanyat %d fitxes\n",apuestaJ);
                printf("\n%s, Has conseguit guanyar!! 21 BLACKJACK!!!\n",fichas);
            }else{
                printf("\n%s, Has conseguit guanyar!!", arrayBots[i].nombre);
                printf("\n Has guanyat %d fitxes\n",apuestaJ);
                fichas =  arrayBots[i].fichas + (apuestaJ*2);
            }
        }
        else if(num_cartasB[i]<21 && num_cartasB[i] == num_cartasC){
            printf("%s, Has empatat amb el Crupier!", arrayBots[i].nombre);
            printf("\n Has recuperat %d fitxes\n",apuestaJ);
            //fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) + apuestaJ;
        }
        else{
            printf("%s, Has perdut la partida!", arrayBots[i].nombre);
            printf("\n Has perdut %d fitxes\n",apuestaJ);
            //fichas =  LISTAFICHAS_consulta(p->jugador.fichas_partida) - apuestaJ;
        }
        printf("\n T'has quedat amb %d fitxes\n", fichas);
        arrayBots[i].fichas = fichas;
        //ListaFichas x = LISTAFICHAS_inserta(p->jugador.fichas_partida, fichas);
        p->jugador.fichas_partida = x;

    }


    printf("\n--------------------------------------\n");
}