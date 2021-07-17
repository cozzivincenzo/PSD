#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

int main (void){
    
	int num, sinistro, destro; // Dichiarazione di variabili utili al controllo
    item val; // Dichiarazione di un elemento
    list lista=newList(); // Dichiarazione e inizializzazione di una lista

    /* Presa in input del numero di elementi da mettere in lista */
    printf("Quanti elementi si vogliono inserire nella lista?\t");
    scanf("%d", &num);

    /* Ciclo utile all'inserimento degli elementi nella lista */
    for(int i=0; i<num; i++) {
        printf("Inserire il %d' numero:\t", i+1);
        input_item(&val);
        lista=consList(val, lista);
    }

    /* Lettura in input degli estremi da cui estrapolare la sottolista */
    printf("\nInserire l'estremo sinistro:\t");
    scanf("%d", &sinistro);
    while(sinistro<0 || sinistro>sizeList(lista)){
        printf("\nL'estremo sinistro deve rientrare negli elementi della lista.\n Si prega di reinserirlo:\t");
        scanf("%d", &sinistro);
    }

    printf("\nInserire l'estremo destro:\t");
    scanf("%d", &destro);
    while(destro<sinistro || destro>sizeList(lista)){
        printf("\nL'estremo destro deve rientrare negli elementi della lista e dev'essere maggiore del sinistro.\n Si prega di reinserirlo:\t");
        scanf("%d", &destro);
    }

    list sublist=newList(); // Dichiarazione e inizializzazione di una nuova lista
    sublist=sottolista(lista, sublist, sinistro, destro, sizeList(lista)); // Chiamata alla funzione utile alla creazione della sottolista

    /* Stampa della sottolista */
    printf("\nLa sottolista creata risulta avere i seguenti elementi:\n");
    outputList(sublist);
    
	return 0;
}
