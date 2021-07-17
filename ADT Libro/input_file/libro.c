#include <stdio.h>
#include <stdlib.h>
#include "libro.h"

struct libro{
     char *titolo;
     char *editore;
     float prezzo;
     int anno;    
};

Libro creaLibro(char *titolo, char *editore, float prezzo, int anno){
      
	Libro libro=(Libro)malloc(sizeof(libro));
      if (libro == NULL) {
            printf("\nError: Out Of Memory\n\n");
            exit(EXIT_FAILURE);
      }

      libro->titolo=titolo;
      libro->editore=editore;
      libro->prezzo=prezzo;
      libro->anno=anno;

      return libro;
}

char *getTitolo(Libro libro)
{
     return libro->titolo;
}

void setTitolo(Libro libro, char *titolo)
{
     libro->titolo=titolo;
}

char *getEditore(Libro libro)
{
      return libro->editore;	  
}

void setEditore(Libro libro, char *editore)
{
     libro->editore=editore;
}

int getAnno(Libro libro)
{
      return libro->anno;
}

void setAnno(Libro libro, int anno)
{
     libro->anno=anno;
}

float getPrezzo(Libro libro)
{     
      return libro->prezzo; 
}

void setPrezzo(Libro libro, float prezzo)
{     
      libro->prezzo=prezzo;
}

void sconto(Libro libro, float percentuale)
{
      float prezzo=getPrezzo(libro);
      prezzo*=percentuale;
      prezzo/=100;
      prezzo=getPrezzo(libro)-prezzo;
      setPrezzo(libro, prezzo);
}

void liberaBiblioteca(Libro *biblioteca){
      free(biblioteca);
}
