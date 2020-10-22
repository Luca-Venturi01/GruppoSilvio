/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

    // TODO:
    // 1 - Far scegliere all'utente quanti valori inserire.

    /* Dichiarazione delle Variabili */
    int nVals = 0; // Variabile che rappresenta il numero di elementi che l'utente vuole inserire nel vettore.
    bool inputCheck = false; // Variabile utilizzata per verificare che l'input dell'utente sia corretto.
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.

    /* Input dei dati */
    // Controllo il numero di elementi che l'utente vuole inserire nel vettore.
    while(!inputCheck){

        printf("Quanti elementi vuoi inserire all'interno del vettore? ");
        scanfReturn = scanf("%d", &nVals);
        fflush(stdin);

        if (nVals > 1 && scanfReturn == 1)
            inputCheck = true;
        else
            printf("Inserire un valore valido, per favore.\n");
    }

    return 0;

}