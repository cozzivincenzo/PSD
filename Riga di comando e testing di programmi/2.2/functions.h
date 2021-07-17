/* FILE DI INTESTAZIONE UTILE A CONTENERE TUTTI I PROTOTIPI, TUTTE LE MACRO E TUTTE LE LIBRERIE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define M 20

int confronta_array(int first_array[], int second_array[], int n) ;
void ordina(int array[], int n);
void close_file(FILE *input_file, FILE *output_file, FILE *oracle_file);
