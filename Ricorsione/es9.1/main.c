#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

int main (void){
    
    int num, flag=0, key; // Dichiarazione di variabili utili al controllo
    item val; // Dichiarazione di un elemento
    list lista=newList(); // Dichiarazione e inizializzazione della lista

    /* Presa in input del numero di elementi da mettere in lista */
    printf("Quanti elementi si vogliono inserire nella lista?\t");
    scanf("%d", &num);

    /* Ciclo utile all'inserimento degli elementi nella lista */
    for(int i=0; i<num; i++) {
        printf("Inserire il %d' numero:\t", i+1); 
        input_item(&val);
        lista=consList(val, lista);
    }

    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */

    while(flag==0){

        printf("\n\n1 -Conteggio del numero di elementi in maniera iterativa;"
                "\n2 -Conteggio del numero di elementi in maniera ricorsiva;"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);

        switch (key){
            case 1:
                printf("\n\nIl conteggio iterativo da come risultato: %d\n\n", sizeList(lista)); // Chiamata alla funzione utile all'ottenimento della grandezza della lista iterativamente
            break;
            case 2:
                printf("\n\nIl conteggio ricorsivo da come risultato: %d\n\n", contaRicorsivo(lista)-1); // Chiamata alla funzione utile all'ottenimento della grandezza della lista ricorsivamente
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
