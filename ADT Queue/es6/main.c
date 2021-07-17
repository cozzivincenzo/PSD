#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

int main(void){

    int flag=0, del, num, key, queue_flag; // Dichiarazione e inizializzazione di variabili utili al controllo
    item input; // Dichiarazione di un item
    queue coda=newQueue(), nuovaCoda=newQueue(); // Dichiarazione e inizializzazione di due code
    
    /* Lettura in input del numero di stampe da inserire inizialmente in coda */
    printf("Quante stampe si vogliono accodare?\t");
    scanf("%d", &num);

    /* Ciclo utile al riempimento della coda */
    for (int i=0; i<num; i++){
    input=input_item(); // Chiamata alla funzione utile alla creazione di nuove stampe
        queue_flag=accoda(input, coda); // Chiamata alla funzione utile all'inserimento delle stampe nella coda
        /* Controllo del corretto inserimento del punto nella coda */
        if(queue_flag==0){
            printf("\n\nErrore di inserimento\n\n");
            exit(-1);
        }
    }

    /* Stampa in output della coda di stampa inizialmente */
    printf("\nLa coda di stampa risulta essere:\n");
    outputQueue(coda);

    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */
    while(flag==0){

        printf("\n\n1 -Aggiunta in coda di una stampa;"
                "\n2 -Aggiunta di una stampa in testa alla coda;"
                "\n3 -Rimozione di una stampa dalla coda in base all'id;"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);

        switch (key){
            case 1:
                input=input_item(); // Chiamata alla funzione utile alla creazione di punti
                queue_flag=accoda(input, coda); // Chiamata alla funzione utile all'inserimento dei punti nella coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(queue_flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }

                /* Stampa della nuova coda di stampa */
                printf("\nLa coda di stampa risulta ora essere:\n");
                outputQueue(coda);
            break;
            case 2:
                input=input_item(); // Chiamata alla funzione utile alla creazione di punti
                queue_flag=urgente(input, coda); // Chiamata alla funzione utile all'inserimento dei punti in testa alla coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(queue_flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }

                /* Stampa della nuova coda di stampa */
                printf("\nLa coda di stampa risulta ora essere:\n");
                outputQueue(coda);
            break;
            case 3:
         
                /* Lettura in input dell'ID da eliminare dalla coda di stampa */
                printf("\nInserire l'ID della stampa da eliminare:\t");
                scanf("%d", &del);

                nuovaCoda=annulla(coda, del); // Chiamata alla funzione annulla, passandole la coda originale e l'id da eliminare, assegnandone poi il risultato alla nuova coda

                /* Stampa del risultato */ 
                if(nuovaCoda==NULL){
                    printf("\nNon risulta nessuna stampa con quell'ID in coda");
                } else {
                    printf("\nLa stampa con ID %d è stata annullata, la coda di stampa risulta ora essere:\n", del);
                    outputQueue(nuovaCoda);
                }
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