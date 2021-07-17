/* Modulo contente tutti i moduli e prototipi necessari al funzionamento del programma */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
# define M 50 

void distanza_minore(list lista, float distance);
void distanza_massima(list lista);
list riordina(list lista, char coordinata, char criterio);
list a_crescente(list lista);
list a_decrescente(list lista);
list o_crescente(list lista);
list o_decrescente(list lista);
list sottolista(list lista, list sublist, int sinistro, int destro);
list inserisci_lista(list lista, list sublist, int pos);
list zigzag(list lista);