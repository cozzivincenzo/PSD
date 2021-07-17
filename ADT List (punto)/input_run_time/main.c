#include "functions.h"

int main (void){
    
	float distance; // Dichiarazione di una variabile utile alle sottofunzioni
	int num, flag=0, key, sinistro, destro, pos; // Dichiarazione di variabili utili al controllo
    item val; // Dichiarazione di un elemento
    list lista=newList(); // Dichiarazione e inizializzazione di una lista
    char criterio, coordinata; // Dichiarazione di due caratteri utili alle sottofunzioni

    /* Presa in input del numero di elementi da mettere in lista */
    printf("Quanti elementi si vogliono inserire nella lista?\t");
    scanf("%d", &num);

    /* Ciclo utile all'inserimento degli elementi nella lista */
    for(int i=0; i<num; i++) {
        printf("\nInserire il %d' punto:\n", i+1);
        val=input_item();
        lista=consList(val, lista);
    }
    lista=reverseList(lista);

    /* Iterazione del menu, con annesso switch per gestire la scelta dell'utente. */
	while(flag==0){

        printf("\n\n1 -Stampa del numero di coppie di punti con distanza inferiore a quella data;"
                "\n2 -Stampa della coppia di punti con distanza massima;"
                "\n3 -Riordinamento della lista per coordinata e criterio;"
                "\n4 -Creazione di una sottolista;"
                "\n5 -Inserimento di una sottolista nella lista originale;"
                "\n6 -Riordinamento della lista a zigzag"
                "\n0 -Chiude il programma\n");
                
        printf("\nCosa si desidera fare? ");
        scanf("%d", &key);
        fflush(stdin);

        switch (key){
            case 1:

                /* Lettura in input della distanza da confrontare */
				printf("\nInserire la distanza:\t");
				scanf("%f", &distance);

                distanza_minore(lista, distance); // Chiamata alla funzione utile alla ricerca del numero di punti con distanza inferiore a quella data
            break;
            case 2:  
                distanza_massima(lista); // Chiamata alla funzione utile alla ricerca dei punti con massima distanza
            break;
            case 3:

                /* Lettura in input dei caratteri utili alla scelta di criterio e coordinata secondo i quali ordinare la lista */
                fflush(stdin);
                printf("\nSecondo quale coordinata si desidera riordinare i punti della lista? (a->ascissa/o->ordinata) ");
                scanf("%s", &coordinata);

                fflush(stdin);
                printf("\nSecondo quale criterio si desidera riordinare i punti della lista? (c->crescente/d->descrescente) ");
                scanf("%s", &criterio);
                
                lista=riordina(lista, coordinata, criterio);
            break;
            case 4:

                /* Lettura in input degli estremi da cui estrapolare la sottolista */
                printf("\nInserire l'estremo sinistro:\t");
                scanf("%d", &sinistro);
                while(sinistro<0 || sinistro>sizeList(lista)){
                    printf("\nL'estremo sinistro deve rientrare negli elementi della lista.\n Si prega di reinserirlo:\t");
                    scanf("%d", &sinistro);
                }

                printf("\nInserire l'estremo destro:\t");
                scanf("%d", &destro);
                while(destro<sinistro || destro>sizeList(lista)){
                    printf("\nL'estremo destro deve rientrare negli elementi della lista e dev'essere maggiore del sinistro.\n Si prega di reinserirlo:\t");
                    scanf("%d", &destro);
                }


                list sublist=newList(); // Dichiarazione e inizializzazione di una nuova lista
                lista=sottolista(lista, sublist, sinistro, destro); // Chiamata alla funzione utile alla creazione della sottolista
            break;
            case 5:
                
                /* Lettura in input del numero di punti da aggiungere alla lista */
                printf("\nQuanti punti si desidera aggiungere alla lista originale?\t");
                scanf("%d", &num);

                list addlist=newList(); // Dichiarazione e inizializzazione di una nuova lista

                /* Lettura in input dei punti da aggiungere alla lista */
                for(int i=0; i<num; i++) {
                    printf("\nInserire il %d' punto:\n", i+1);
                    val=input_item();
                    addlist=consList(val, addlist);
                }
                addlist=reverseList(addlist);

                /* Lettura in input della posizione della posizione in cui aggiungere i punti */
                printf("\nIn quale posizione si desidera aggiungerli?\t");
                scanf("%d", &pos);

                lista=inserisci_lista(lista, addlist, pos); // Chiamata alla funzione utile all'inserimento di punti nella lista
            break;
            case 6:  
                lista=zigzag(lista); // Chiamata alla funzione utile al riordinamento dei punti nella lista
            break;
            case 0:
                flag=1; // Flag utile all'uscita dal menu e chiusura del programma
            break;
            default:
                printf("\n\nSi prega di selezionare una delle opzioni\n\n"); // Stampa di errore in caso l'utente inserisca un numero non presente nel menu
            break;
        }


    }
    
	return 0;
}
