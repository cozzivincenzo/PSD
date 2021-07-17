#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

# define MAX_CLOCK 4

int main(void){

    int flag=0, burst, num, key, queue_flag; // Dichiarazione e inizializzazione di variabili utili al controllo
    item input; // Dichiarazione di un item
    queue coda=newQueue(); // Dichiarazione e inizializzazione di una coda
    
    /* Lettura in input del numero da processi da inserire nella coda */ 
    printf("Quante processi si vogliono accodare?\t");
    scanf("%d", &num);

    /* Ciclo utile al riempimento della coda */
    for (int i=0; i<num; i++){
    input=input_item(); // Chiamata alla funzione utile alla creazione di nuovi clock
        queue_flag=accoda(input, coda); // Chiamata alla funzione utile all'inserimento dei clock nella coda
        /* Controllo del corretto inserimento del punto nella coda */
        if(queue_flag==0){
            printf("\n\nErrore di inserimento\n\n");
            exit(-1);
        }
    }

    /* Stampa in output della coda iniziale */
    printf("\nLa coda di processi risulta essere:\n");
    outputQueue(coda);

    /* Ciclo utile a ripetere i clock fin quando la coda non risulta essere vuota */
    while(getSize(coda)>0){
        input=dequeue(coda); // Prelievo del primo item presente in coda
        if(getBurst(input)>MAX_CLOCK){ // Se il burst del clock risulta essere maggiore del MAX_CLOCK:
            burst=getBurst(input)-MAX_CLOCK; // calcolo del burst rimanente;
            setBurst(input, burst); // aggiornamento del burst;
            queue_flag=accoda(input, coda); // reinserimento del clock nella coda;
            /* Controllo del corretto inserimento del punto nella coda */
            if(queue_flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        }
        /* Controllo della presenza di elementi nella coda */
        if(getSize(coda)==0){
            printf("\n\nLa coda di processi risulta essere completa, non c'e' mai stato Batman qui a Gotham\n\n"); // Stampa del completamento dei processi con successo
        } else {
            /* Stampa della coda aggiornata */
            printf("\n\nLa coda risulta ora essere:\n");
            outputQueue(coda);
        }
    }

    return 0;

}