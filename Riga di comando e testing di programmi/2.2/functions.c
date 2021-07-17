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

/* Sottofunzione utile all'ordinamento dell'array tramite il BubbleSort */

void ordina(int array[], int n)
{
    int tmp; 

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        
        }
        
    }
}

/* Sottofunzione utile alla chiusura dei file */

void close_file(FILE *input_file, FILE *output_file, FILE *oracle_file){
	fclose(input_file);
    fclose(output_file);
    fclose(oracle_file);
}
