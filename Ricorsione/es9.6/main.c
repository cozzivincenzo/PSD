#include <stdio.h>

// Prototipo della funzione 
int quadrato(int num, int cont, int somma);

int main(void){

    int num, somma=0; // Dichiarazione e inizializzazione di variabili utili ai calcoli

    /* Lettura in input del numero di cui calcolare il quadrato */
    printf("Inserire un numero da elevare al quadrato:\t");
    scanf("%d", &num);

    /* Stampa del risultato */
    printf("\n\nIl quadrato di %d vale %d\n\n", num, function(num, num, somma));    
    
    return 0;
}

/* FUNZIONE UTILE AL CALCOLO DEL QUADRATO DI UN NUMERO IN MODO RICORSIVO */
int quadrato(int num, int cont, int somma){
    
    /* Se il contatore scende a 0, e quindi sono stati sommati tutti i numeri, avviene il return del risultato */
    if(cont==0){
        return somma;
    }

    if(num==cont && somma==0){ // La prima volta, num viene reinizializzato a 1 e sommato a somma
        num=1;
        somma+=num;
    }else{ // Dalla seconda volta in poi, n incrementerà sempre di 2 e si aggiungerà a somma
        num+=2;
        somma+=num;
    } 
    return function(num, cont-1, somma); // Richiamo della funzione
}