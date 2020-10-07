/**HEADER********************************************************************
 *  AUTORI: xx
 *  EMAIL:  xx
 *  DATA:   xx
 *  ES n.2: L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.
            - L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max). Se i valori inseriti non rispettano il vincolo 0<min≤max, l’operazione di lettura va ripetuta.
            - L’utente pensa ad un numero compreso tra min e max.
            - Il programma cerca di indovinare la scelta dell’utente e propone un numero. A seconda della situazione l’utente deve dire al programma se
                + il numero da indovinare è più piccolo;
                + il numero da indovinare è più grande;
                + ha indovinato.
            - Non poniamo limite al numero di tentativi   
***END************************************************************************/

/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Esercizio 2: Pensa a un numero\n");
    printf("------------------------------");


    printf("\nPremi invio per chiudere il terminale.");
    getchar();
}