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
    // TODO:
    // 1 - Sistemare giorni bianchi passando da mese a mese --> Basta aggiornare la variabile giorno (tipo uguale a i, dove i è l'ultimo giorno del mese precedente).
    // 2 - Aggiungere nome giorni (tipo: Lun Mar.... fare tipo %4 o %5d così tutto allineamento anche con i nomi dei giorni + lunghi).

    /* Dichiarazione delle variabili */
    short int anno = 0; // Variabile che rappresenta l'anno inserito dall'utente.
    short int giorno = 0; // Variabile che rappresenta il giorno inserito dall'utente.
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.
    short int tempDay = 0; // Variabile utilizzata per poter tener traccia del giorno finale di ogni mese.
    bool inputCheck = false; // Variabile utilizzata per controllare che l'input dei dati avvenga correttamente.
    bool isBisestile;

    /* Inizio effettivo del programma */
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
    printf("\nRiepilogo dati inseriti:\n\tAnno: %d, \n\tGiorno: %d, \n\tBisestile: %s", anno, giorno, isBisestile? "Si\'." : "No.");

    /* Mostra Calendario */
    printf("\n\n\nCalendario, Anno: %hd\n\n", anno);

    // Scrittura effettiva del calendario.
    // Ciclo for per tutti i mesi, 1 = Gennaio e 12 = Dicembre.
    for(int mese = 1; mese < 13; mese++){

        if(mese == 1 || mese == 3 || mese ==5 || mese ==7 || mese ==8 || mese == 10 || mese ==12) // Mesi con 31 giorni
        {
            switch (mese)
            {
                case 1: printf("\n--------Gennaio--------\n"); break;
                case 3: printf("\n--------Marzo--------\n"); break;
                case 5: printf("\n--------Maggio--------\n"); break;
                case 7: printf("\n--------Luglio--------\n"); break;
                case 8: printf("\n--------Agosto--------\n"); break;
                case 10: printf("\n--------Ottobre--------\n"); break;
                case 12: printf("\n--------Dicembre--------\n"); break;
            }

            // Spazi bianchi da mettere in base al giorno di partenza scelto dall'utente.
            for(int i = 1; i < giorno; i++)
                printf("   ");

            for(int i = 1; i <= 31; i++){
                printf("%3d", i);
                if((giorno + i - 1) % 7 == 0)
                    printf("\n");
            }
            printf("\n");
        }
        else if(mese == 2 && isBisestile == true)
        {
            printf("\n--------Febbraio--------\n");
            for(int i = 1; i <= 29; i++){
            printf("%3d", i);
            if((giorno + i - 1) % 7 == 0)
                printf("\n");
            }
            printf("\n");
        }
        else if(mese == 2 && isBisestile == false)
        {
            printf("\n--------Febbraio--------\n");
            for(int i = 1; i <= 28; i++){
            printf("%3d", i);
            if((giorno + i - 1) % 7 == 0)
                printf("\n");
            }
            printf("\n");
        }
        else
        {
            switch (mese)
            {
                case 4: printf("\n--------Aprile--------\n"); break;
                case 6: printf("\n--------Giugno--------\n"); break;
                case 9: printf("\n--------Settembre--------\n"); break;
                case 11: printf("\n--------Novembre--------\n"); break;
            }
            for(int i = 1; i <= 30; i++){
            printf("%3d", i);
            if((giorno + i - 1) % 7 == 0)
                printf("\n");
            }
            printf("\n");
        }


    }

    // Comando che invita l'utente a premere il tasto "invio" per chiudere il programma.
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

    // Al momento:
    // GCC: Process terminated with status 0 (0 minute(s), 0 second(s)) 0 error(s), 0 warning(s) (0 minute(s), 0 second(s))


}