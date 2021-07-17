#include "functions.h"

/* FUNZIONE UTILE A CONTROLLARE SE IL NUMERO E' PRIMO IN MODO ITERATIVO */
void controlloIterativo(int n){
    int flag=0; // Dichiarazione e inizializzzazione di una variabile di controllo
    
    /* Ciclo utile alla scomposizione del numero */
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    /* Stampa del risultato */
    if(flag==0){
        printf("\n\nIl numero è primo\n\n");
    } else {
        printf("\n\nIl numero non è primo\n\n");
    }
}

/* FUNZIONE UTILE A CONTROLLARE SE IL NUMERO E' PRIMO IN MODO RICORSIVO */
int controlloRicorsivo(int n, int i){
    
    /* Se il numero risulta divisibile per un numero compreso tra sé stesso e 1 (esclusi), viene ridato 1 alla funzione chiamante */
    if(i==1){
        return 0;
    } else {
        if(n%i==0){
            return 1;
        }
        controlloRicorsivo(n, i-1); // Richiamo della funzione
    }
}