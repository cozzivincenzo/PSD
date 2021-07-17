#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(void){

    float x, y, D, distance;  // Dichiarazione delle variabili atte a contenere coordinate e distanze
    int num, cont=0; // Dichiarazione di variabili utili ai controlli
    

    // Presa in input del numero di punti da voler inserire

    printf("Quanti punti si vogliono inserire?\t");
    scanf("%d", &num);


    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num

    
    // Presa in input della distanza con la quale confrontare le distanze dei vari punti

    printf("\nInserire la D: ");
    scanf("%f", &D);

    /* Creazione dei vari punti prendendo in input le coordinate (x;y), passate poi alla funzione creaPunto del file punto.c */

    for(int i=0; i<num; i++){
        
        printf("\nInserire l'ascissa del %d' punto: ", i+1);
        scanf("%f", &x);

        printf("\nInserire l'ordinata del %d' punto: ", i+1);
        scanf("%f", &y);

        p[i]=creapunto(x, y);

    }

    // Confronto e ricerca delle distanze, calcolate tramite apposita funzione nel file punto.c, di valore inferiore a quella inserita dall'utente

    for(int i=0;i<num-1;i++){
        distance = distanza(p[i], p[i+1]);
        if(D>distance){
            cont++;
        }
    }

    // Stampa del risultato

    printf("\nIl numero di coppie di punti vicini la cui distanza risulta minore di D, equivale a: %d", cont);

    return 0;

}