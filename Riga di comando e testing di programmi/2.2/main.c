#include "functions.h"

int run_test_case(char *tc_id, int n){
    
    char input_fname[M], output_fname[M], oracle_fname[M]; // Dichiarazione delle stringhe atte a contenere i nomi dei file

    /* Creazione dei nomi dei file */

    strcpy(input_fname,tc_id);
    strcat(input_fname,"_input.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");


    FILE *input_file, *output_file; // Dichiarazione dei file di input dai quali leggere e output sul quale scrivere
    int input_array[n]; // Dichiarazione degli array atti a contenere i dati dei file di input

    /* Apertura dei file di input e creazione del file di output */

    input_file = fopen(input_fname, "r");
    output_file = fopen(output_fname, "w");

    if( input_file==NULL || output_file == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }

    /* Caricamento dei dati letti dal file di input sull'array */

    for(int i=0; i<n; i++){
        fscanf(input_file, "%d", &input_array[i]);
    }

    ordina(input_array, n); // Chiamata alla funzione per l'ordine dei valori 

    /* Scrittura dei valori presenti nell'array sul file di output */

    for(int i=0; i<n; i++){
        fprintf(output_file, "%d\n", input_array[i]);
    }
    
 
    FILE *oracle_file; // Dichiarazione del file oracolo
    int oracle_array[n]; // Dichiarazione dell'array atto a contenere i dati del file oracolo

    oracle_file = fopen(oracle_fname, "r"); // Apertura del file oracolo

    for(int i=0; i<n; i++){
        fscanf(oracle_file, "%d", &oracle_array[i]); // Caricamento dei valori dal file all'array
    }
    
    int flag = confronta_array(input_array, oracle_array, n); // Confronto dell'array di input e dell'array oracolo per la verifica del corretto funzionamento del programma

    close_file(input_file, output_file, oracle_file); // Sottofunzione atta alla chiusura dei vai file di input, output e oracolo

    return flag; // Ritorno del risultato del confronto 
}



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
    

    while(fscanf(test_suite, "%s%d%d%d", tc_id, &n) == 2){

        pass = run_test_case(tc_id, n); // Chiamata alla funzione principale

        fprintf(result,"%s ", tc_id); // Stampa del test case id sul file result
        if(pass == 0)
            fprintf(result, "PASS \n"); // Stampa di "PASS" nel caso in cui il confronto sia avvenuto con successo
        else   
            fprintf(result, "FAIL \n");	// Stampa di "FAIL" nel caso in cui il confronto sia avvenuto con successo		 	
        }	
    
    fclose(test_suite); // Chiusura del file di input
    fclose(result); // Chiusura del file di output
}