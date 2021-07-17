#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct punto {
      float x;
      float y;
};
      
Punto creapunto(float x, float y){

      Punto p = malloc(sizeof(*p));

      p->x=x;
      p->y=y;

      return p;

}

float ascissa(Punto p){
     return p->x;
}
 
float ordinata(Punto p){
      return p->y;
}

float distanza(Punto p1, Punto p2){
      float distanza = sqrt(pow((p1->x-p2->x), 2) + pow((p1->y-p2->y), 2));
      return distanza;
}

void  stampa (Punto p){
      printf("(%f;%f)", p->x, p->y );
}


