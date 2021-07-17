#include "functions.h"

int run_test_case(char *tc_id){
    
    char input_fname[M], output_fname[M], oracle_fname[M]; // Dichiarazione delle stringhe atte a contenere i nomi dei file
    char criterio, coordinata; // Dichiarazione delle stringhe atte a contenere criterio e coordinata sui quali basare l'ordinamento
    int num=0, cont=0; // Dichiarazione di variabili utili ai controlli
    float x, y; // Dichiarazione delle variabili atte a contenere le coordinate

    /* Creazione dei nomi dei file */

    strcpy(input_fname,tc_id);
    strcat(input_fname,"_input.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");


    FILE *input_file; // Dichiarazione dei file di input dai quali leggere e output sul quale scrivere

    /* Apertura del file di input */

    input_file = fopen(input_fname, "r");


    /* Controllo della corretta apertura del file */

    if( input_file==NULL) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }


    /* Conteggio del numero di coppie di coordinate presenti nel file */

    while(fscanf(input_file, "%f%f", &x, &y)==2){
        num++;
    }  


    /* Lettura di criterio e coordinata dal file */

    fscanf(input_file, "%c %c", &criterio, &coordinata);


    /* Chiusura e riapertura del file in modo tale da poter ricominciare a leggere dalla prima riga */

    fclose(input_file);
    input_file = fopen(input_fname, "r");

    Punto *p = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dal file di input, passate poi alla funzione creaPunto del file punto.c */
    
    while(fscanf(input_file, "%f%f", &x, &y)==2){
        p[cont]=creapunto(x,y);
        cont++;
    }  

    cont=0;
    

    // Chiamata alla sottofunzione utile a gestire il riordinamento dell'array di punti

    riordina(p, coordinata, criterio, num, output_fname);

    
 
    FILE *oracle_file = fopen(oracle_fname, "r"); // Dichiarazione del file oracolo


    /* Conteggio del numero di coppie di coordinate presenti nel file */

    while(fscanf(input_file, "%f%f", &x, &y)==2){
        num++;
    }  


    /* Chiusura e riapertura del file in modo tale da poter ricominciare a leggere dalla prima riga */

    fclose(input_file);
    input_file = fopen(input_fname, "r");

    Punto *oracle_array = (Punto*)malloc(sizeof(Punto*)*num); // Allocazione dinamica di un numero di punti pare a num


    /* Creazione dei vari punti prendendo le coordinate (x;y) dal file oracolo, passate poi alla funzione creaPunto del file punto.c */
    
    while(fscanf(input_file, "%f%f", &x, &y)==2){
        oracle_array[cont]=creapunto(x,y);
        cont++;
    }  
    
    int flag = confronta_punti(p, oracle_array, num); // Confronto dell'array di input e dell'array oracolo per la verifica del corretto funzionamento del programma


    /* Chiusura dei file */

    fclose(input_file);
    fclose(oracle_file);

    return flag; // Ritorno del risultato del confronto 
}

/* Sottofunzione utile a selezionare la subroutine da eseguire, basandosi su coordinata e criterio inseriti dall'utente */

void riordina(Punto *p, char coordinata, char criterio, int num, char output_fname[]){

   
    if(coordinata=='a'){
        if(criterio=='c'){          
            a_crescente(p, num, output_fname);
        } else {
            a_decrescente(p, num, output_fname);
        }
    } else {
        if(criterio=='c'){
            o_crescente(p, num, output_fname);
        } else {
            o_decrescente(p, num, output_fname);
        }
    }

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ascisse */

void a_crescente(Punto *p, int num, char output_fname[]){

    FILE *output_file = fopen(output_fname, "w"); // Creazione del file di output sul quale andare a scrivere il l'array riordinato
    Punto tmp;

    for(int i=0; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(ascissa(p[i]) > ascissa(p[j]))
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }    
        }
    }

    for(int i=0; i<num; i++){
        fprintf(output_file, "%f %f\n", ascissa(p[i]), ordinata(p[i])); // Scrittura sul file di output
    }

    fclose(output_file); // Chiusura del file di output

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ascisse */

void a_decrescente(Punto *p, int num, char output_fname[]){

    FILE *output_file = fopen(output_fname, "w"); // Creazione del file di output sul quale andare a scrivere il l'array riordinato
    Punto tmp;

    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if (ascissa(p[i]) < ascissa(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    for(int i=0; i<num; i++){
        fprintf(output_file, "%f %f\n", ascissa(p[i]), ordinata(p[i])); // Scrittura sul file di output
    }

    fclose(output_file); // Chiusura del file di output

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ordinate */

void o_crescente(Punto *p, int num, char output_fname[]){

    FILE *output_file = fopen(output_fname, "w"); // Creazione del file di output sul quale andare a scrivere il l'array riordinato
    Punto tmp;

    for(int i=0; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(ordinata(p[i]) > ordinata(p[j]))
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }    
        }
    }

    for(int i=0; i<num; i++){
        fprintf(output_file, "%f %f\n", ascissa(p[i]), ordinata(p[i])); // Scrittura sul file di output
    }

    fclose(output_file); // Chiusura del file di output

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ordinate */

void o_decrescente(Punto *p, int num, char output_fname[]){

    FILE *output_file = fopen(output_fname, "w"); // Creazione del file di output sul quale andare a scrivere il l'array riordinato
    Punto tmp;

    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if (ordinata(p[i]) < ordinata(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    for(int i=0; i<num; i++){
        fprintf(output_file, "%f %f\n", ascissa(p[i]), ordinata(p[i])); // Scrittura sul file di output
    }

    fclose(output_file);  // Chiusura del file di output

}

/* Sottofunzione utile a confrontare i due array di punti */

int confronta_punti(Punto *p1, Punto *p2, int n) {

    for(int i=0;i<n;i++){
        if( ascissa(p1[i]) != ascissa(p1[i]) || ordinata(p1[i]) != ordinata(p1[i]) ){
            return 1;
        }
    }

    return 0;

}