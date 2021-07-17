#include <stdio.h>
#include "item.h"

/* FUNZIONE UTILE AL CONFRONTO DI DUE VALORI */
int eq(item a, item b) {
    return a==b;
}

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN VALORE */
void input_item(item *x) {
    scanf("%d", x);
} 

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN VALORE */
void output_item(item x) {
    printf("%d", x);
} 

