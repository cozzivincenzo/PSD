#include "functions.h"

int run_test_case(char *tc_id, int n){
    
    char input_fname1[M], input_fname2[M], output_fname[M], oracle_fname[M]; // Dichiarazione delle stringhe atte a contenere i nomi dei file

    /* Creazione dei nomi dei file */

    strcpy(input_fname1,tc_id);
    strcat(input_fname1,"_input1.txt");

    strcpy(input_fname2,tc_id);
    strcat(input_fname2,"_input2.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");
    

    FILE *input_file1, *input_file2, *output_file; // Dichiarazione dei file di input dai quali leggere e output sul quale scrivere
    int input_array1[n], input_array2[n], output_array[n]; // Dichiarazione degli array atti a contenere i dati dei file di input

    /* Apertura dei file di input e creazione del file di output */

    input_file1 = fopen(input_fname1, "r");
    input_file2 = fopen(input_fname2, "r");
    output_file = fopen(output_fname, "w");

    if( input_file1==NULL || input_file2 == NULL || output_file==NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }

    /* Caricamento dei dati letti dal file di input sugli array */

    for(int i=0; i<n; i++){
        fscanf(input_file1, "%d", &input_array1[i]); // Caricamento dei valori dal file all'array
    }

    for(int i=0; i<n; i++){
        fscanf(input_file2, "%d", &input_array2[i]); // Caricamento dei valori dal file all'array
    }

    /*  Caricamento dei dati presenti dell'array sul file di output*/

    for(int i=0; i<n; i++){
        output_array[i]=input_array1[i]+input_array2[i]; // Ottenimento dei valori dell'array di output in base alla somma dei valori presenti negli array di input alla posizione i
        fprintf(output_file, "%d\n", output_array[i]); // Caricamento dei valori dall'array al file
    }
    
 
    FILE *oracle_file; // Dichiarazione del file oracolo
    int oracle_array[n]; // Dichiarazione dell'array atto a contenere i dati del file oracolo

    oracle_file = fopen(oracle_fname, "r"); // Apertura del file oracolo

    for(int i=0; i<n; i++){
        fscanf(oracle_file, "%d", &oracle_array[i]); // // Caricamento dei valori dal file all'array
    }
    
    int flag = confronta_array(output_array, oracle_array, n); // Confronto dell'array di output e dell'array oracolo per la verifica del corretto funzionamento del programma

    close_file(input_file1, input_file2, output_file, oracle_file); // Sottofunzione atta alla chiusura dei vai file di input, output e oracolo

    return flag; // Ritorno del risultato del confronto
}



int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result; // Dichiarazione dei file
    char tc_id[M]; // Dichiarazione di una stringa atta poi a contenere l'id dei test case
    int n, pass; // Dichiarazione di variabili utili ai controlli
    
    /* Controllo del corretto inserimento di argomenti sulla linea di comando */

    if( argc < 3 ){ 
         printf("Nomi dei file mancanti \n");
         exit(1);
    }

    test_suite = fopen(argv[1], "r"); // Apertura del file contenente test suite               
    result = fopen(argv[2], "w"); // Apertura del file contenente risultati test        
    
    /* Controllo della corretta apertura e creazione dei file */

    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
     
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */
    
    while( fscanf( test_suite, "%s%d", tc_id, &n ) == 2 ){

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