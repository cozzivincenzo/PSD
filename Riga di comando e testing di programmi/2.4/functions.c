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

/* Sottofunzione utile alla chiusura dei file */

void close_file(FILE *input_file1, FILE *input_file2, FILE *output_file, FILE *oracle_file){
	fclose(input_file1);
    fclose(input_file2);
    fclose(output_file);
    fclose(oracle_file);
}

