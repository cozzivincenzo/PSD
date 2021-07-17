
#include <stdio.h>
#include <stdlib.h>
#include "libro.h"


/* CREAZIONE DELL'ADT LIBRO */

struct libro{
     char *titolo;
     char *editore;
     float prezzo;
     int anno;    
};


/* FUNZIONE UTILE ALLA CREAZIONE DEL TIPO */

Libro creaLibro(char *titolo, char *editore, float prezzo, int anno){
      
	Libro libro=(Libro)malloc(sizeof(libro)); // Dichiarazione e allocazione dinamica della variabile di tipo Libro

      /* Controllo della corretta allocazione di memoria */
      if (libro == NULL) {
            printf("\nError: Out Of Memory\n\n");
            exit(EXIT_FAILURE);
      }


      /* Assegnamento dei valori per i campi della struttura */
      libro->titolo=titolo;
      libro->editore=editore;
      libro->prezzo=prezzo;
      libro->anno=anno;

      return libro; // Ritorno del nuovo libro
}


/* FUNZIONE UTILE AL RITORNO DEL TITOLO DI UN DATO LIBRO */

char *getTitolo(Libro libro)
{
     return libro->titolo;
}


/* FUNZIONE UTILE AD ASSEGNARE UN NUOVO TITOLO AD UN DATO LIBRO */

void setTitolo(Libro libro, char *titolo)
{
     libro->titolo=titolo;
}


/* FUNZIONE UTILE AL RITORNO DELL'AUTORE DI UN DATO LIBRO */

char *getEditore(Libro libro)
{
      return libro->editore;	  
}


/* FUNZIONE UTILE AD ASSEGNARE UN NUOVO EDITORE AD UN DATO LIBRO */

void setEditore(Libro libro, char *editore)
{
     libro->editore=editore;
}


/* FUNZIONE UTILE AL RITORNO DELL'ANNO DI UN DATO LIBRO */

int getAnno(Libro libro)
{
      return libro->anno;
}


/* FUNZIONE UTILE AD ASSEGNARE UN NUOVO ANNO AD UN DATO LIBRO */

void setAnno(Libro libro, int anno)
{
     libro->anno=anno;
}


/* FUNZIONE UTILE AL RITORNO DEL PREZZO DI UN DATO LIBRO */

float getPrezzo(Libro libro)
{     
      return libro->prezzo; 
}


/* FUNZIONE UTILE AD ASSEGNARE UN NUOVO PREZZO AD UN DATO LIBRO */

void setPrezzo(Libro libro, float prezzo)
{     
      libro->prezzo=prezzo;
}


/* FUNZIONE UTILE AL CALCOLO DELLO SCONTO DI UN DATO LIBRO, CON ANNESSO AGGIORNAMENTO DI QUEST'ULTIMO */

void sconto(Libro libro, float percentuale)
{
      float prezzo=getPrezzo(libro);
      prezzo*=percentuale;
      prezzo/=100;
      prezzo=getPrezzo(libro)-prezzo;
      setPrezzo(libro, prezzo);
}


/* FUNZIONE UTILE A LIBERARE LA MEMORIA ASSEGNATA DINAMICAMENTE */

void liberaBiblioteca(Libro *biblioteca){
      free(biblioteca);
}