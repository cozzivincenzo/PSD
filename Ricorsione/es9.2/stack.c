#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

#define STARTSIZE 5  // Definizione della grandezza iniziale dello stack

/* STRUTTURA CHE IDENTIFICA LO STACK */   
struct Stack {
    item *vet;
    int size;  
    int top; 
};

/* FUNZIONE UTILE A CREARE UN NUOVO STACK */
stack newStack(void) {
    stack s = malloc (sizeof(struct Stack)); // Allocazione dinamica della memoria per lo stack
    /* Controllo della corretta allocazione della memoria */
    if (s == NULL){
        return NULL;
    }
    s->vet = malloc(STARTSIZE * sizeof(item)); // Allocazione dinamica della memoria per l'item dello stack */
    /* Controllo della corretta allocazione della memoria */
    if (s->vet == NULL){
        return NULL;
    }
    s->size = STARTSIZE; // Impostazione della dimensione iniziale dello stack
    s->top = 0; // Impostazione del valore top come primo valore dello stack
    return s;
}

/* FUNZIONE UTILE A CONTROLLARE CHE LO STACK SIA VUOTO */
int emptyStack(stack s){
    return s->top == 0;
}

/* FUNZIONE UTILE ALL'INSERIMENTO DI NUOVI ELEMENTI NELLO STACK */
int push(item val, stack s)
{
    if (s->top == s->size) {  // Controllo del necessario resizing dello stack
	    item *tmp = realloc(s->vet, (s->size + 1) * sizeof(item)); // Riallocazione dinamica della memoria per l'aggiunta di un elemento
	    /* Controllo della corretta riallocazione dinamica */
        if (tmp == NULL){
            return 0; // Return 0 in caso di errore
        }
        s->vet = tmp;     	
        s->size = s->size + 1; // Incremento del valore size
    }
    s->vet[s->top] = val; // Aggiunta in top del nuovo valore
    (s->top)++; // Incremento del top
    return 1; // Return 1 in caso di successo
}

