#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(void){

    float x, y, max=0, distance;  // Dichiarazione delle variabili atte a contenere coordinate e distanze
    int num, cont=0; // Dichiarazione di variabili utili ai controlli
    Punto output_p1, output_p2; // Dichiarazione delle variabili atte a contenere i punti da restituire in output
    

    /* Presa in input del numero di punti da voler inserire */

    printf("Quanti punti si vogliono inserire?\t");
    scanf("%d", &num);

    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo in input le coordinate (x;y), passate poi alla funzione creaPunto del file punto.c */

    for(int i=0; i<num; i++){
        
        printf("\nInserire l'ascissa del %d' punto: ", i+1);
        scanf("%f", &x);

        printf("\nInserire l'ordinata del %d' punto: ", i+1);
        scanf("%f", &y);

        p[i]=creapunto(x, y);

    }


    /* Confronto e ricerca della distanza maggiore, trovata confrontando tra loro le distanze dei vari punti, calcolate tramite apposita funzione nel file punto.c */

    for(int i=0;i<num-1;i++){
        distance = distanza(p[i], p[i+1]);
        if(max<distance){
            max=distance;
            output_p1=p[i];
            output_p2=p[i+1];
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