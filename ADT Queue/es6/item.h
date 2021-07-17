#ifndef ITEM_H
#define ITEM_H

/* STRUTTURA CHE IDENTIFICA UNA STAMPA */  
typedef struct stampa *item;

#endif

#define NULLITEM 0

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
item input_item(void);

/* FUNZIONE UTILE ALLA CREAZIONE DI UNA STAMPA */
item creaStampa(int id, int num, int type);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ID DI UNA STAMPA */
int getId(item stampa);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL NUMERO DI COPIE DI UNA STAMPA */
int getNum(item stampa);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL TIPO DI UNA STAMPA */
int getType(item stampa);

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UNA STAMPA */
void output_item (item s);