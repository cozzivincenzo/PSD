#include "functions.h"

char *dropN(char *str){
    if(str[strlen(str)-1] == '\n') 
        str[strlen(str)-1] = '\0'; // Sostituzione dell'ultimo carattere, solo se risulta essere \n, con il carattere tappo
    return str;
}

void libroPiuVecchio(Libro *biblioteca, int n){

    Libro libro=biblioteca[0]; // Dichiarazione di una nuova variabile temporanea, di tipo Libro, atta a contenere il libro più antico, inizializzandola assegnadole il primo libro presente in biblioteca 


    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di quello con l'anno minore */

    for(int i=0; i<n; i++){
        if(getAnno(libro)>getAnno(biblioteca[i])){ // Confronto degli anni dei libri 
            libro=biblioteca[i]; // Sostituzione della variabile temporanea
        }
    }

    /* Stampa del libro più antico */
    printf("Il libro piu' antico risulta essere '%s', edito da '%s', pubblicato nel %d, al costo di %0.2f euro", getTitolo(libro), getEditore(libro), getAnno(libro), getPrezzo(libro));

}

void libroMenoCostoso(Libro *biblioteca, int n){

    Libro libro=biblioteca[0]; // Dichiarazione di una nuova variabile temporanea, di tipo Libro, atta a contenere il libro meno costoso, inizializzandola assegnadole il primo libro presente in biblioteca 


    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di quello con l'anno minore */

    for(int i=0; i<n; i++){
        if(getPrezzo(libro)>getPrezzo(biblioteca[i])){ // Confronto degli anni dei libri 
            libro=biblioteca[i]; // Sostituzione della variabile temporanea
        }
    }

    /* Stampa del libro meno costoso */
    printf("Il libro meno costoso risulta essere '%s', edito da '%s', pubblicato nel %d, al costo di %0.2f euro", getTitolo(libro), getEditore(libro), getAnno(libro), getPrezzo(libro));

}

void ricercaEditore(Libro *biblioteca, char *editore, int n){

    int j=0; // Dichiarazione e inizializzazione di una variabile utile al controllo


    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di tutti quelli di un dato editore */

    for(int i=0; i<n; i++){ 
        if(strcmp(editore, getEditore(biblioteca[i]))==0){ // Confronto tra il dato editore e gli editori dei vari libri
            j++;
            /* Stampa dei libri man mano che vengono trovati */
            printf("\n\nIl %d' libro trovato risulta essere: '%s', del %d, al prezzo di %0.2f euro\n\n", j, getTitolo(biblioteca[i]), getAnno(biblioteca[i]), getPrezzo(biblioteca[i]));
        }
    }


    /* Stampa di un messaggio di errore in caso in cui non vengano trovati libri del dato editore */

    if(j==0){
        printf("\n\nNon ci sono libri di questo editore in biblioteca\n\n");
    } 

}

int scontaLibri(Libro *biblioteca, int anno, float percentuale, int n){

    int flag=1; // Dichiarazione e inizializzazione di una variabile utile al controllo

    
    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di tutti quelli di un dato anno */

    for(int i=0; i<n; i++){
        if(getAnno(biblioteca[i])==anno){ // Confronto tra il dato anno e gli anni dei vari libri
            sconto(biblioteca[i], percentuale); // Chiamata alla funzione sconto in caso l'anno del libro corrisponda al dato anno */
            flag=0;
        }
    }

    return flag;

}

void costoTotale(Libro *biblioteca, int anno, int n){

    float costo=0; // Dichiarazione e inizializzazione di una variabile atta a contenere il costo totale


    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di tutti quelli di un dato anno */

    for(int i=0; i<n; i++){
        if(getAnno(biblioteca[i])==anno){ // Confronto tra il dato anno e gli anni dei vari libri
            costo+=getPrezzo(biblioteca[i]); // Incremento della variabile 
        }
    }

    /* Stampa del costo totale calcolato */
    printf("Il costo totale dei libri del %d risulta essere di %0.2f euro", anno, costo);

}

int eliminaLibri(Libro *biblioteca, int anno, int n){

    Libro *tmp=malloc(sizeof(Libro)*n); // Dichiarazione e allocazione dinamica di un puntatore temporaneo alla struct Libro

    /* Controllo della corretta allocazione dinamica */
    if(tmp == NULL) {
        printf("\nError: Out Of Memory\n\n");
        exit(EXIT_FAILURE);
    }

    int cont = 0; // Dichiarazione e inizializzazione di una variabile utile al controllo

    /* Scorrimento di tutti i libri presenti in biblioteca, alla ricerca di tutti quelli con anno differente a quello dato */

    for(int i=0; i<n; i++){
        if(getAnno(biblioteca[i])!=anno){
            cont++;
            tmp[cont-1]=biblioteca[i]; // Nel caso in cui l'anno dovesse risultare differente, il libro verrebbe salvato nella nuova biblioteca temporanea
            
        }
    }


    /* Ciclo utile alla riscrittura della vecchia biblioteca sulla base della nuova */

    for(int i=0; i<cont; i++){
        biblioteca[i]=tmp[i];
    }

    biblioteca = realloc(biblioteca, cont*sizeof(Libro)); // Riallocazione dinamica della memoria destinata alla vecchia biblioteca, sulla base del numero di libri ancora presenti
    

    return cont; // Ritorno della variabile utile poi a reimpostare il numero di libri ora presenti in biblioteca

}

void trovaLibriPrezzoSimile(Libro* biblioteca, int n){

    float min=9999, scarto; // Dichiarazione e inizializzazione di variabili utili al controllo
    Libro output1, output2; // Dichiarazione di due variabili temporanea, di tipo Libro, utili alla stampa


    /* Scorrimento della biblioteca utile a confrontare i prezzi di ogni libro, alla ricerca dei due con scarto di prezzo minore */

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            scarto = getPrezzo(biblioteca[i])-getPrezzo(biblioteca[j]); // Calcolo dello scarto di prezzo
            
            /* Controllo di un eventuale scarto di prezzo negativo */
            if(scarto<0){
                scarto*=-1; // Nel caso in cui lo scarto dovesse essere negativo, verrebbe moltiplicato per -1 in modo tale da renderlo positivo e poterlo confrontare con lo scarto minore trovato in precedenza, senza compromettere la ricerca
            }
            if( scarto<min){ // Confronto tra il nuovo scarto di prezzo e lo scarto minore
                min=scarto; // Assegnamento del nuovo scarto di prezzo allo scarto minore
                output1=biblioteca[i]; // Assegnamento della prima variabile di stampa come uno dei due libri
                output2=biblioteca[j]; // Assegnamento della seconda variabile di stampa come uno dei due libri
            }
        }
    }


    /* Stampa dei libri con minor scarto di prezzo, e dello scarto stesso */
    printf("I libri con scarto di prezzo minore sono '%s' e '%s', con uno scarto di %0.2f", getTitolo(output1), getTitolo(output2), min);

}