#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

int main (void){
    
    int num, flag=0, key, pos; // Dichiarazione di variabili utili al controllo
    item val; // Dichiarazione di un elemento
    list reverse=newList(), lista=newList(); // Dichiarazione e inizializzazione di due liste 

    /* Presa in input del numero di elementi da mettere in lista */
    printf("Quanti elementi si vogliono inserire nella lista?\t");
    scanf("%d", &num);

    /* Ciclo utile all'inserimento degli elementi nella lista */
    for(int i=0; i<num; i++) {
        printf("Inserire il %d' numero:\t", i+1); 
        input_item(&val);
        lista=consList(val, lista);
    }
    reverse=reverseList(lista);

    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */
    while(flag==0){

        printf("\n\n1 -Stampa degli elementi della lista;"
                "\n2 -Ricerca di un elemento nella lista;"
                "\n3 -Ricerca di una posizione nella lista;"
                "\n4 -Stampa del reverse della lista;"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);

        switch (key){
            case 1:
                outputList(reverse); // Chiamata alla funzione outputList passandogli la lista inversa per stamparla in ordine d'inserimento
            break;
            case 2:

                /* Presa in input del valore da cercare */
                printf("Inserire l'elemento da cercare:\t");
                scanf("%d", &val);

                /* Controllo dell'effettiva presenza del valore nella lista, con stampa dei risultati */
                if(posItem(lista, val)==-1){ 
                    printf("\n\nL'elemento cercato non risulta presente in lista\n\n");
                } else {
                    printf("\n\nL'elemento si trova alla posizione %d\n\n", posItem(lista, val));
                }
                
            break;
            case 3:

                /* Presa in input della posizione da cercare */
                printf("Inserire la posizione da cercare:\t");
                scanf("%d", &val);

                /* Controllo dell'effettiva presenza della posizione nella lista, con stampa dei risultati */
                if(getItem(reverse, val)==NULL){
                    printf("\n\nNon risulta esserci nessun elemento alla posizione %d\n\n", val);
                } else {
                    printf("\n\nL'elemento alla posizione %d risulta essere %d\n\n", val, getItem(reverse, val)); 
                }  
            break;
            case 4:
                outputList(lista); // Chiamata alla funzione outputList passandogli la lista originale per stamparla in ordine inverso
            break;
            case 0:
                flag=1;
            break;
            default:
                printf("\n\nSi prega di selezionare una delle opzioni\n\n");
            break;
        }


    }

    return 0;
}
