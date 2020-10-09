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
#include <stdbool.h>
#include <time.h>

int main() {

    /* TODO: */
    // 1 - Mettere %u per unsigned int nella scanf.
    // 2 - Fix messaggio di while(!check) nel caso qualcuno inserisca una lettera e non dei numeri.
    
    /* IDEE: */
    // 1 - Fare dei commenti tipo SUMMARY come in C# per tipo le variabili?

    /* Dichiarazione delle variabili */
    unsigned int cont = 1; // Rappresenta il numero di tentativi fatti per indovinare il numero
    int min, max; // Rappresentano l'intervallo di ricerca inserito in input dall'utente.
    int newMin, newMax; // Rappresentano il nuovo Min e Max dopo ogni tentativo di risposta.
    char temp; // Rappresenta la rispota dell'utente ad ogni domanda posta.
    int random = 0; // Rappresenta il numero random fornito come risposta dal computer all'utente.
    // int oldRandom; // Rappresenta una copia temporanea del valore random generato.
    bool check = false; // Variabile usata per controllare che il valore min sia più piccolo di max.
    bool preso = false; // Variabile usata per controllare se il "computer" ha azzeccato il numero.

    /* Input dei dati iniziali */
    printf("Esercizio 2: Pensa a un numero\n");
    printf("------------------------------\n");

    /* Controllo Min e Max */
    // Richiedo l'inserimento dei valori finchè max non è maggiore di min.
    while (!check)
    {
        printf("Inserisci l\'intervallo di ricerca (min max): ");
        scanf("%d %d", &min, &max);
        fflush(stdin); // Elimina eventuali caratteri indesiderati presenti in stdin.
        if(max > min)
            check = true;
        else if(min > max)
            printf("Min non puo\' essere maggiore di Max, riprova!\n");
        else
            printf("Min non puo\' essere uguale a Max, riprova!\n");      
    }
    
    /* Inizio del gioco */
    // Abbiamo scelto l'alternativa di gioco n. 2
    printf("Bene! Ora pensa a un numero compreso tra %d e %d\n", min, max);

    /* Generazione numero random (pseudo-casuale) */
    random = min + (rand()+time(NULL))%(max+1-min);

    while (!preso)
    {
        printf("Il numero e\' minore (<), uguale (=) o maggiore (>) di %d? ", random);
        scanf("%c", &temp);
        fflush(stdin);

        switch (temp)
        {
            case '>':
                newMin = random + 1;
                
                if ( newMin > max)
                    printf("Il numero a cui hai pensato e\' maggiore del massimo fornito in input!\n");
                else
                    random = newMin + (rand()+time(NULL))%(max+1-newMin);
                break;
            case '<':
                newMax = random - 1;

                if ( newMax < min )
                    printf("Il numero a cui hai pensato e\' minore del minimo fornito in input!\n");
                else
                    random = min + (rand()+time(NULL))%(newMax+1-min);
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
                // do something here...
                break;
        }
    }
    


    /* Codice per Testing */
    // printf("Min: %d, Max: %d\n", min, max);
    // printf("%d", random);

    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;
}