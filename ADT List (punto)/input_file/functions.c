#include "functions.h"


/* Funzione utile alla ricerca del numero di punti con distanza inferiore a quella data */

void distanza_minore(list lista, float distance){

    float tmp; // Dichiarazione di una variabile temporanea atta a contenere la distanza dei nodi ad ogni ciclo
    int cont=0; // Dichiarazione e inizializzazione di una variabile contatore
    list tmp_list=newList(); // Dichiarazione e inizializzazione di una lista temporanea
    tmp_list=tailList(lista); // Puntamento della lista temporanea al nodo successivo della lista originale

    /* Algoritmo utile al calcolo e controllo delle distanze */
    while(!emptyList(lista)){
        while(!emptyList(tmp_list)){
            tmp=distanza(getFirst(lista), getFirst(tmp_list));
            if(tmp<distance){
                cont++;
            }
            tmp_list=tailList(tmp_list);
        }
        lista=tailList(lista);
        if(!emptyList(tailList(lista))){
            tmp_list=tailList(lista);
        }
    }

    /* Stampa del risultato */
    printf("Sono presenti %d coppie di punti la cui distanza risulta essere inferiore a %0.2f\n", cont, distance);

}


/* Funzione utile alla ricerca dei punti con massima distanza */

void distanza_massima(list lista){

    item tmp_p1, tmp_p2; // Dichiarazione di due elementi temporanei
    list tmp_list=newList(); // Dichiarazione di una lista temporanea
    tmp_list=lista; // Assegnamento della lista originale alla lista temporanea
    float tmp, max=distanza(getFirst(lista), getFirst(tmp_list)); // Dichiarazione di variabili di controllo

    /* Algoritmo utile al calcolo e controllo della distanza massima, confrontando tra loro tutti i punti */
    while(!emptyList(lista)){
        while(!emptyList(tmp_list)){
            tmp=distanza(getFirst(lista), getFirst(tmp_list));
            if(tmp<0){
                tmp=tmp*-1;
            }
            if(tmp>max){
                max=tmp;
                tmp_p1=getFirst(lista);
                tmp_p2=getFirst(tmp_list);
            }
            tmp_list=tailList(tmp_list);
        }
        lista=tailList(lista);
        if(!emptyList(tailList(lista))){
            tmp_list=tailList(lista);
        }
    }

    /* Stampa del risultato */
    printf("La coppia di punti con distanza maggiore risulta essere: \n");
    output_item(tmp_p1);
    printf("||");
    output_item(tmp_p2);
    printf("\ncon distanza pari a %0.2f", max);


}



/* Funzione utile a selezionare la subroutine da eseguire, basandosi su coordinata e criterio inseriti dall'utente */

list riordina(list lista, char coordinata, char criterio){

    /* Selezione dell'algoritmo di ordinamento */
    if(coordinata=='a'){
        if(criterio=='c'){         
            lista=a_crescente(lista);
        } else {
            lista=a_decrescente(lista);
        }
    } else {
        if(criterio=='c'){
            lista=o_crescente(lista);
        } else {
            lista=o_decrescente(lista);
        }
    }

    return lista;

}

/* Funzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ascisse */

