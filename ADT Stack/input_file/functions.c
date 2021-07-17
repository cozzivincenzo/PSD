#include "functions.h"

/* FUNZIONE UTILE A RIMUOVERE LO \n DA UNA STRINGA */
char *dropN(char *str){
    if(str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0'; // Sostituzione dell'ultimo carattere, solo se risulta essere \n, con il carattere tappo
    return str;
}

/* FUNZIONE UTILE A LAVORARE SU UN NUOVO STACK, INVERTENDOLO, UNENDOLO ALLA SUA REVERSE ED ELIMINANDONE ELEMENTI */
void processo(void){

    FILE *file; // Dichiarazione di un file
    char input_fname[MAX]; // Dichiarazione della stringa atta a contenere il nome del file
    int flag; // Dichiarazione di una variabile di controllo
    item input; // Dichiarazione di un item
    stack s=newStack(); // Dichiarazione e inizializzazione di uno stack

    /* Lettura in input del file da cui prendere i valori da inserire nello stack */
    printf("Inserire il file di cui processare lo stack:\t");
    scanf("%s", &input_fname);

    file=fopen(input_fname, "r"); // Apertura in lettura del file
    /* Controllo della corretta apertura del file */
    if(file==NULL){
        printf("Errore nell'apertura del file");
        exit(-1);
    }

    /* Ciclo utile all'inserimento degli elementi del file nello stack */
    while(!feof(file)){
        input=input_item_file(file);
        push(input, s);
    }

    stack reverseS=reverseStack(s); // Chiamata alla funzione reverseStack per salvare lo stack inverso
    
    /* Stampa dello stack originale e dello stack inverso */
    printf("\n\nLo stack risulta essere:\n");
    output_stack(s);
    printf("\n");
    printf("\nLo stack invertito risulta essere:\n");
    output_stack(reverseS);

    stack mergedStack=merge(s, reverseS); // Chiamata alla funzione merge per salvare l'unione dello stack originale e dello stack inverso

    /* Stampa dell'unione dei due stack */
    printf("\n\nUnendo i due stack, il risultato risulta essere:\n");
    output_stack(mergedStack);

    /* Lettura in input del valore da ricercare ed eliminare nello stack */
    printf("\n\n\nChe valore si desidera eliminare dallo stack?\t");
    input_item(&input);

    mergedStack=estrazione(mergedStack, input); // Chiamata alla funzione utile a cancellare i valori dallo stack

    /* Stampa dello stack con i valori aggiornati */
    printf("\n");
    printf("\nLo stack risulta ora essere:\n");
    output_stack(mergedStack);
}

/* FUNZIONE UTILE ALLA CONVERSIONE DI UN NUMERO DA BASE BINARIA A BASE DECIMALE */
void conversioneDecBin(void){

    FILE *file; // Dichiarazione di un file
    char input_fname[MAX]; // Dichiarazione della stringa atta a contenere il nome del file
    item input; // Dichiarazione di un item 
    int resto, flag; // Dichiarazione di variabili di controllo
    stack s=newStack(); // Dichiarazione e inizializzazione di un nuovo stack

    /* Lettura in input del file da cui prendere i numeri da convertire in base binaria */
    printf("Inserire il file di cui prendere i numeri da processare in binario:\t");
    scanf("%s", &input_fname);

    file=fopen(input_fname, "r"); // Apertura in lettura del file
    /* Controllo della corretta apertura del file */
    if(file==NULL){
        printf("Errore nell'apertura del file");
        exit(-1);
    }

    /* Ciclo utile alla conversione di tutti gli elementi che si trovano nel file */
    while(!feof(file)){
        input=input_item_file(file); // Lettura dal file dell'item

        /* Stampa dell'item */
        printf("\n");
        output_item(input);
        printf(" in binario equivale a:\n");

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
        output_stack(s);
        printf("\n");
        s=newStack();
    }
}

/* FUNZIONE UTILE ALLA RISOLUZIONE DI UN'ESPRESSIONE IN NOTAZIONE POLACCA */
void conversionePostIn(void){

    FILE *file;
    item val, tmp1, tmp2, result; // Dichiarazione di item utili ai calcoli
    char tmp[5], input_fname[MAX], str[MAX]; // Dichiarazione di stringhe temporanee
    int cont=0, flag=0; // Dichiarazione e inizializzazione di variabili utili al controllo
    stack s=newStack(); // Dichiarazione e inizializzazione di uno stack

    /* Lettura in input dell'espressione in notazione polacca */
    printf("Inserire il file di cui prendere le espressioni in notazione polacca:\t");
    scanf("%s", &input_fname);
    printf("\n");

    file=fopen(input_fname, "r"); // Apertura in lettura del file
    /* Controllo della corretta apertura del file */
    if(file==NULL){
        printf("Errore nell'apertura del file");
        exit(-1);
    }
    printf("\n");

    /* Ciclo utile alla conversione di tutti gli elementi che si trovano nel file */
    while(!feof(file)){

        fgets(str, 50, file);

        /* Ciclo utile allo scorrimento di tutta la stringa passata dalla funzione chiamante */
        for(int i=0; i<strlen(str); i++){

            /* Controllo del carattere attuale */  
            if(str[i]>='0' && str[i]<='9'){ // In caso sia una cifra:
                tmp[cont]=str[i]; // il carattere viene salvato nella stringa temporanea;
                cont++; // l'indice della stringa viene incrementato;
            }  else if (str[i]=='*' || str[i]=='-' || str[i]=='+' || str[i]=='/' ) { // In caso sia un operatore matematico:
                tmp1=top(s); // il valore in top viene salvato in un item temporaneo
                pop(s); // scorrimento dello stack
                tmp2=top(s); // il valore in top viene salvato in un item temporaneo
                pop(s); // scorrimento dello stack

                /* Switch utile alla selezione dell'operazione da fare (in alternativa a 4 if annidati) */
                switch (str[i]) {
                case '*':

                    /* Stampa dell'operazione eseguita */
                    printf("\nMoltiplicazione tra ");
                    output_item(tmp2);
                    printf(" e ");
                    output_item(tmp1);
                    
                    result=tmp1*tmp2; // Calcolo del risultato
                    push(result, s); // Push del risultato nello stack
                break;
                case '-':

                    /* Stampa dell'operazione eseguita */
                    printf("\nSottrazione tra ");
                    output_item(tmp2);
                    printf(" e ");
                    output_item(tmp1);

                    result=tmp2-tmp1; // Calcolo del risultato
                    push(result, s); // Push del risultato nello stack
                break;
                case '+':

                    /* Stampa dell'operazione eseguita */
                    printf("\nAddizione tra ");
                    output_item(tmp2);
                    printf(" e ");
                    output_item(tmp1);

                    result=tmp1+tmp2; // Calcolo del risultato
                    push(result, s); // Push del risultato nello stack
                break;
                case '/':

                    /* Stampa dell'operazione eseguita */
                    printf("\nDivisione tra ");
                    output_item(tmp2);
                    printf(" e ");
                    output_item(tmp1);
                    result=(float)tmp2/tmp1; // Calcolo del risultato
                    push((float)result, s); // Push del risultato nello stack
                break;
                }
            } else { // Se il carattere non è nè una cifra nè un operatore:
                if(cont==0){ // Si fa un controllo sull'indice del carattere, in caso sia 0 salta direttamente alla prossima iterazione
                    continue;
                }
                val=char_to_item(tmp); // Chiamata alla funzione utile a convertire la stringa in item
                push(val, s); // Push dell'item nello stack

                /* Ciclo utile a svuotare la stringa temporanea */
                for(int i=0; i<cont; i++){
                    tmp[i]="";
                }

                cont=0; // Reinizializzazione dell'indice della stringa temporanea
            }
        }

        // Stampa del risultato
        dropN(str);
        printf("\nL'espressione %s vale:\t", str);
        output_stack(s);
        printf("\n");
        s=newStack();
    }

    
}