
#include "partida.h"
#include "crupier.h"
#include "jugador.h"
#include "bots.h"
#include "gestionFicheros.h"

Partida PARTIDA_crea(Baraja b){
    Partida p;
    p.jugador = JUGADOR_crea();
    p.crupier = CRUPIER_crea();
    p.nBots = BOT_numBots();
    // Crea en memoria
    // BOT_crea(arrayBOT);
    p.arrayBots = BOT_crea(p.nBots);
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
        fichas = JUGADOR_consultaFichas((*p).jugador);
        printf(" [%c]  [X] %dfch\n", carta, fichas);//oju
    }
    else{
        while(!LISTACARTA_final(cartas)){
            carta = LISTACARTA_consulta(cartas);
            printf(" [%c] ", carta);
            cartas = LISTACARTA_avanza(cartas);
        }
        printf(" \n                 (%d)\n",PARTIDA_conversor_jugador(p));
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


//end of partifa

void PARTIDA_comprobacion(Partida *p, int num_cartasC, int num_cartasJ, int apuestaJ){
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
    printf("\n--------------------------------------\n");
}