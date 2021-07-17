#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(int argc, char *argv[]){

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc<4 || argc%2!=0){
        printf("\nErrore: non ci sono abbastanza argomenti\n");
        exit(-1);
    }

    float x, y, D, distance; // Dichiarazione delle variabili atte a contenere coordinate e distanze
    int num=(argc-2)/2, cont=0, i=2; // Dichiarazione di variabili utili ai controlli

    D=atof(argv[1]); // Assegnamento della distanza con la quale confrontare le distanze dei vari punti

    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dagli argomenti della riga di comando, passate poi alla funzione creaPunto del file punto.c */

    while(argv[i]!='\0'){
        x=atof(argv[i]);
        y=atof(argv[i+1]);
        p[cont]=creapunto(x,y);

        cont++;
        i+=2;
    }

    cont=0;

    /* Confronto e ricerca delle distanze, calcolate tramite apposita funzione nel file punto.c, di valore inferiore a quella inserita dall'utente */

    for(int j=0;j<num-1;j++){
        distance = distanza(p[j], p[j+1]);
        if(D>distance){
            cont++;
        }
    }

    // Stampa del risultato

    printf("\nIl numero di coppie di punti vicini la cui distanza risulta minore di D, equivale a: %d", cont);

    return 0;

}