list a_crescente(list lista){

    int size=sizeList(lista); // Ottenimento della grandezza della lista per decretare il numero di iterazioni da svolgere
    item p[size], tmp; // Dichiarazione di variabili utili al controllo
    
    for(int i=0; i<size; i++){
        p[i]=getFirst(lista);
        lista=tailList(lista);
    }

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (ascissa(p[i]) < ascissa(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    lista=newList();

    for(int i=0; i<size; i++){
        lista=consList(p[i], lista);
    }

    outputList(lista);
    return lista;
}

/* Funzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ascisse */

list a_decrescente(list lista){
    
    int size=sizeList(lista); // Ottenimento della grandezza della lista per decretare il numero di iterazioni da svolgere
    item p[size], tmp; // Dichiarazione di variabili utili al controllo
    
    for(int i=0; i<size; i++){
        p[i]=getFirst(lista);
        lista=tailList(lista);
    }

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (ascissa(p[i]) > ascissa(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    lista=newList();

    for(int i=0; i<size; i++){
        lista=consList(p[i], lista);
    }

    outputList(lista);
    return lista;

}

/* Funzione utile a riordinare l'array di punti, in ordine crescente, basandosi sulle ordinate */

list o_crescente(list lista){

    
    int size=sizeList(lista); // Ottenimento della grandezza della lista per decretare il numero di iterazioni da svolgere
    item p[size], tmp; // Dichiarazione di variabili utili al controllo
    
    for(int i=0; i<size; i++){
        p[i]=getFirst(lista);
        lista=tailList(lista);
    }

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (ordinata(p[i]) < ordinata(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    lista=newList();

    for(int i=0; i<size; i++){
        lista=consList(p[i], lista);
    }

    outputList(lista);
    return lista;

}

/* Funzione utile a riordinare l'array di punti, in ordine decrescente, basandosi sulle ordinate */

list o_decrescente(list lista){

    
    int size=sizeList(lista); // Ottenimento della grandezza della lista per decretare il numero di iterazioni da svolgere
    item p[size], tmp; // Dichiarazione di variabili utili al controllo
    
    for(int i=0; i<size; i++){
        p[i]=getFirst(lista);
        lista=tailList(lista);
    }

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (ordinata(p[i]) > ordinata(p[j]))
            {
                tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    lista=newList();

    for(int i=0; i<size; i++){
        lista=consList(p[i], lista);
    }

    outputList(lista);
    return lista;

}


/* Funzione utile alla creazione della sottolista */

list sottolista(list lista, list sublist, int sinistro, int destro) {

    int size=sizeList(lista), num=destro-sinistro+1, cont=0; // Dichiarazione e inizializzazione di variabili utili al controllo
    item array[num]; // Dichiarazione di un array di elementi atto a contenere gli elementi da riscrivere nella lista originale

    /* Algoritmo che estrapola gli elementi della lista creando la sottolista in base agli estremi */
    for(int i=0; i<size; i++){
        if(i>=sinistro&&i<=destro){
            sublist=consList(getFirst(lista), sublist);
        }else{
            array[cont]=getFirst(lista);
            cont++;
        }
        lista=tailList(lista);
    }

    lista=newList(); // Reinizializzazione della lista

    /* Reinserimento degli elementi in lista */
    for(int i=0; i<size-num; i++){
        lista=consList(array[i], lista);
    }
    sublist=reverseList(sublist);
    lista=reverseList(lista);

    /* Stampa del risultato */
    printf("\nLa sottolista creata risulta avere i seguenti elementi:\n");
    outputList(sublist);
    printf("\n\nAlla lista originale sono rimasti i seguenti elementi:\n");
    outputList(lista);
    return lista;
}


/* Funzione utile all'inserimento di punti nella lista */

list inserisci_lista(list lista, list sublist, int pos){
    
    list tmp=newList(); // Dichiarazione e inizializzazione di una lista temporanea
    int size=sizeList(lista)+sizeList(sublist), cont=sizeList(sublist); // Dichiarazione e inizializzazione di variabili utili al controllo

    /* Algoritmo che riempie la lista temporanea con gli elementi della lista originale e gli elementi della sottolista da inserire */
    for(int i=0; i<size; i++){
        if(emptyList(lista)){
            break;
        } else {
            if(i!=pos){
                tmp=consList(getFirst(lista), tmp);
                lista=tailList(lista);
            } else {
                while(!emptyList(sublist)){
                    tmp=consList(getFirst(sublist), tmp);
                    sublist=tailList(sublist);
                }
            }
        }
    }
    tmp=reverseList(tmp);
    
    lista=newList(); // Reinizializzazione della lista
    lista=tmp; // Assegnamento della lista temporanea alla lista originale

    return lista;

}


/* Funzione utile al riordinamento dei punti nella lista */

list zigzag(list lista){

    int size=sizeList(lista); // Ottenimento della grandezza della lista per decretare il numero di iterazioni da svolgere
    item p[size], tmp; // Dichiarazione di variabili utili al controllo
    

    /* Algoritmo di ordinamento crescente in base all'ascissa */
    for(int i=0; i<size; i++){
        p[i]=getFirst(lista);
        lista=tailList(lista);
    }

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if(ascissa(p[i]) == ascissa(p[j])){

                if (ordinata(p[i]) < ordinata(p[j]))
                {
                    tmp = p[j];
                    p[j] = p[i];
                    p[i] = tmp;
                }

            } else {

                if (ascissa(p[i]) < ascissa(p[j]))
                {
                    tmp = p[j];
                    p[j] = p[i];
                    p[i] = tmp;
                }

            }
            
        }
    }


    /* Una volta ordinato in modo crescente, si procede a fare uno swap degli elementi vicini, a partire dal secondo a due a due */
    for(int i=1; i<size-1; i+=2){
        tmp=p[i+1];
        p[i+1]=p[i];
        p[i]=tmp;
    }

    lista=newList(); // Reinizializzazione della lista

    /* Reinserimento degli elementi in lista */
    for(int i=0; i<size; i++){
        lista=consList(p[i], lista);
    }

    outputList(lista);
    return lista;

}