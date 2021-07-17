#include "functions.h"

int main(void)
{
    int n, anno, flag=0, key, flag_sconto; // Dichiarazione di variabili utili ai controlli
    Libro *biblioteca; // Dichiarazione di un puntatore all'ADT Libro
    char *titolo, *editore, buffer[100]=""; // Dichiarazione delle variabili utili a contenere le stringhe
    float prezzo, percentuale; // Dichiarazione delle variabili utili a impostare il prezzo dei libri


    /* Presa in input del numero di libri da voler inserire */

    printf("Inserire il numero di libri da aggiungere alla biblioteca:\t");
    scanf("%d", &n);

    biblioteca = (Libro*)malloc(sizeof(Libro*)*n); // Allocazione dinamica di un numero di libri pari a n

    /* Controllo della corretta allocazione di memoria */
    if (biblioteca == NULL) {
        printf("\nError: Out Of Memory\n\n");
        exit(EXIT_FAILURE);
    }


    /* Creazione dei vari libri prendendo in input titolo, editore, anno e prezzo, per poi passarli alla funzione creaLibro.
       Per quanto riguarda le stringhe, è stato necessario salvare l'input in un buffer di massimo 100 caratteri tramite la fgets (passando come file lo standard input),
       per poi allocare dinamicamente, alle variabili titolo ed editore, un numero di caratteri pari alla strlen del buffer.
       Alla funzione strcpy, invece, è stato passato il buffer privato del newline. */

    for(int i=0;i<n;i++){

        getchar();
        printf("\nInserire il titolo: \t");
        fgets(buffer, 100, stdin);
        titolo=malloc(strlen(buffer));
        strcpy(titolo, dropN(buffer));
        fflush(stdin);

        printf("\nInserire l'editore: \t");
        fgets(buffer, 100, stdin);
        editore=malloc(strlen(buffer));
        strcpy(editore, dropN(buffer));

        fflush(stdin);
        printf("\nInserire l'anno di pubblicazione: \t");
        scanf("%d", &anno);

        fflush(stdin);
        printf("\nInserire il prezzo: \t");
        scanf("%f", &prezzo);

        biblioteca[i]=creaLibro(titolo, editore, prezzo, anno);

    }


    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */

    while(flag==0){

        printf("\n\n1 -Ricerca del libro piu' antico;"
        "\n2 -Ricerca del libro meno costoso;"
        "\n3 -Stampare tutti i libri di un dato editore;"
        "\n4 -Applicare un determinato sconto a tutti i libri di un determinato anno;"
        "\n5 -Ricerca dei libri con il minor scarto di prezzo;"
        "\n6 -Calcolo del costo totale dei libri di un dato anno;"
        "\n7 -Rimozione di tutti i libri di un determinato anno dalla biblioteca;"
        "\n0 -Chiude il programma\n");


        /* Presa in input della scelta dell'utente */

        printf("\nCosa si desidera fare?\t");
        scanf("%d", &key);

        switch (key){

            case 1:
                libroPiuVecchio(biblioteca, n); // chiamata alla funzione libroPiuVecchio in caso l'utente immeta 1;
            break;
            case 2:
                libroMenoCostoso(biblioteca, n); // chiamata alla funzione libroMenoCostoso in caso l'utente immeta 2;
            break;
            case 3:

                /* Presa in input dell'editore da ricercare con annessa allocazione dinamica e copia della stringa dal buffer al puntatore*/

                printf("\nInserire l'editore da cercare \t");
                getchar();
                fgets(buffer, 100, stdin);
                editore=malloc(sizeof(char*)*strlen(buffer)); 
                strcpy(editore, dropN(buffer));

                ricercaEditore(biblioteca, editore, n); // chiamata alla funzione ricerdaEditore in caso l'utente immeta 3;     
            break;
            case 4:

                /* Presa in input della percentuale di sconto da applicare e l'anno sul quale applicarla */

                printf("\nInserire la percentuale di sconto da applicare: \t");
                scanf("%f", &percentuale);
                printf("\nInserire l'anno sul quale applicare lo sconto: \t");
                scanf("%d", &anno);


                flag_sconto=scontaLibri(biblioteca, anno, percentuale, n); // chiamata alla funzione scontaLibri in caso l'utente immeta 4;

                /* In caso non fosse stato scontato alcun libro, il programma stamperebbe questo messaggio */
                if(flag_sconto==1){
                    printf("\n\nOps, potrebbe essere stato riscontrato un errore");
                }   
            break;
            case 5:
                trovaLibriPrezzoSimile(biblioteca, n); // chiamata alla funzione trovaLibriPrezzoSimile in caso l'utente immeta 5;
            break;
            case 6:

                /* Presa in input dell'anno di cui calcolare il costo totale dei libri */

                printf("\nInserire l'anno da calcolare: \t");
                scanf("%d", &anno);

                costoTotale(biblioteca, anno, n); // chiamata alla funzione trovaLibriPrezzoSimile in caso l'utente immeta 6;
            break;
            case 7:

                /* Presa in input dell'annata di cui eliminare i libri */

                printf("\nInserire l'annata dei libri da eliminare: \t");
                scanf("%d", &anno);

                n = eliminaLibri(biblioteca, anno, n); // chiamata alla funzione trovaLibriPrezzoSimile in caso l'utente immeta 7;

                /* Nel caso in cui dovessero essere stati eliminati tutti i libri, verrebbe stampato questo messaggio con successiva chiusura del programma */
                if(n==0){
                    printf("\nSono stati rimossi tutti i libri dalla biblioteca, arrivederci!\n ");
                    return 1;
                }
            break;
            case 0:
                flag=1; // Assegnamento del valore 1 al flag per uscire dal menu e chiudere il programma
            break;
            default:
                printf("\n\nSi prega di selezionare una delle opzioni\n\n"); // stampa di un messaggio di errore nel caso in cui non dovesse essere stato immesso nessun input corrispondente a funzioni;
            break;

        }


    }


    /* Chiusura del programma */

    printf("\n");
    system("PAUSE");	
    return 0;
}
