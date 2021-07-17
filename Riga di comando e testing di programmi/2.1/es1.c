#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc < 3){
        printf("Argomenti insufficienti");
        exit(1);
    }

    char *first_string=argv[1], *second_string=argv[2], *result; // Dichiarazione e inizializzazione delle stringhe contenenti le parole da concatenare
    int sum = strlen(first_string) + strlen(second_string); // Dichiarazione e inizializzazione di una variabile utile a contenere la dimensione della stringa risultante

    result = malloc(sizeof(char) * sum); // Allocazione dinamica di memoria per la stringa risultante

    /* Controllo della corretta allocazione di memoria */

    if(!result)
    {   
        fprintf(stderr, "Memoria insufficiente\n");
        exit(-1);
    }

    /* Creazione stringa risultante */

    strcpy(result, first_string);
    strcat(result, second_string);

    /* Stampa della stringa risultante */

    printf("%s", result);


    return 0;
}