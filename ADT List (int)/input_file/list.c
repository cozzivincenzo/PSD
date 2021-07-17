#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* STRUTTURA CHE IDENTIFICA IL NODO DELLA LISTA CONCATENATA */   
struct node {
     item value;
     struct node *next;
};

/* FUNZIONE UTILE A CREARE UNA NUOVA LISTA VUOTA */
list newList(void) {
     return NULL;
}

/* FUNZIONE CHE CONTROLLA SE LA LISTA È VUOTA */
int emptyList(list l) {
     return l==NULL;
}

/* FUNZIONE UTILE ALL'INSERIMENTO DI NUOVI ELEMENTI NELLA LISTA */
list consList(item val, list l) {
     
     struct node *newNode; // Dichiarazione di un nuovo nodo
     newNode = malloc(sizeof(struct node)); // Allocazione dinamica della memoria per il nuovo nodo

     if(newNode!=NULL){ // Nel caso in cui l'allocazione dovesse essere riuscita 
          newNode->value=val; // Il valore passato dalla funzione chiamante verrebbe assegnato al campo value del nuovo nodo
          newNode->next=l; // Il campo next del nuovo nodo verrebbe fatto puntare al nodo precedentemente inserito 
          l=newNode; // newNode diventa il primo elemento della lista puntato da l
     }
     return l;

}

/* FUNZIONE UTILE ALLO SCORRIMENTO DELLA LISTA */
list tailList(list l) {

     list temp; // Dichiarazione di una nuova lista

     if(l!=NULL) { 
          temp=l->next; // Se la lista passata dalla funzione chiamante non risulta essere vuota, temp assume l'indirizzo del nodo successivo
     } else {
          temp=NULL; // Se la lista passata dalla funzione chiamante risulta essere vuota, temp assume il valore nullo
     } 
     
     return temp;

}

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL PRIMO ELEMENTO DELLA LISTA */
item getFirst (list l) {

     item val; // Dichiarazione di un nuovo elemento
     if(l!=NULL){
          val=l->value; // Se la lista passata dalla funzione chiamante non risulta essere vuota, val assume il valore del primo elemento della lista
     } else {
          val=NULLITEM; // Se la lista passata dalla funzione chiamante non risulta essere vuota, val assume il valore nullo
     }

     return val;
     
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA GRANDEZZA DELLA LISTA */
int sizeList (list l) {

     int size=0; // Dichiarazione e inizializzazione di un contatore

     while(!emptyList(l)) { // Ripetizione del ciclo fino a quando ci sono elementi nella lista
          size++; // Incremento del contatore
          l=tailList(l); // Scorrimento della lista tramite la funzione tailList
     }

     return size;
}

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA POSIZIONE DI UN ELEMENTO CERCATO NELLA LISTA */
int posItem (list l, item val) {
    
     int pos=0, i=0; // Dichiarazione e inizializzazione di una variabile contatore e di una variabile utile al controllo

     while(!emptyList(l)&&!i){ // Ripetizione del ciclo fino a quando ci sono elementi nella lista e i risulta essere 0
          if(eq(getFirst(l), val)){ // Confronto dell'elemento da ricercare con il contenuto della lista
               i=1; // Se l'elemento viene trovato, i viene posto a 1 in modo tale da fermare il ciclo
          } else { // Se l'elemento non  viene trovato:
               pos++; // il contatore viene incrementato;
               l=tailList(l); // avviene lo scorrimento della lista tramite la funzione tailList;
          }
     }

     if(!i){ // Controllo del valore di i una volta finito il ciclo
          pos=-1; // Se, una volta scorsa tutta la lista, non è stato trovato alcun elemento, pos viene impostato a -1 per indicare che l'elemento non è presente
     }

     return pos;

}


/* FUNZIONE UTILE ALL'OTTENIMENTO DI UN ELEMENTO CORRISPONDENTE AD UNA POSIZIONE CERCATA NELLA LISTA */
item getItem (list l, int pos) {

     item val; // Dichicarazione di un nuovo elemento
     int i=0; // Dichiarazione di una variabile contatore

     while(i<pos && !emptyList(l)){ // Ripetizione del ciclo fino a quando ci sono elementi nella lista
          i++; // Incremento del contatore fino al raggiungimento di pos
          l=tailList(l); // Scorrimento della lista tramite la funzine taiList
     }

     if(!emptyList(l)){ // Controllo sulla lista
          val=getFirst(l); // Se la lista non risulta essere vuota, il nuovo elemento acquisisce il valore dell'elemento della lista a cui stiamo puntando
     } else {
          val=NULLITEM; // Se la lista risulta essere vuota, il nuovo elemento acquisisce il valore nullo
     }

     return val;

}

/* FUNZIONE UTILE A INVERTIRE LA LISTA */
list reverseList (list l) {
      
     list lista; // Dichiarazione di una nuova lista
     item val; // Dichiarazione di un nuovo elemento

     lista = newList(); // 

     while(!emptyList(l)){ // Ripetizione del ciclo fino a quando ci sono elementi nella lista passata dalla funzione chiamante
          val=getFirst(l); // Assegnamento dell'elemento della lista al nuovo elemento
          lista=consList(val, lista); // Inserimento del nuovo elemento nella nuova lista
          l=tailList(l); // Scorrimento della lista passata dalla funzione chiamante tramite la funzione tailList
     }

     return lista;

}

/* FUNZIONE UTILE ALLA STAMPA DEGLI ELEMENTI DELLA LISTA */
void outputList (list l) {

     int i=0; // Dichiarazione e inizializzazione di una variabile contatore 
     item val; // Dichiarazione di un nuovo elemento

     while(!emptyList(l)){ // Ripetizione del ciclo fino a quando ci sono elementi nella lista
          val=getFirst(l); // Assegnamento dell'elemento della lista al nuovo elemento 

          /* Stampa di posizione ed elemento */
          printf("\nElemento di posizione %d:\t", i); 
          output_item(val);
          printf("\n");

          l=tailList(l); // Scorrimento della lista tramite la funzione tailList
          i++; // Incremento del contatore
     }
      
}
