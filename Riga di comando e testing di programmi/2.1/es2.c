#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void ordina(int array[], int cont); // Prototipo della sottofunzione

int main(int argc, char *argv[])
{
    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if(argc < 2){
        printf("Argomenti insufficienti");
        exit(1);
    }

    int cont = 0, j=1; // Dichiarazione e inizializzazione di variabili utili al controllo

    /* Conto del numero argomenti inseriti a riga di comando */

    while(argv[j]!='\0'){
        cont++;
        j++;
    }

    int array[cont]; // Dichiarazione di un array di dimensione pari al numero di argomenti inseriti a riga di comando */

    /* Conversione degli argomenti da stringa a intero con annesso controllo sulla presenza di caratteri non numerici */

    for(int i = 0; i<cont;i++){
        array[i]=atoi(argv[i+1]);
        if(isdigit(array[i])==0){
            printf("Errore, rilevato NaN");
            exit(1);
        }
    }

    ordina(array, cont); // Chiamata alla funzione atta all'ordinamento dell'array

    return 0;

}

/* Sottofunzione utile all'ordinamento dell'array tramite il BubbleSort */

void ordina(int array[], int cont)
{
    int tmp;

    for(int i=0; i<cont; i++)
    {
        for(int j=i+1; j<cont; j++)
        {
            if(array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        
        }
        
    }

    
    /* Stampa dell'array ordinato */

    for(int i=0; i<cont; i++){
        printf("%d\n", array[i]);
        
    }

}
