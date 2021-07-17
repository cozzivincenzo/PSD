#include "functions.h"

int main(void){
    
    int key, flag=0, input; // Dichiarazione e inizializzazione di variabili utili al controllo;

    while(flag==0){

        printf("\n\n1 -Controllo in maniera iterativa"
                "\n2 -Controllo in maniera ricorsiva"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);
        fflush(stdin);

        switch (key){
            case 1:
                /* Lettura in input del numero da controllare */
                printf("\n\nQuale numero si desidera controllare?\t");
                scanf("%d", &input);
                if(input==1){
                    printf("Inserire un numero che non sia 1!");
                    break;
                }
                
				controlloIterativo(input); // Chiamata alla funzione utile a controllare se il numero è primo iterativamente
            break;
            case 2: 
                /* Lettura in input del numero da controllare */ 
                printf("\n\nQuale numero si desidera controllare?\t");
                scanf("%d", &input);
                if(input==1){
                    printf("Inserire un numero che non sia 1!");
                    break;
                }
                
                /* Chiamata alla funzione utile a controllare se il numero è primo ricorsivamente */
				if(controlloRicorsivo(input, input-1)==1){
                    printf("\n\nIl numero è primo\n\n");
                } else {
                    printf("\n\nIl numero non è primo\n\n");
                }
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
