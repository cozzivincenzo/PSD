#include "functions.h"

int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;  // Dichiarazione dei file
    char tc_id[M];  // Dichiarazione di una stringa atta poi a contenere l'id dei test case
    int n, pass; // Dichiarazione di variabili utili ai controlli

    /* Controllo del corretto inserimento di argomenti sulla linea di comando */
    
    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    
    test_suite = fopen(argv[1], "r");  // Apertura del file contenente test suite                 
    result = fopen(argv[2], "w");   // Apertura del file contenente risultati test       
    
    /* Controllo della corretta apertura e creazione dei file */

    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
     
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */
    

    while(fscanf(test_suite, "%s", tc_id) == 1){

        pass = run_test_case(tc_id); // Chiamata alla funzione principale

        fprintf(result,"%s ", tc_id); // Stampa del test case id sul file result
        if(pass == 0)
            fprintf(result, "PASS \n"); // Stampa di "PASS" nel caso in cui il confronto sia avvenuto con successo
        else   
            fprintf(result, "FAIL \n");	// Stampa di "FAIL" nel caso in cui il confronto sia avvenuto con successo		 	
        }	
    
    fclose(test_suite); // Chiusura del file di input
    fclose(result); // Chiusura del file di output
}