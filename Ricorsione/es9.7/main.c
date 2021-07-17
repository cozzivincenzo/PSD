#include <stdio.h>

// Prototipo della funzione
int euclide(int m, int n);

int main(void){

    int n, m; // Dichiarazione di variabili utili ai calcoli

    /* Lettura in input dei due numeri */
    printf("Inserire il primo numero:\t");
    scanf("%d", &n);
    printf("\nInserire il secondo numero:\t");
    scanf("%d", &m);
    while(n>m){
        printf("\nIl secondo numero dev'essere maggiore del primo, si prega di reinserirlo:\t");
        scanf("%d", &m);
    }    

    /* Stampa del risultato */
    printf("\nIl massimo comun divisore dei due numeri risulta essere: %d\n", euclide(m,n));

    return 0;
}

/* FUNZIONE UTILE AL CALCOLO DEL MASSIMO COMUN DIVISORE TRA DUE NUMERI IN MODO RICORSIVO */
int euclide(int m, int n){
    if(n==0){
        return m;
    } else {
        return euclide(n, m%n);
    }
}