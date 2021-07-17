#include "functions.h"


/* Sottofunzione utile a selezionare la subroutine da eseguire, basandosi su coordinata e criterio inseriti dall'utente */

void riordina(Punto *p, char coordinata, char criterio, int num){

   
    if(coordinata=='a'){
        if(criterio=='c'){          
            a_crescente(p, num);
        } else {
            a_decrescente(p, num);
        }
    } else {
        if(criterio=='c'){
            o_crescente(p, num);
        } else {
            o_decrescente(p, num);
        }
    }

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ascisse */

void a_crescente(Punto *p, int num){

    
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
        stampa(p[i]);
        printf("\n");
    }

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ascisse */

void a_decrescente(Punto *p, int num){

    
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
        stampa(p[i]);
        printf("\n");
    }

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ordinate */

void o_crescente(Punto *p, int num){

    
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
        stampa(p[i]);
        printf("\n");
    }

}

/* Sottofunzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ordinate */

void o_decrescente(Punto *p, int num){

    
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
        stampa(p[i]);
        printf("\n");
    }

}