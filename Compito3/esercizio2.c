/**HEADER********************************************************************
 *  AUTORI: Lorenzo Gessi, Andrea Bedei, Fabio Notaro e Luca Venturi.
 *  EMAIL:  lorenzo.gessi@studio.unibo.it, andrea.bedei2@studio.unibo.it, fabio.notaro2@studio.unibo.it, luca.venturi29@studio.unibo.it
 *  DATA:   
 *  ES n.2: Scrivere un programma C che stampi il calendario di un anno, chiedendo all'utente di specificare 
            l'anno in oggetto e il numero che identifica il primo giorno dell'anno (1=lunedì, 7=domenica).
***END************************************************************************/

/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

    /* Dichiarazione delle variabili */
    unsigned short int anno = 0; // Variabile che rappresenta l'anno inserito dall'utente.
    bool inputCheck = false; // Variabile utilizzata per controllare che l'input dei dati avvenga correttamente.

    /* Inizio del programma */
    printf("Il Calendario in C");
    printf("------------------");

    /* Input dei dati */
    // Anno
    while (!inputCheck)
    {
        printf("Inserisci l'anno in oggetto: ");
        
        if(anno > 0 && anno < 3000 && scanf("%d", &anno) == 1)
            inputCheck = true;
    }

    

    
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

}