/* FUNZIONE UTILE ALLO SCORRIMENTO DELLO STACK */
void pop(stack s) {
    /* Controllo della presenza di elementi nello stack */
    if (s->top == 0){
        exit(-1);
    }    
    (s->top)--; // Decremento del top
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL PRIMO ELEMENTO DELLO STACK */
item top(stack s) {
    item e; // Dichiarazione di un item
    if(s->top > 0){ // Controllo della presenza di un numero positivo
        e = s->vet[s->top-1]; // Assegnamento del valore in posizione top all'item
    } else {
        e = NULLITEM; // Assegnamento di valore NULL in caso in top ci sia un numero negativo
    }
    return e; // Ritorno dell'item
}

/* FUNZIONE UTILE A INVERTIRE LO STACK */
stack reverseStack(stack s){
    int cont=0, flag; // Dichiarazione di variabili utili al controllo
    item *array=malloc(sizeof(item)*s->size); // Dichiarazione e allocazione dinamica della memoria ad un array di item
    stack reverseS=malloc(sizeof(struct Stack)*s->size); // Dichiarazione e allocazione dinamica della memoria ad uno stack
    
    /* Ciclo utile a salvare i valori del primo stack nell'array */
    while(!emptyStack(s)){
        array[cont]=top(s);
        pop(s);
        cont++;
    }

    /* Ciclo utile all'inserimento dei valori dell'array nello stack */
    for(int i=0; i<cont; i++){
        flag=push(array[i], reverseS); // Push del valore nello stack
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
    }

    rewindStack(s); // Chiamata alla funzione utile a ripartire dalla prima posizione dello stack

    return reverseS; // Ritorno dello stack
}

/* FUNZIONE UTILE ALL'UNIONE DI DUE STACK */
stack merge(stack s, stack reverseS){
    int cont=0, flag; // Dichiarazione di variabili utili al controllo
    item *array=malloc((sizeof(item)*s->size)*2); // Dichiarazione e allocazione dinamica della memoria ad un array di item
    stack mergedStack=malloc((sizeof(struct Stack)*s->size)*2); // Dichiarazione e allocazione dinamica della memoria ad uno stack

    /* Ciclo utile a salvare i valori del primo stack nell'array */
    while(!emptyStack(s)){
        array[cont]=top(s);
        pop(s);
        cont++;
    }

    /* Ciclo utile a salvare i valori del secondo stack nell'array */
    while(!emptyStack(reverseS)){
        array[cont]=top(reverseS);
        pop(reverseS);
        cont++;
    }

    /* Ciclo utile all'inserimento dei valori dell'array nello stack */
    for(int i=0; i<cont; i++){
        flag=push(array[i], mergedStack); // Push del valore nello stack
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
    }

    rewindStack(s); // Chiamata alla funzione utile a ripartire dalla prima posizione dello stack
    rewindStack(reverseS); // Chiamata alla funzione utile a ripartire dalla prima posizione dello stack

    return mergedStack; // Ritorno dello stack
}

/* FUNZIONE UTILE ALL'ELIMINAZIONE DI ELEMENTI DALLO STACK */
stack estrazione(stack s, item n){
    int cont=0, flag_push; // Dichiarazione di variabili utili al controllo
    item *array=malloc(sizeof(item)*s->size); // Dichiarazione e allocazione dinamica della memoria ad un array di item

    /* Ciclo utile a salvare i valori del secondo stack nell'array */
    while(!emptyStack(s)){
        array[cont]=top(s);
        pop(s);
        cont++;
    } 

    s=newStack(); // Reinizializzazione dello stack
    int flag=cont; // Assegnamento del contatore ad una variabile utile a controllare la presenza o meno del
    
    for(int i=0; i<cont; i++){
        if(array[i]==n){ // Se l'item alla posizione i risulta essere il valore da eliminare, si passerà direttamente alla prossima iterazione, non riscrivendolo nello stack
            flag--;
            continue;
        }
        flag_push=push(array[i], s); // Push del valore nello stack
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag_push==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
    }

    /* Stampa di un messaggio particolare in caso il flag risulti ancora uguale al contatore, quindi non è stato trovato alcun item col valore dato */
    if(flag==cont){ 
        printf("\nIl valore non e' presente nello stack");
    } 

    return s; // Ritorno dello stack

}

/* FUNZIONE UTILE ALLA STAMPA DELLO STACK */
void output_stack(stack s){

    /* Ciclo che si ripete fin quando ci sono elementi nello stack */
    while(!emptyStack(s)){
        /* Stampa dell'item */
        output_item(top(s));
        printf("|");

        pop(s); // Scorrimento dello stack
    }

    rewindStack(s); // Chiamata alla funzione utile al ripristino di lettura dello stack

}

/* FUNZIONE UTILE AL RIPRISTINO DI LETTURA DELLO STACK */
void rewindStack(stack s){
    s->top=s->size; // Assegnamento del top come primo valore dello stack
}

/* FUNZIONE UTILE ALLA CONVERSIONE DI UN NUMERO DA BASE BINARIA A BASE DECIMALE IN MODO ITERATIVO */
void conversioneDecBin(item input){

    int resto, flag; // Dichiarazione di variabili di controllo
    stack s=newStack(); // Dichiarazione e inizializzazione di un nuovo stack

    flag=push(input,s); // Inserimento del numero nello stack
    /* Stampa di errore in caso in cui il push non sia andato a buon fine */
    if(flag==0){
        printf("\n\nErrore di memoria\n\n");
        exit(-1);
    }

    /* Ciclo utile a scomporre il numero e salvare i valori nello stack */
    while(input>1){
        resto=input%2; // Ottenimento del resto della divisione
        input/=2; // Ottenimento del quoziente
        pop(s); // Pop del valore in top, quindi del quoziente
        flag=push(resto,s); // Push del resto
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
        flag=push(input,s); // Push del quoziente per secondo, in modo da averlo in top alla prossima iterazione
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
    }

    /* Stampa dello stack */
    printf("\n");
    output_stack(s);

}

/* FUNZIONE UTILE ALLA CONVERSIONE DI UN NUMERO DA BASE BINARIA A BASE DECIMALE IN MODO RICORSIVO */
item conversioneRicorsiva(item input, stack s){

    int r, flag; // Dichiarazione di variabili di controllo

    flag=push(input,s); // Inserimento del numero nello stack
    /* Stampa di errore in caso in cui il push non sia andato a buon fine */
    if(flag==0){
        printf("\n\nErrore di memoria\n\n");
        exit(-1);
    }

    if(input>1){
        r=input%2; // Ottenimento del resto della divisione
        input/=2; // Ottenimento del quoziente
        pop(s); // Pop del valore in top, quindi del quoziente
        flag=push(r,s); // Inserimento del numero nello stack
        /* Stampa di errore in caso in cui il push non sia andato a buon fine */
        if(flag==0){
            printf("\n\nErrore di memoria\n\n");
            exit(-1);
        }
        input=conversioneRicorsiva(input, s); // Richiamo della funzione
    }

}