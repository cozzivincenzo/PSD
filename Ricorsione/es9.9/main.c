#include <stdio.h>

// Prototipo della funzione
int tartaglia(int n, int i);

int main() {

    int n = 0, row, col; // Dichiarazione di variabili utili ai calcoli

    /* Lettura in input del numero di righe con cui creare il triangolo */
    printf ("Inserire il numero di righe:\t");
    scanf("%d", &n);

    int matrix[n+1][n+1]; // Dichiarazione di una matrice di n+1 righe e colonne

    /* Ciclo utile al riempimento della matrice e alla stampa del triangolo */
    for(int k = 0; n >= k; k++) {
        for(int m = 0; k >= m; m++) {
            matrix[k][m]=tartaglia(k, m);
            printf("%d ", matrix[k][m]);
        }
        printf("\n");
    }

    /* Lettura in input di riga e colonna del valore da cercare nel triangolo */
    printf("Inserire riga:\t");
    scanf("%d", &row);
    printf("Inserire colonna:\t");
    scanf("%d", &col);

    /* Stampa del risultato */
    printf("\n\nAlla riga %d e colonna %d c'è il numero %d\n\n", row, col, matrix[row][col]);
    return 0;
}

int tartaglia(int n, int i) {
    if(n == i || i == 0){ // Se la riga corrisponde alla colonna o a 0, viene ridato 1 al main
        return 1;
    } else {
        return tartaglia(n-1, i) + tartaglia(n-1, i-1); // Richiamo della funzione per il calcolo di valori tramite l'apposita formula ricorsiva
    }
}