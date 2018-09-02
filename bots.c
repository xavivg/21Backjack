#include "bots.h"
#include "partida.h"

void BOT_crea(Bot *arrayBots) {
    int nBots = BOT_numBots();
   /* BOT b;
    return b; */
    int fichas;
    char car;
    char *caracter = malloc(sizeof(char) * 1024);
    int cartaMax;
    char *nombre = malloc(sizeof(char) * 1024);
        FILE *f;
        f = fopen("fichero_bots.bj", "r");

        if (f == NULL) {
            printf("\nError en obrir fitxer...\n");
        } else {
            int numBOT = 0; int i= 0;
            fscanf(f, "%i", &numBOT);

            char *nombre = malloc(sizeof(char) * 1024);

            char aux;
            fscanf(f, "%c", &aux);
            fgets(nombre, 25, f);
            strtok(nombre, "\n");
            arrayBots[0].nombre = nombre;
            for (i = 0; i<numBOT; i++){
                while (!feof(f)) {

                    fscanf(f, "%d", &fichas);
                    arrayBots[i].fichas = fichas;

                    fscanf(f, "%s", caracter);
                    if (strcmp(caracter, "Fuerte") == 0) {
                        car = 'f';
                    } else if (strcmp(caracter, "Debil") == 0) {
                        car = 'd';
                    } else if (strcmp(caracter, "Normal") == 0) {
                        car = 'n';
                    }
                    arrayBots[i].caracter = car;

                    fscanf(f, "%d", &cartaMax);
                    arrayBots[i].carta_maxima = cartaMax;
                    ListaCarta x  = LISTACARTA_crea();
                    arrayBots[i].cartas = x;
                    i++;
                    fscanf(f, "%c", &aux);
                    nombre = malloc(sizeof(char) * 1024);
                    fgets(nombre, 25, f);
                    strtok(nombre, "\n");
                    arrayBots[i].nombre = nombre;
                }
            }
        }
        fclose(f);
}
int BOT_numBots(){

    int numBOT=0;


    FILE *fi=fopen("fichero_bots.bj","r");
    if (fi==NULL){
        printf("Error al llegir l'arxiu.");
    }else{
        fscanf(fi, "%d", &numBOT);
        fclose(fi);
    }

    return numBOT;

}
void BOT_insertaNombre(Bot *b, char *nombre) {
    (*b).nombre = nombre;
}

void BOT_insertaFichas(Bot *b, int fichas) {
    (*b).fichas = fichas;
}

void BOT_insertaCaracter(Bot *b, char caracter) {
    (*b).caracter = caracter;
}

void BOT_insertaCartaMax(Bot *b, int cartaMax) {
    (*b).carta_maxima = cartaMax;
}

void BOT_insertaCartas(Bot *b, ListaCarta cartas) {
    (*b).cartas = cartas;
}

char *BOT_consultaNombre(Bot b) {
    return b.nombre;
}

int BOT_consultaFichas(Bot b) {
    return b.fichas;
}

char BOT_consultaCaracter(Bot b) {
    return b.caracter;
}

int BOT_consultaCartaMax(Bot b) {
    return b.carta_maxima;
}

ListaCarta BOT_consultaCartas(Bot b) {
    return b.cartas;
}
void BOT_add_carta(Bot *bot, char carta){
    bot->cartas = LISTACARTA_inserta(bot->cartas, carta);
}
ListaCarta BOT_get_cartas(Bot *bot){
    return bot->cartas;
}