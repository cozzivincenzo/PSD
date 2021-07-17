#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo della funzione
int palindromo(char *str, int n);

int main(void){

    int flag; // Dichiarazione di una variabile di controllo
    char *str=malloc(sizeof(char)*50); // Dichiarazione e allocazione di memoria per un puntatore a carattere 

    // Lettura in input della parola da controllare
    printf("Inserire una parola:\n");
    scanf("%s", str);

    flag=palindromo(str, strlen(str)-1); // Chiamata alla funzione

    /* Controllo e stampa del risultato */
    if(flag==0){
        printf("\nLa parola è palindroma\n\n");
    } else {
        printf("\nLa parola non è palindroma\n\n");
    }

    return 0;
}

/* FUNZIONE UTILE A CONTROLLARE SE DUE PAROLE SONO PALINDROME O MENO IN MODO RICORSIVO */
int palindromo(char *str, int n){

    /* Se n risulta minore o uguale a 0, la parola risulta essere palindroma */
    if(n<=0){
        return 0;
    }

    /* Confronto del primo carattere con l'ultimo */
    if(str[0]==str[n]){
        palindromo(str+1, n-2); // Richiamo della funzione 
    } else {
        return 1; // Se i caratteri sono diversi, la parola non è palindroma e viene ridato 1 al main
    }
}