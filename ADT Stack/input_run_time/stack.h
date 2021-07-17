#include "item.h"

typedef struct Stack *stack;

/* FUNZIONE UTILE A CREARE UN NUOVO STACK */
stack newStack(void);

/* FUNZIONE UTILE A CONTROLLARE CHE LO STACK SIA VUOTO */
int emptyStack(stack s);

/* FUNZIONE UTILE ALL'INSERIMENTO DI NUOVI ELEMENTI NELLO STACK */
int push(item val, stack s);

/* FUNZIONE UTILE ALLO SCORRIMENTO DELLO STACK */
void pop(stack s);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL PRIMO ELEMENTO DELLO STACK */
item top(stack s);

/* FUNZIONE UTILE A INVERTIRE LO STACK */
stack reverseStack(stack s);

/* FUNZIONE UTILE ALL'UNIONE DI DUE STACK */
stack merge(stack s, stack reverseS);

/* FUNZIONE UTILE ALL'ELIMINAZIONE DI ELEMENTI DALLO STACK */
stack estrazione(stack s, item n);

/* FUNZIONE UTILE ALLA STAMPA DELLO STACK */
void output_stack(stack s);

/* FUNZIONE UTILE AL RIPRISTINO DI LETTURA DELLO STACK */
void rewindStack(stack s);
