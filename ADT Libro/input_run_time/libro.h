/********************************************************************/
/*                SPECIFICA SINTATTICA                              */ 
/*                                                                  */
/*  Tipo di riferimento: libro;                                     */
/*                                                                  */
/*  Tipi usati: stringa, numero con virgola, intero;                */
/*                                                                  */
/*                                                                  */                                                          
/*                                                                  */
/*  Operatori:                                                      */
/* -creaLibro(stringa, stringa, numero con virgola, intero)->libro  */
/* -getTitolo(libro)-> stringa                                      */
/* -setTitolo(libro)                                                */
/* -getEditore(libro)-> stringa                                     */
/* -setEditore(libro)                                               */
/* -getAnno(libro)-> intero                                         */
/* -setAnno(libro)                                                  */
/* -getPrezzo(libro)-> numero con virgola                           */
/* -setPrezzo(libro)                                                */
/* -sconto(libro, numero con virgola)                               */
/* -liberaBiblioteca(libro)                                         */
/*                                                                  */
/********************************************************************/


/********************************************************************/
/*                SPECIFICA SEMANTICA                               */ 
/*                                                                  */
/*  Tipo libro: insieme delle quadruple (titolo, editore,           */
/*              anno, prezzo) dove le preme due sono stringhe       */
/*              mentre anno è un intero e prezzo un float           */
/*  Operatori:                                                      */
/* -creaLibro(titolo, editore, prezzo, anno)->libro                 */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */
/* -getTitolo(libro)-> stringa                                      */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */                                 
/* -setTitolo(libro)                                                */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */                          
/* -getEditore(libro)-> stringa                                     */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */           
/* -setEditore(libro)                                               */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */
/* -getAnno(libro)-> intero                                         */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */                                    
/* -setAnno(libro)                                                  */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */                          
/* -getPrezzo(libro)-> numero con virgola                           */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */     
/* -setPrezzo(libro)                                                */
/*POST C. Libro=(titolo, editore, prezzo, anno)                     */
/* -sconto(libro, numero con virgola)                               */
/* -liberaBiblioteca(libro)                                         */
/*                                                                  */
/********************************************************************/
typedef struct libro *Libro;

Libro creaLibro(char *titolo, char *editore, float prezzo, int anno);
char *getTitolo(Libro libro);
void setTitolo(Libro libro, char *titolo);
char *getEditore(Libro libro);
void setEditore(Libro libro, char *editore);
int getAnno(Libro libro);
void setAnno(Libro libro, int anno);
float getPrezzo(Libro libro);
void setPrezzo(Libro libro, float nuovoPrezzo);
void sconto(Libro libro, float percentuale);
void liberaBiblioteca(Libro *biblioteca);
