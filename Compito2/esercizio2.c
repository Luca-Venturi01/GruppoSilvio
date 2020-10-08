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

    /* TODO: */
    // 1 - Sarebbe da controllare che il numero il numero max sia > di min
    //     ma senza il while è un po' difficile, potrei fare uno scambio da codice se min > max magari
    //     notificarlo poi all'utente.

    /* Dichiarazione delle variabili */
    unsigned int cont = 0; // Rappresenta il numero di tentativi fatti per indovinare il numero
    int min, max; // Rappresentano l'intervallo di ricerca inserito in input dall'utente.
    char temp; // Rappresenta la rispota dell'utente ad ogni domanda posta.
    int num = 0; // Rappresenta la risposta fornita dal computer all'utente.


    /* Input dei dati iniziali */
    printf("Esercizio 2: Pensa a un numero\n");
    printf("------------------------------\n");
    printf("Inserisci l\'intervallo di ricerca (min max): ");
    scanf("%d %d", &min, &max);
    fflush(stdin); // Elimina eventuali caratteri indesiderati presenti in stdin.
    printf("Bene! Ora pensa a un numero compreso tra %d e %d\n", min, max);

    /* Inizio del gioco */
    // Abbiamo scelto l'alternativa di gioco n. 2
    printf("Il numero e\' minore (<), uguale (=) o maggiore (>) di %d? ", num = min);
    scanf("%c", &temp);
    fflush(stdin);

    switch (temp)
    {
        case '>':
            printf("\nHai inserito maggiore");
            // do something here...
            break;
        case '<':
            printf("\nHai inserito minore");
            // do something here...
            break;
        case '=':
            printf("\nPerfetto, allora hai pensato a %d!\n", num);
            break;
        default:
            printf("\nIl carattere da lei inserito non e\' valido, inserire una risposta corretta, per favore! (< | = | >)");
            break;
    }

    /* Codice per Testing */
    // printf("Min: %d, Max: %d\n", min, max);

    printf("\nPremi invio per chiudere il terminale.");
    getchar();
    return 0;
}