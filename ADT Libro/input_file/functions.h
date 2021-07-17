#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

/* FUNZIONE UTILE ALLA RIMOZIONE DEL CARATTERE \n DALLE STRINGHE */
char* dropN(char* str);

/* FUNZIONE UTILE ALLA STAMPA DEL LIBRO PIU ANTICO PRESENTE NELLA BIBLIOTECA */
void libroPiuVecchio(Libro *biblioteca, int n);

/* FUNZIONE UTILE ALLA STAMPA DEL LIBRO MENO COSTOSO PRESENTE NELLA BIBLIOTECA */
void libroMenoCostoso(Libro *biblioteca, int n);

/* FUNZIONE UTILE ALLA STAMPA DI TUTTI I LIBRI DI UN DATO EDITORE PRESENTI IN BIBLIOTECA */
void ricercaEditore(Libro *biblioteca, char *editore, int n);

/* FUNZIONE UTILE ALL'AGGIORMENTO DEL PREZZO DI TUTTI I LIBRI DI UN DETERMINATO ANNO SECONDO UN DATO SCONTO */
int scontaLibri(Libro *biblioteca, int anno, float percentuale, int n);

/* FUNZIONE UTILE ALLA STAMPA DEI DUE LIBRI CON MINOR DIFFERENZA DI PREZZO */
void trovaLibriPrezzoSimile(Libro* biblioteca, int n);

/* FUNZIONE UTILE ALLA STAMPA DEL COSTO TOTALE DI TUTTI I LIBRI DI UN DETERMINATO ANNO */
void costoTotale(Libro *biblioteca, int anno, int n);

/* FUNZIONE UTILE ALLA RIMOZIONE DI TUTTI I LIBRI DI UN DATO ANNO DALLA BIBLIOTECA */
int eliminaLibri(Libro *biblioteca, int anno, int n);