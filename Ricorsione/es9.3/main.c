#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

int main(void){

    float x, y, somma=0; // Dichiarazione e inizializzazione di variabili utili ai calcoli;
    int flag, cont=0, size, scelta; // Dichiarazione e inizializzazione di variabili utili al controllo;
    item input, tmp1, tmp2; // Dichiarazione di item utili a riempire le code
    queue coda=newQueue(), q1=newQueue(), q2=newQueue(), q3=newQueue(), q4=newQueue(); // Dichiarazione e inizializzazione di tutte le code necessarie al funzionamento del programma

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

    x=0;
    cont=0;

    /* Ciclo utile a ripetere l'input da tastiera fin quando non viene inserito un valore valido */
    while(x==0){

        /* Lettura in input del quadrante di cui calcolare la spezzata */
        printf("\n\nDi quale dei quattro quadranti si desidera calcolare la spezzata?\t");
        scanf("%d",&flag);

        /* Switch utile alla selezione del quadrante di cui calcolare la spezzata */
        switch (flag) {
            case 1:
                while(scelta!=1&&scelta!=2){
                    printf("\nSi desidera la soluzione iterativa o ricorsiva?\n1) Iterativo;\n2) Ricorsivo;\nScelta:\t");
                    scanf("%d", &scelta);

                    if(scelta==1){
                        printf("La spezzata del primo quadrante vale: %0.2f\t\n\n", spezzataIterativa(q1)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    } else {
                        printf("La spezzata del primo quadrante vale: %0.2f\t\n\n", spezzataRicorsiva(q1, cont, somma)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    }
                }
            break;
            
            case 2:
                while(scelta!=1&&scelta!=2){
                    printf("\nSi desidera la soluzione iterativa o ricorsiva?\n-1 Iterativo;\n2-Ricorsivo;\nScelta:\t");
                    scanf("%d", &scelta);

                    if(scelta==1){
                        printf("La spezzata del secondo quadrante vale: %0.2f\t\n\n", spezzataIterativa(q2)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    } else {
                        printf("La spezzata del secondo quadrante vale: %0.2f\t\n\n", spezzataRicorsiva(q2, cont, somma)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    }
                }
            break;

            case 3:
                while(scelta!=1&&scelta!=2){
                    printf("\nSi desidera la soluzione iterativa o ricorsiva?\n-1 Iterativo;\n2-Ricorsivo;\nScelta:\t");
                    scanf("%d", &scelta);

                    if(scelta==1){
                        printf("La spezzata del terzo quadrante vale: %0.2f\t\n\n", spezzataIterativa(q3)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    } else {
                        printf("La spezzata del terzo quadrante vale: %0.2f\t\n\n", spezzataRicorsiva(q3, cont, somma)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    }
                }
            break;

            case 4:
                while(scelta!=1&&scelta!=2){
                    printf("\nSi desidera la soluzione iterativa o ricorsiva?\n-1 Iterativo;\n2-Ricorsivo;\nScelta:\t");
                    scanf("%d", &scelta);

                    if(scelta==1){
                        printf("La spezzata del quarto quadrante vale: %0.2f\t\n\n", spezzataIterativa(q4)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    } else {
                        printf("La spezzata del quarto quadrante vale: %0.2f\t\n\n", spezzataRicorsiva(q4, cont, somma)); // Stampa del risultato
                        x=1; // Assegnamento di un valore diverso da 0 alla sentinella, in modo da causare l'uscita del ciclo 
                    }
                }
            break;

            default:
                printf("\n\nInserire un numero compreso tra 1 e 4\n\n"); //Stampa di un messaggio d'errore in caso l'utente inserisca un valore non corrispondente ai quattro quadranti 
            break;
        }
    }


    return 0;

}