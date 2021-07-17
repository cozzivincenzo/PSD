#include <stdio.h>
#include "item.h"
#include "stack.h"

int main(void){
    
    int key, flag=0; // Dichiarazione di variabili di controllo
    item input; // Dichiarazione di un elemento
    stack s=newStack(); // Dichiarazione e inizializzazione di uno stack

    while(flag==0){

        printf("\n\n1 -Conversione in maniera iterativa"
                "\n2 -Conversione in maniera ricorsiva"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);
        fflush(stdin);

        switch (key){
            case 1:
                /* Lettura in input del numero da convertire in binario tramite lo stack */
                printf("\n\nQuale numero si desidera convertire da decimale in binario?\t");
                input_item(&input);
                
				conversioneDecBin(input); // Chiamata alla funzione utile alla conversione iterativamente
            break;
            case 2:
                /* Lettura in input del numero da convertire in binario tramite lo stack */  
                printf("\n\nQuale numero si desidera convertire da decimale in binario?\t");
                input_item(&input);

                conversioneRicorsiva(input, s); // Chiamata alla funzione utile alla conversione ricorsivamente

                /* Stampa dello stack */
                printf("\n");
                output_stack(s);
                s=newStack();
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
