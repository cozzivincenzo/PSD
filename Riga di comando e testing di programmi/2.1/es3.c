#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct parola{
    char *vocali;
    char *consonanti;
} Parola;

Parola vocali_consonanti(char string[]);

int main(int argc, char **argv){

    if(argc!=2){
        printf("Per far funzionare questo programma bisogna dare esattamente una stringa, strunz");
        exit(1);
    }

    Parola output = vocali_consonanti(argv[1]);

    printf("\nVocali: %s", output.vocali); // Stampa delle vocali
    printf("\nConsonanti: %s", output.consonanti); // Stampa delle consonanti

    return 0;
}

Parola vocali_consonanti(char string[]){

    Parola parola; // Dichiarazione di una variabile di tipo Parola atta a contenere vocali e consonanti
 
    parola.vocali=malloc(0); // Allocazione dinamica della memoria, inizialmente a 0 in quanto non si sa se ci saranno o no vocali
    parola.consonanti=malloc(0); // Allocazione dinamica della memoria, inizialmente a 0 in quanto non si sa se ci saranno o no consonanti


    int i=0, j=1, k=1; // Dichiarazione e inizializzazione di variabili utili al controllo

    /* Utilizzo di un ciclo per dividere la parola in vocali e consonanti */

    while(string[i]!='\0'){

        if(isalpha(string[i])){  // Controllo della presenza di cifre o simboli nell'array

            if(string[i]!='a'&&string[i]!='e'&&string[i]!='i'&&string[i]!='o'&&string[i]!='u'&&string[i]!='A'&&string[i]!='E'&&string[i]!='I'&&string[i]!='O'&&string[i]!='U'){

                realloc(parola.consonanti, sizeof(char)*(j)); // Riallocazione dinamica della memoria nel momento in cui si trova una consonante
                parola.consonanti[j-1]=string[i]; 
                j++;

            } else {

                realloc(parola.vocali, sizeof(char)*(k)); // Riallocazione dinamica della memoria nel momento in cui si trova una vocale
                parola.vocali[k-1]=string[i];   
                k++;

            }
        }

        i++;    
    }

    parola.consonanti[j-1] = '\0'; // Applicazione del tappo
    parola.vocali[k-1] = '\0'; // Applicazione del tappo

    return parola;

}