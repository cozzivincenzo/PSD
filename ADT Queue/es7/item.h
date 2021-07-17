#ifndef ITEM_H
#define ITEM_H

/* STRUTTURA CHE IDENTIFICA UNA CLOCK */  
typedef struct clock *item;

#endif

#define NULLITEM 0

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
item input_item(void);

/* FUNZIONE UTILE ALLA CREAZIONE DI UNA STAMPA */
item creaProcesso(int id, int burst);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ID DI UN CLOCK */
int getId(item processo);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL BURST DI UN CLOCK */
int getBurst(item processo);

/* FUNZIONE UTILE ALL'AGGIORNAMENTO DEL BURST DI UN CLOCK */
void setBurst(item processo, int burst);

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN CLOCK */
void output_item (item p);