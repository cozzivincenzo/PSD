#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

int main(void){

    float x, y, somma=0; // Dichiarazione e inizializzazione di variabili utili ai calcoli;
    int flag, cont=0, size; // Dichiarazione e inizializzazione di variabili utili al controllo;
    item input, tmp1, tmp2; // Dichiarazione di item utili a riempire le code
    queue coda=newQueue(), q1=newQueue(), q2=newQueue(), q3=newQueue(), q4=newQueue(), simm13=newQueue(), simm24=newQueue(); // Dichiarazione e inizializzazione di tutte le code necessarie al funzionamento del programma
    
    /* Ciclo utile all'inserimento degli elementi nella coda */
    while(1){
        input=input_item(); // Chiamata alla funzione utile alla creazione di punti
        if(input==NULLITEM){ // In caso il punto risulti NULLITEM, il ciclo si stoppa
            break;
        } else {
            flag=enqueue(input, coda); // Chiamata alla funzione utile all'inserimento dei punti nella coda
            /* Controllo del corretto inserimento del punto nella coda */
            if(flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        }
    }

    /* Stampa della coda iniziale */
    printf("La coda iniziale risulta essere:\n");
    outputQueue(coda); // Chiamata alla funzione utile alla stampa della coda

    size=getSize(coda); // Chiamata alla funzione getSize per ottenere il numero di elementi presenti nella coda

    /* Ciclo utile alla creazione delle sottocode dei quadranti */
    for(int i=0;i<size; i++){

        input=dequeue(coda); // Rimozione e prelievo del punto in testa alla coda
        x=ascissa(input); // Chiamata alla funzione ascissa per l'ottenimento dell'ascissa
        y=ordinata(input); // Chiamata alla funzione ordinata per l'ottenimento dell'ordinata

        /* Serie di condizioni annidate utili a "instradare" ogni punto nella coda corrispondente al suo quadrante di appartenenza */
        if(x==0&&y==0){
            cont++;
        } else if(x>=0&&y>=0){
            flag=enqueue(input, q1); // Chiamata alla funzione utile all'inserimento dei punti nella coda
            /* Controllo del corretto inserimento del punto nella coda */
            if(flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        } else if (x<=0&&y>=0){
            flag=enqueue(input, q2); // Chiamata alla funzione utile all'inserimento dei punti nella coda
            /* Controllo del corretto inserimento del punto nella coda */
            if(flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        } else if (x<=0&&y<=0){
            flag=enqueue(input, q3); // Chiamata alla funzione utile all'inserimento dei punti nella coda
            /* Controllo del corretto inserimento del punto nella coda */
            if(flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        } else {
            flag=enqueue(input, q4); // Chiamata alla funzione utile all'inserimento dei punti nella coda
            /* Controllo del corretto inserimento del punto nella coda */
            if(flag==0){
                printf("\n\nErrore di inserimento\n\n");
                exit(-1);
            }
        }
    }

    /* Stampa delle code dei quattro quadranti, se non vuote */
    if(!emptyQueue(q1)){
        printf("\nNel primo quadrante ci sono i seguenti punti:\n");
        outputQueue(q1); // Chiamata alla funzione utile alla stampa della coda
    }
    if(!emptyQueue(q2)){
        printf("\nNel secondo quadrante ci sono i seguenti punti:\n");
        outputQueue(q2); // Chiamata alla funzione utile alla stampa della coda
    }
    if(!emptyQueue(q3)){
        printf("\nNel terzo quadrante ci sono i seguenti punti:\n");
        outputQueue(q3); // Chiamata alla funzione utile alla stampa della coda
    }
    if(!emptyQueue(q4)){
        printf("\nNel quarto quadrante ci sono i seguenti punti:\n");
        outputQueue(q4); // Chiamata alla funzione utile alla stampa della coda
    }
    if(cont!=0){
        printf("\nAll'origine sono stati trovati %d punti, che non rientrano quindi in nessun quadrante\n", cont);
    }
    printf("\n\n");

    /* Ciclo utile a confrontare ogni punto della prima coda con ogni punto della terza coda */
    for(int i=0; i<getSize(q1); i++){
        tmp1=getItem(q1, i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
        for(int j=0; j<getSize(q3); j++){
            tmp2=getItem(q3, j); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
            if(ascissa(tmp1)==ascissa(tmp2)*-1 && ordinata(tmp1)==ordinata(tmp2)*-1){ // Condizione necessaria affinchè i punti siano simmetrici
                flag=enqueue(tmp1, simm13); // Chiamata alla funzione utile all'inserimento dei punti nella coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }
                flag=enqueue(tmp2, simm13); // Chiamata alla funzione utile all'inserimento dei punti nella coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }
            }
        }
    }

    /* Ciclo utile a confrontare ogni punto della seconda coda con ogni punto della quarta coda */
    for(int i=0; i<getSize(q2); i++){
        tmp1=getItem(q2, i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
        for(int j=0; j<getSize(q4); j++){
            tmp2=getItem(q4, j); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
            if(ascissa(tmp1)==ascissa(tmp2)*-1 && ordinata(tmp1)==ordinata(tmp2)*-1){
                flag=enqueue(tmp1, simm24); // Chiamata alla funzione utile all'inserimento dei punti nella coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }
                flag=enqueue(tmp2, simm24); // Chiamata alla funzione utile all'inserimento dei punti nella coda
                /* Controllo del corretto inserimento del punto nella coda */
                if(flag==0){
                    printf("\n\nErrore di inserimento\n\n");
                    exit(-1);
                }
            }
        }
    }

    /* Stampa delle code contenenti le simmetrie, se non vuote */
    if(!emptyQueue(simm13)){
        printf("I punti simmetrici nel primo e terzo quadrante sono:\n");
        outputQueue(simm13); // Chiamata alla funzione utile alla stampa della coda
    } else {
        printf("Non sono stati trovati punti simmetrici nel primo e terzo quadrante");
    }
    printf("\n\n");
    if(!emptyQueue(simm24)){
        printf("I punti simmetrici nel secondo e quarto quadrante sono:\n");
        outputQueue(simm24); // Chiamata alla funzione utile alla stampa della coda
    } else {
        printf("Non sono stati trovati punti simmetrici nel primo e terzo quadrante");
    }
    

    x=0; // Reinizializzazione della variabile x per usarla come valore sentinella nel ciclo

    /* Ciclo utile a ripetere l'input da tastiera fin quando non viene inserito un valore valido */
    while(x==0){

        /* Lettura in input del quadrante di cui calcolare la spezzata */
        printf("\n\nDi quale dei quattro quadranti si desidera calcolare la spezzata?\t");
        scanf("%d",&flag);

        /* Switch utile alla selezione del quadrante di cui calcolare la spezzata */
        switch (flag) {
            case 1:
                /* Ciclo utile allo scorrimento di tutta la coda */
                for(int i=0; i<getSize(q1)-1; i++){
                    tmp1=getItem(q1,i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
                    tmp2=getItem(q1,i+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
                    somma+=distanza(tmp1, tmp2); // Incremento del valore somma per la distanza tra i due punti appena prelevati
                }
                printf("La spezzata del primo quadrante vale: %0.2f\t", somma); // Stampa del risultato
                x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
            break;
            
            case 2:
                /* Ciclo utile allo scorrimento di tutta la coda */
                for(int i=0; i<getSize(q2)-1; i++){
                    tmp1=getItem(q2,i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
                    tmp2=getItem(q2,i+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
                    somma+=distanza(tmp1, tmp2); // Incremento del valore somma per la distanza tra i due punti appena prelevati
                }
                printf("La spezzata del primo quadrante vale: %0.2f\t", somma); // Stampa del risultato
                x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
            break;

            case 3:
                /* Ciclo utile allo scorrimento di tutta la coda */
                for(int i=0; i<getSize(q3)-1; i++){
                    tmp1=getItem(q3,i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
                    tmp2=getItem(q3,i+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
                    somma+=distanza(tmp1, tmp2); // Incremento del valore somma per la distanza tra i due punti appena prelevati
                }
                printf("La spezzata del primo quadrante vale: %0.2f\t", somma); // Stampa del risultato
                x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
            break;

            case 4:
                /* Ciclo utile allo scorrimento di tutta la coda */
                for(int i=0; i<getSize(q4)-1; i++){
                    tmp1=getItem(q4,i); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo 
                    tmp2=getItem(q4,i+1); // Chiamata alla funzione utile all'ottenimento del valore in testa alla coda senza eliminarlo
                    somma+=distanza(tmp1, tmp2); // Incremento del valore somma per la distanza tra i due punti appena prelevati
                }
                printf("La spezzata del primo quadrante vale: %0.2f\t", somma); // Stampa del risultato
                x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
            break;

            default:
                printf("\n\nInserire un numero compreso tra 1 e 4\n\n"); //Stampa di un messaggio d'errore in caso l'utente inserisca un valore non corrispondente ai quattro quadranti 
            break;
        }
    }

    queue codaFinale=newQueue(); // Dichiarazione e inizializzazione di una coda destinata a contenere l'unione delle 4 sottocode in ordine di 
    coda=newQueue(); // Reinizializzazione della coda iniziale per usarla come valore temporaneo

    coda=concatena(q2, q1); // Chiamata alla funzione utile a unire due code
    codaFinale=concatena(q4, q3); // Chiamata alla funzione utile a unire due code

    codaFinale=concatena(codaFinale, coda); // Chiamata alla funzione utile a unire due code

    /* Stampa dell'unione delle quattro sottocode in ordine di quadrante decrescente */
    printf("\n\nLa coda finale risulta essere:\n");
    outputQueue(codaFinale); // Chiamata alla funzione utile alla stampa della coda


    return 0;

}