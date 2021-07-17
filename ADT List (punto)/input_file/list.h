/********************************************************/
/*              SPECIFICA SINTATTICA                    */
/*                                                      */
/*  Tipo di riferimento: list                           */
/*  Tipi usati: item, boolean , int;                    */
/*                                                      */
/*  Operatori :                                         */
/*  -newList() → list                                   */
/*  -emptyList(list) → boolean                          */
/*  -consList(item, list) → list                        */
/*  -posItem(list, item) → int                          */
/*  -getItem(list, int)→ list                           */
/*  -sizeList(list)→ int                                */
/*  -reverseList(list)→ list                            */
/*  -outputList(list) → void                            */
/*  -tailList(list) → list                              */
/*  -getFirst(list) → item                              */
/*                                                      */
/********************************************************/

/********************************************************/
/*                 SPECIFICA SEMANTICA                  */
/*                                                      */
/*  Tipo di riferimento list :                          */
/*  -list è l’insieme delle sequenze L=a1,a2,…,an       */
/*   di tipo item .L’insieme list contiene inoltre      */
/*   un elemento nil che rappresenta                    */
/*   la lista vuota (priva di elementi)                 */
/*                                                      */
/*  Operatori                                           */
/*  -newList() → l                                      */
/*    Post: l = nil                                     */
/*                                                      */
/*  -emptyList(l) → b                                   */
/*    Post: se l=nil allora b = true                    */
/*          altrimenti b = false                        */
/*                                                      */
/*  -consList(e, l) → l’                                */
/*    Post: l = <a1, a2, … an> AND                      */
/*                l’ = <e, a1, a2, …, an>               */  
/*                                                      */
/*  -tailList(l) → l’                                   */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*    Post: l’ = <a2, …, an>                            */
/*                                                      */
/*  -getFirst(l) → e                                    */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*    Post: e = a1                                      */
/*                                                      */
/*  -posItem(l, val) → pos                              */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*    Post: pos = posizione                             */
/*                                                      */
/*  -getItem(l, pos)→ e                                 */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*    Post: e = apos                                    */
/*                                                      */
/*  - sizeList(l)→ n                                    */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*                                                      */
/*  -reverseList(l)→ l'                                 */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*    Post: l = <an, a(n-1), …, a1>   n>0               */  
/*                                                      */
/*  -outputList(l) → void                               */
/*    Pre: l = <a1, a2, …, an>   n>0                    */
/*                                                      */
/********************************************************/


#include "item.h"

typedef struct node *list;

/* FUNZIONE UTILE A CREARE UNA NUOVA LISTA VUOTA */
list newList(void);

/* FUNZIONE CHE CONTROLLA SE LA LISTA È VUOTA */
int emptyList(list l);

/* FUNZIONE UTILE ALL'INSERIMENTO DI NUOVI ELEMENTI NELLA LISTA */
list consList(item val, list l);

/* FUNZIONE UTILE ALLO SCORRIMENTO DELLA LISTA */
list tailList(list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DEL PRIMO ELEMENTO DELLA LISTA */
item getFirst (list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA GRANDEZZA DELLA LISTA */
int sizeList (list l);

/* FUNZIONE UTILE ALL'OTTENIMENTO DELLA POSIZIONE DI UN ELEMENTO CERCATO NELLA LISTA */
int posItem (list l, item val);

/* FUNZIONE UTILE ALL'OTTENIMENTO DI UN ELEMENTO CORRISPONDENTE AD UNA POSIZIONE CERCATA NELLA LISTA */
item getItem (list l, int pos);

/* FUNZIONE UTILE A INVERTIRE LA LISTA */
list reverseList (list l);

/* FUNZIONE UTILE ALLA STAMPA DEGLI ELEMENTI DELLA LISTA */
void outputList (list l);
