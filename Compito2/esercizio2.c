/**HEADER********************************************************************
 *  AUTORI: Lorenzo Gessi, Andrea Bedei, Fabio Notaro e Luca Venturi.
 *  EMAIL:  lorenzo.gessi@studio.unibo.it, andrea.bedei2@studio.unibo.it, fabio.notaro2@studio.unibo.it, luca.venturi29@studio.unibo.it
 *  DATA:   20201009
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
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int main() {

    /* Dichiarazione delle variabili */
    unsigned int cont = 0; // Rappresenta il numero di tentativi fatti per indovinare il numero
    int min, max; // Rappresentano l'intervallo di ricerca inserito in input dall'utente.
    int newMin, newMax; // Rappresentano il nuovo Min e Max dopo ogni tentativo di risposta.
    int random = 0; // Rappresenta il numero random fornito come risposta dal computer all'utente.
    int scanfReturn = 0; // Rappresenta il valore restituito dalla funzione scanf e server per controllare che l'utente abbia inserito correttamente 2 numeri.
    char temp; // Rappresenta la rispota dell'utente ad ogni domanda posta.
    // int oldRandom; // Rappresenta una copia temporanea del valore random generato.
    bool check = false; // Variabile usata per controllare che il valore min sia più piccolo di max.
    bool preso = false; // Variabile usata per controllare se il "computer" ha azzeccato il numero.

    /* Input dei dati iniziali */
    printf("Esercizio 2: Pensa a un numero|\n");
    printf("-------------------------------\n");

    /* Controllo Min e Max */
    // Richiedo l'inserimento dei valori finchè max non è maggiore di min.
    while (!check)
    {
        printf("Inserisci l\'intervallo di ricerca (min max): ");
        scanfReturn = scanf("%d %d", &min, &max);
        fflush(stdin); // Elimina eventuali caratteri indesiderati presenti in stdin.

        if(max >= min && min > 0 && scanfReturn == 2)
        {
            newMin = min;
            newMax = max;
            check = true;
        }
        else if(scanfReturn != 2)
            printf("L'input dei valori min e max non e\' corretto, per favore inserisci solo dei numeri!\n");
        else if(min > max)
            printf("Min non puo\' essere maggiore di Max, riprova!\n");
        else if(min < 0)
            printf("Min non puo\' essere minore di 0 (ovvero un numero negativo)!\n");
    }
    
    /* Inizio del gioco */
    // Abbiamo scelto l'alternativa di gioco n. 2
    printf("Bene! Ora pensa a un numero compreso tra %d e %d\n", min, max);

    /* Generazione numero random (pseudo-casuale) */
    random = min + (rand()+time(NULL))%(max+1-min);

    /* Inizio effettivo del gioco */
    // Il ciclo continua fino a quando il numero scelto dall'utente non viene azzeccato.
    while (!preso)
    {
        printf("Il numero e\' minore (<), uguale (=) o maggiore (>) di %d? ", random);
        scanf("%c", &temp);
        fflush(stdin);
        cont++;

        // Gestisco ogni possibile risposta dell'utente.
        switch (temp)
        {
            case '>':
                newMin = random + 1;

                if(newMin > max)
                    printf("Il numero a cui hai pensato e\' maggiore del massimo fornito in input!\n");
                else if (newMin > newMax)
                    printf("Non esiste un numero tra %d e %d\n", newMin-1, newMax+1);
                else
                    random = newMin + (rand()+time(NULL))%(newMax+1-newMin);
                break;
            case '<':
                newMax = random - 1;

                if(newMax < min)
                    printf("Il numero a cui hai pensato e\' minore del minore fornito in input!\n");
                else if (newMax < newMin)
                    printf("Non esiste un numero tra %d e %d\n", newMin-1, newMax+1);
                else
                    random = newMin + (rand()+time(NULL))%(newMax+1-newMin);
                break;
            case '=':
                printf("\nPerfetto, allora hai pensato a %d!\n", random);
                printf( "                                                               \n"
                        "YYYYYYYY        YYYYYYYY    EEEEEEEEEEEEEEEEEE      SSSSSSSSSSS\n"
                        "YYYYYYYY        YYYYYYYY    EEEEEEEEEEEEEEEEEE     SSSSSSSSSSSSS\n"
                        "YYYYYYYY        YYYYYYYY    EEEEEEEEEEEEEEEEEE    SSSSSSSSSSSSSSS\n"
                        "YYYYYYYY        YYYYYYYY    EEEEEEEEEEEEEEEEEE    SSSSSSSS    SSS\n"
                        " YYYYYYYY      YYYYYYYY     EEEEEEEE              SSSSSSSS\n"
                        "  YYYYYYYY    YYYYYYYY      EEEEEEEE              SSSSSSSS\n"
                        "   YYYYYYYY  YYYYYYYY       EEEEEEEEEEEEE          SSSSSSSS\n"
                        "    YYYYYYYYYYYYYYYY        EEEEEEEEEEEEE           SSSSSSSSSS\n"
                        "     YYYYYYYYYYYYYY         EEEEEEEEEEEEE            SSSSSSSSSS\n"
                        "      YYYYYYYYYYYY          EEEEEEEEEEEEE               SSSSSSSSS\n"
                        "       YYYYYYYYYY           EEEEEEEE                     SSSSSSSS\n"
                        "        YYYYYYYY            EEEEEEEE                     SSSSSSSS\n"
                        "        YYYYYYYY            EEEEEEEEEEEEEEEEE     SSS    SSSSSSSS\n"
                        "        YYYYYYYY            EEEEEEEEEEEEEEEEE     SSSSSSSSSSSSSSS\n"
                        "        YYYYYYYY            EEEEEEEEEEEEEEEEE      SSSSSSSSSSSSS\n"
                        "        YYYYYYYY            EEEEEEEEEEEEEEEEE       SSSSSSSSSSS\n");
                preso = true;
                printf("\n\nRiepilogo:\nNumero: %d, tentativi richiesti: %d", random, cont);
                break;
            default:
                printf("\nLa risposta da lei inserita non e\' valida, inserirne una corretta, per favore! (< | = | >)\n");
                break;
        }
    }
    
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

}