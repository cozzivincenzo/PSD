#include "functions.h"

int main(void){

    float x, y; // Dichiarazione delle variabili atte a contenere le coordinate
    int num; // Dichiarazione di variabili utili ai controlli
    char criterio, coordinata; // Dichiarazione delle stringhe atte a contenere criterio e coordinata sui quali basare l'ordinamento
    

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


    /* Presa in input di criterio e coordinata */

    fflush(stdin);
    printf("\nSecondo quale criterio si desidera riordinare i punti? (c->crescente/d->decrescente) ");
    scanf("%c", &criterio);

    fflush(stdin);
    printf("\nSecondo quale coordinata si desidera riordinare i punti? (a->ascissa/o->ordinata)\t");
    scanf("%c", &coordinata);
    

    // Chiamata alla sottofunzione utile a gestire il riordinamento dell'array di punti

    riordina(p, coordinata, criterio, num);


}