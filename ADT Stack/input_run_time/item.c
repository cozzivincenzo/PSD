#include <stdio.h>
#include <stdlib.h>
#include "item.h"

/* FUNZIONE UTILE AL CONFRONTO DI DUE ELEMENTI */
int eq(item a, item b) {
    return a==b;
}

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
void input_item(item *x) {
    scanf("%d", x);
} 

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN ELEMENTO */
void output_item(item x) {
    printf("%d", x);
} 

/* FUNZIONE UTILE ALLA CONVERSIONE DI UNA STRINGA IN ELEMENTO */
item char_to_item(char *str){
    item x=atoi(str);
    return x;
}

