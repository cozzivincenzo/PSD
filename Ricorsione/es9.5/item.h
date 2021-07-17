#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM NULL

/* FUNZIONE UTILE AL CONFRONTO DI DUE VALORI */
int eq(item x, item y);

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN VALORE */
void input_item(item *x); 

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN VALORE */
void output_item(item x);
