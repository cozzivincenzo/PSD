#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

/* STRUTTURA CHE IDENTIFICA UNA STAMPA */  
struct stampa {
      int id;
      int num;
      int type;
};

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
item input_item(void) {
      item coda;
      int id, num, type;
      id=rand();
      printf("\nQuante copie bisogna stampare?\t");
      scanf("%d", &num);
      while(1){
            printf("\nCome si desidera stampare le copie?\n-0 In bianco e nero;\n-1 A colori;\n");
            scanf("%d", &type);
            if(type==0||type==1){
                  break;
            }
      }
      coda=creaStampa(id, num, type);
}

/* FUNZIONE UTILE ALLA CREAZIONE DI UNA STAMPA */
item creaStampa(int id, int num, int type){
      item s = malloc(sizeof(*s));
      s->id=id;
      s->num=num;
      s->type=type;
      return s;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ID DI UNA STAMPA */
int getId(item stampa){
      return stampa->id;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL NUMERO DI COPIE DI UNA STAMPA */
int getNum(item stampa){
      return stampa->num;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL TIPO DI UNA STAMPA */
int getType(item stampa){
      return stampa->type;
}

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UNA STAMPA */
void output_item (item s){
      printf("%d | Copie: %d | Tipo: %d", s->id, s->num, s->type);
}
