#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "item.h"

#define MAX 50 // Definizione della grandezza di alcune stringhe

/* FUNZIONE UTILE A RIMUOVERE LO \n DA UNA STRINGA */
char *dropN(char *str);

/* FUNZIONE UTILE A LAVORARE SU UN NUOVO STACK, INVERTENDOLO, UNENDOLO ALLA SUA REVERSE ED ELIMINANDONE ELEMENTI */
void processo(void);

/* FUNZIONE UTILE ALLA CONVERSIONE DI UN NUMERO DA BASE BINARIA A BASE DECIMALE */
void conversioneDecBin(void);

/* FUNZIONE UTILE ALLA RISOLUZIONE DI UN'ESPRESSIONE IN NOTAZIONE POLACCA */
void conversionePostIn(void);