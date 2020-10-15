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
    short int anno = 0; // Variabile che rappresenta l'anno inserito dall'utente.
    short int giorno = 0; // Variabile che rappresenta il giorno inserito dall'utente.
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.
    bool inputCheck = false; // Variabile utilizzata per controllare che l'input dei dati avvenga correttamente.
    bool isBisestile;
    
    /* Inizio del programma */
    printf("Il Calendario in C\n");
    printf("------------------\n");

    /* Input dei dati */
    while (!inputCheck)
    {
        // Anno
        printf("Inserisci l'anno in oggetto: ");
        scanfReturn = scanf("%hd", &anno);
        fflush(stdin);
        if(anno > 0 && anno < 3000 && scanfReturn == 1)
        {
            // Giorno
            printf("\nInserisci il giorno: ");
            scanfReturn = scanf("%hd", &giorno);
            fflush(stdin);
            if(giorno > 0 && giorno < 8 && scanfReturn == 1)
                inputCheck = true;
            else
                printf("Per favore, inserisci un giorno valido (solo un numero >0 e <8)!\n");
        }
        else
            printf("Per favore, inserisci un anno corretto (solo un numero >0 e <3000)!\n");   
    }

    /* Controllo se l'anno è bisestivo */
    if((anno % 400) == 0)
        isBisestile = true;
    else if((anno % 4) == 0 && (anno % 100) != 0)
        isBisestile = true;
    else
        isBisestile = false;

    // Output del risultato del controllo con tanto di riepilogo dei dati.
    printf("\nRiepilogo dati inseriti:\n\tAnno: %d, \tGiorno: %d, \tBisestile: %s", anno, giorno, isBisestile? "Sì" : "No");

    // Comando che invita l'utente a premere il tasto "invio" per chiudere il programma.    
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

    // Al momento:
    // GCC: Process terminated with status 0 (0 minute(s), 0 second(s)) 0 error(s), 0 warning(s) (0 minute(s), 0 second(s))


}