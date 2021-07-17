#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

# define M 50

int main(int argc, char *argv[]){

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc<3){
        printf("\nErrore: non ci sono abbastanza argomenti");
        exit(-1);
    }

    FILE *test_suite; // Dichiarazione del file
    int num=0, cont=0; // Dichiarazione di variabili utili ai controlli
    float x, y, D = atof(argv[1]), distance; // Dichiarazione delle variabili atte a contenere coordinate e distanze

    test_suite = fopen(argv[2], "r"); // Apertura del file contenente test suite  


    /* Controllo della corretta apertura del file */

    if(test_suite==NULL ) {
        printf("Errore in apertura del file \n");    
        exit(-1);
    }


    /* Conteggio del numero di coppie di coordinate presenti nel file */

    while(fscanf(test_suite, "%f%f", &x, &y)==2){
        num++;
    }  


    /* Chiusura e riapertura del file in modo tale da poter ricominciare a leggere dalla prima riga */

    fclose(test_suite); 
    test_suite=fopen(argv[2], "r");



    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dal file test_suite.txt, passate poi alla funzione creaPunto del file punto.c */
    
    while(fscanf(test_suite, "%f%f", &x, &y)==2){
        p[cont]=creapunto(x,y);
        cont++;
    }   

    cont=0;


    // Confronto e ricerca delle distanze, calcolate tramite apposita funzione nel file punto.c, di valore inferiore a quella inserita dall'utente

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

