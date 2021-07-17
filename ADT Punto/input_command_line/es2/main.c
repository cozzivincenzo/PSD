#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(int argc, char *argv[]){

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc<3 || (argc-1)%2!=0){
        printf("\nErrore: non ci sono abbastanza argomenti\n");
        exit(-1);
    }

    float x, y, max=0, distance; // Dichiarazione delle variabili atte a contenere coordinate e distanze
    int num=(argc-2)/2, cont=0, i=1; // Dichiarazione di variabili utili ai controlli

    Punto output_p1, output_p2; // Dichiarazione delle variabili atte a contenere i punti da restituire in output

    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dagli argomenti della riga di comando, passate poi alla funzione creaPunto del file punto.c */

    while(argv[i]!='\0'){
        x=atof(argv[i]);
        y=atof(argv[i+1]);
        p[cont]=creapunto(x,y);

        cont++;
        i+=2;
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

    return 0;

}