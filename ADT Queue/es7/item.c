#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

/* STRUTTURA CHE IDENTIFICA UNA CLOCK */  
struct clock {
      int id;
      int burst;
};
 
/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
item input_item(void) {
      item processo;
      int id, burst=0;
      id=rand();
      while(burst==0){
            burst=rand() % (20 + 1 - 0) + 0;
      }
      processo=creaProcesso(id, burst);
      return processo;
}

/* FUNZIONE UTILE ALLA CREAZIONE DI UNA STAMPA */
item creaProcesso(int id, int burst){
      item p = malloc(sizeof(*p));
      p->id=id;
      p->burst=burst;
      return p;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ID DI UN CLOCK */
int getId(item processo){
      return processo->id;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL BURST DI UN CLOCK */
int getBurst(item processo){
      return processo->burst;
}

/* FUNZIONE UTILE ALL'AGGIORNAMENTO DEL BURST DI UN CLOCK */
void setBurst(item processo, int burst){
      processo->burst=burst;
}

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN CLOCK */
void output_item (item p){
      printf("ID: %d | Clock: %d", p->id, p->burst);
}
