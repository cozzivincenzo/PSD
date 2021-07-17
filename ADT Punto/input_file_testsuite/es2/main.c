#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(int argc, char *argv[]){

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc<2){
        printf("\nErrore: non ci sono abbastanza argomenti\n");
        exit(-1);
    }



    FILE *test_suite; // Dichiarazione del file
    int num=0, cont=0; // Dichiarazione di variabili utili ai controlli
    float x, y, max=0, distance; // Dichiarazione delle variabili atte a contenere coordinate e distanze
    Punto output_p1, output_p2; // Dichiarazione delle variabili atte a contenere i punti da restituire in output

    test_suite = fopen(argv[1], "r"); // Apertura del file contenente test suite 


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
    test_suite=fopen(argv[1], "r");

    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dal file test_suite.txt, passate poi alla funzione creaPunto del file punto.c */
    
    while(fscanf(test_suite, "%f%f", &x, &y)==2){
        p[cont]=creapunto(x,y);
        cont++;
    }   


    /* Confronto e ricerca della distanza maggiore, trovata confrontando tra loro le distanze dei vari punti, calcolate tramite apposita funzione nel file punto.c */

    for(int j=0;j<num-1;j++){
        distance = distanza(p[j], p[j+1]);
        if(max<distance){
            max=distance;
            output_p1=p[j];
            output_p2=p[j+1];
        }
    }


    /* Stampa del risultato, utilizzando la funzione "stampa", del file punto.c, per stampare le variabili del tipo Punto */

    printf("\nLa distanza maggiore risulta essere quella tra i punti: ");
    stampa(output_p1);
    printf(" e ");
    stampa(output_p2);
    printf(", con il valore di: %f", max);

}