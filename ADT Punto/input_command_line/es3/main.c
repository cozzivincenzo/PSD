#include "functions.h"

int main(int argc, char *argv[]){

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc<5 || (argc-3)%2!=0){
        printf("\nErrore: non ci sono abbastanza argomenti\n");
        exit(-1);
    }

    char criterio = argv[1][0], coordinata = argv[2][0]; // Dichiarazione e inizializzazione delle stringhe atte a contenere criterio e coordinata sui quali basare l'ordinamento
    float x, y; // Dichiarazione delle variabili atte a contenere le coordinate
    int num=(argc-3)/2, cont=0, i=3; // Dichiarazione di variabili utili ai controlli

    Punto *p = malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo in input le coordinate (x;y), passate poi alla funzione creaPunto del file punto.c */

    while(argv[i]!='\0'){
        x=atof(argv[i]);
        y=atof(argv[i+1]);
        p[cont]=creapunto(x,y);
        cont++;
        i+=2;
    }


    // Chiamata alla sottofunzione utile a gestire il riordinamento dell'array di punti
    
    riordina(p, coordinata, criterio, num);

    return 0;

}