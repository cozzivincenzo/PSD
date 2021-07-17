#include "functions.h"

int main(void){
    
    int key, flag=0; // Dichiarazione di variabili di controllo

    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */
    while(flag==0){

        printf("\n\n1 -Processo (creazione, inversione, merge ed estrazione di elementi);"
                "\n2 -Conversione di un numero da base decimale a base binaria;"
                "\n3 -Risoluzione di un'espressione in notazia polacca;"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);
        fflush(stdin);

        switch (key){
            case 1:
				processo(); // Chiamata alla funzione utile a lavorare su un nuovo stack
            break;
            case 2:  
                conversioneDecBin(); // Chiamata alla funzione utile a convertire un numero da decimale a binario
            break; 
            case 3:
                conversionePostIn(); // Chiamata alla funzione utile alla risoluzione dell'espressione in notazione polacca
            break;
            case 0:
                flag=1; // Flag utile all'uscita dal menu e chiusura del programma
            break;
            default:
                printf("\n\nSi prega di selezionare una delle opzioni\n\n"); // Stampa di errore in caso l'utente inserisca un numero non presente nel menu
            break;
        }


    }

    return 0;
}
