#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM NULL

/* FUNZIONE UTILE AL CONFRONTO DI DUE ELEMENTI */
int eq(item x, item y);

/* FUNZIONE UTILE ALLA LETTURA DA FILE DI UN ELEMENTO */
item input_item_file(FILE *file);

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */
void input_item(item *x);

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN ELEMENTO */
void output_item(item x);

/* FUNZIONE UTILE ALLA CONVERSIONE DI UNA STRINGA IN ELEMENTO */
item char_to_item(char str[]);
