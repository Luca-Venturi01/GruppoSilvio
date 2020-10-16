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
    short int nGiorni = 0; // Variabile utilizzata per definire quanti giorni ha ogni mese.
    bool inputCheck = false; // Variabile utilizzata per controllare che l'input dei dati avvenga correttamente.
    bool isBisestile; // Variabile utilizzata per indicare se l'anno è bisestile oppure no.

    /* Inizio effettivo del programma */
    printf("Il Calendario in C\n");
    printf("-----------------------------------\n");

    /* Input dei dati */
    // Controllo sull'anno.
    while (!inputCheck)
    {
        printf("Inserisci l'anno in oggetto: ");
        scanfReturn = scanf("%hd", &anno);
        fflush(stdin);
        if(anno > 0 && anno < 3000 && scanfReturn == 1)
        {
            inputCheck = true;
        }
        else
            printf("Per favore, inserisci un anno corretto (solo un numero >0 e <3000)!\n");
    }

    // Controllo sul giorno.
    inputCheck = false;
    while (!inputCheck)
    {
        printf("\nInserisci il giorno: ");
        scanfReturn = scanf("%hd", &giorno);
        fflush(stdin);
        if(giorno > 0 && giorno < 8 && scanfReturn == 1)
            inputCheck = true;
        else
            printf("Per favore, inserisci un giorno valido (solo un numero >0 e <8)!\n");
    }

    /* Controllo se l'anno è bisestivo */
    if((anno % 400) == 0)
        isBisestile = true;
    else if((anno % 4) == 0 && (anno % 100) != 0)
        isBisestile = true;
    else
        isBisestile = false;

    // Output del risultato del controllo con tanto di riepilogo dei dati.
    printf("\nRiepilogo dati inseriti:\n\tAnno: %d, \n\tGiorno: %d, \n\tBisestile: %s", anno, giorno, isBisestile? "Si\'." : "No.");
    printf("\n-----------------------------------");

    /* Mostra Calendario */
    printf("\n\nCalendario, Anno: %hd\n\n", anno);

    /* Scrittura effettiva del calendario. */
    // Ciclo for per tutti i mesi, 1 = Gennaio e 12 = Dicembre.
    for(int mese = 1; mese < 13; mese++){
        switch (mese)
        {
            case 1: printf("\n-------------Gennaio---------------\n"); nGiorni=31; break;
            case 2: printf("\n-------------Febbraio--------------\n"); nGiorni=isBisestile?29:28; break;
            case 3: printf("\n-------------Marzo-----------------\n"); nGiorni=31; break;
            case 4: printf("\n-------------Aprile----------------\n"); nGiorni=30; break;
            case 5: printf("\n-------------Maggio----------------\n"); nGiorni=31; break;
            case 6: printf("\n-------------Giugno----------------\n"); nGiorni=30; break;
            case 7: printf("\n-------------Luglio----------------\n"); nGiorni=31; break;
            case 8: printf("\n-------------Agosto----------------\n"); nGiorni=31; break;
            case 9: printf("\n-------------Settembre-------------\n"); nGiorni=30; break;
            case 10: printf("\n-------------Ottobre---------------\n"); nGiorni=31; break;
            case 11: printf("\n-------------Novembre--------------\n"); nGiorni=30; break;
            case 12: printf("\n-------------Dicembre--------------\n"); nGiorni=31; break;
        }

        printf("  Lun  Mar  Mer  Gio  Ven  Sab  Dom\n");

        // Inserimento spazi bianchi in base al giorno di partenza scelto dall'utente.
        for(int i = 1; i < giorno; i++)
            printf("     ");

        // Scrittura effettiva dei giorni.
        for(int i = 1; i <= nGiorni; i++){
            printf("%5d", i);
            if((giorno + i - 1) % 7 == 0)
                printf("\n");
            if(i == nGiorni)
                giorno = (giorno + i - 1) % 7 + 1;
        }

        printf("\n\n");

    }

    // Comando che invita l'utente a premere il tasto "invio" per chiudere il programma.
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

}