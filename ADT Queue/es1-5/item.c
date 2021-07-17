#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

/* STRUTTURA CHE IDENTIFICA UN PUNTO */  
struct punto {
      float x;
      float y;
};

/* FUNZIONE UTILE ALLA LETTURA IN INPUT DI UN ELEMENTO */ 
item input_item(void) {
      printf("\n\nInserire il valore 163 per stoppare l'inserimento di punti");
      item punto;
      float x, y;
      printf("\nInserire la x:\t");
      scanf("%f", &x);
      if(x==163){
            punto=NULLITEM;
            return punto;
      }
      printf("Inserire la y:\t");
      scanf("%f", &y);
      punto=creapunto(x,y);
      return punto;
}

/* FUNZIONE UTILE ALLA CREAZIONE DI UN PUNTO */
item creapunto(float x, float y){
      item p = malloc(sizeof(*p));
      p->x=x;
      p->y=y;
      return p;
}

/* FUNZIONE UTILE AL CONFRONTO DI DUE ELEMENTI */
int eq(item p1, item p2) {
      return ascissa(p1)==ascissa(p2) && ordinata(p1)==ordinata(p2);
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ASCISSA DI UN PUNTO */
float ascissa(item p){
     return p->x;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELL'ORDINATA DI UN PUNTO */
float ordinata(item p){
      return p->y;
}

/* FUNZIONE UTILE AL CALCOLO DELLA DISTANZA TRA DUE PUNTI */
float distanza(item p1, item p2){
      float distanza = sqrt(pow((p1->x-p2->x), 2) + pow((p1->y-p2->y), 2));
      return distanza;
}

/* FUNZIONE UTILE ALLA STAMPA IN OUTPUT DI UN ELEMENTO */
void output_item (item p){
      printf("(%f;%f)", p->x, p->y );
}
