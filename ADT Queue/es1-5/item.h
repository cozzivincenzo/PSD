#ifndef ITEM_H
#define ITEM_H

/* STRUTTURA CHE IDENTIFICA UN PUNTO */  
typedef struct punto *item;

#endif

#define NULLITEM 0

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */
item input_item(void);

/* FUNZIONE UTILE ALLA CREAZIONE DI UN PUNTO */
item creapunto(float x, float y);

/* FUNZIONE UTILE AL CONFRONTO DI DUE ELEMENTI */
int eq(item p1, item p2);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ASCISSA DI UN PUNTO */
float ascissa(item p);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ORDINATA DI UN PUNTO */
float ordinata(item p);

/* FUNZIONE UTILE AL CALCOLO DELLA DISTANZA TRA DUE PUNTI */
float distanza(item p1, item p2);

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN ELEMENTO */
void output_item (item p);
