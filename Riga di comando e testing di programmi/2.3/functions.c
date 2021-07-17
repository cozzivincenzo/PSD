#include "functions.h"

/* Sottofunzione utile al confronto degli array */

int confronta_array(int first_array[], int second_array[], int n) {

    for(int i=0;i<n;i++){
        if(first_array[i]!=second_array[i]){
            return 1;
        }
    }

    return 0;

}

/* Sottofunzione utile all'inserimento dei valori nell'array alla posizione desiderata */

void inserimento(int array[], int pos, int val, int n){

    for(int i=0; i<n+1; i++){
        if(i==pos){
            for(int i=n+1; i>pos; i--){
                array[i]=array[i-1];
            }
            array[pos]=val;
        }
    }

}

/* Sottofunzione utile alla chiusura dei file */

void close_file(FILE *input_file, FILE *output_file, FILE *oracle_file){
	fclose(input_file);
    fclose(output_file);
    fclose(oracle_file);
}
