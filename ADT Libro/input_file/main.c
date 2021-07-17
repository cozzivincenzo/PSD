#include "functions.h"

int main(int argc, char *argv[]) {


    /* Controllo del corretto inserimento di argomenti a riga di comando */
    if(argc!=2){
        printf("\nNumero errato di argomenti, si prega di scrivere solo il nome dell'eseguibile seguito dal nome del file\n\n");
        exit(-1);
    }

    FILE *file; // Dichiarazione del file dal quale leggere la biblioteca
    int n=0, anno, flag=0, key, flag_sconto; // Dichiarazione di variabili utili ai controlli
    char *titolo, *editore, buffer[100]=""; // Dichiarazione delle variabili utili a contenere le stringhe
    float prezzo, percentuale; // Dichiarazione delle variabili utili a impostare il prezzo dei libri


    file=fopen(argv[1], "r"); // Apertura in lettura del file
    
    /* Controllo della corretta apertura del file */
    if(file==NULL) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
    

    /* Ciclio utile al conto di righe presenti nel file */

    while(!feof(file)){
        fgets(buffer, 100, file);
        titolo=malloc(strlen(buffer));
        strcpy(titolo, dropN(buffer));
        fgets(buffer, 100, file);
        editore=malloc(strlen(buffer));
        fscanf(file,"%d\n",&anno);
        fscanf(file,"%f\n",&prezzo);
        n++;

    }

    Libro *biblioteca=malloc(sizeof(Libro)*n); // Dichiarazione e allocazione dinamica di un numero di puntatori all'ADT Libro pari ad n
    
    /* Controllo della corretta allocazione di memoria */
    if (biblioteca == NULL) {
        printf("\nError: Out Of Memory\n\n");
        exit(EXIT_FAILURE);
    }

    rewind(file); // Rilettura del file dall'inizio 


    /* Ciclio utile al riempimento della biblioteca tramite il file */

    for(int i=0; i<n; i++){
        fgets(buffer, 100, file);
        titolo=malloc(strlen(buffer));
        strcpy(titolo, dropN(buffer));
        fgets(buffer, 100, file);
        editore=malloc(strlen(buffer));
        strcpy(editore, dropN(buffer));
        fscanf(file,"%d\n",&anno);
        fscanf(file,"%f\n",&prezzo);

        biblioteca[i] = creaLibro(titolo, editore, prezzo, anno);
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

        printf("\nCosa si desidera fare? ");
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

    fclose(file);
    free(biblioteca);
    printf("\n");
    system("PAUSE");	
    return 0;
}
