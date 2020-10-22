/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N_VALS 10

int main() {

    // TODO:
    // Nothing atm

    /* Dichiarazione delle Variabili */
    int nVals = 0; // Variabile che rappresenta il numero di elementi che l'utente vuole inserire nel vettore.
    bool inputCheck = false; // Variabile utilizzata per verificare che l'input dell'utente sia corretto.
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.
    int random; // Rappresenta volta per volta il numero random generato da inserire nel vettore.
    int min, max; // Rappresentano l'intervallo, inserito in input dall'utente, di generazione di numeri random.
    int arrayPt1[N_VALS]; // E' il vettore utilizzato nella prima parte.
    int arrayPt2[N_VALS]; // E' il vettore utilizzato nella seconda parte.

    /* Inizio del Programma */

    /* Parte 1: Input utente, No random */
    printf("Esercizio 2: Parte 1\n");

    /* Input dei dati */
    for (int i = 0; i < N_VALS; i++)
    {
        printf("\nInserisci valore n.%d: ", i+1);
        scanfReturn = scanf("%d", &arrayPt1[i]);
        if(scanfReturn != 1){
            i--;
            printf("Ultimo valore non valido, per favore re-inserire!");
        }
        fflush(stdin);
    }
    
    /* Output valori vettore */
    printf("\nI valori contenuti nel vettore sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < N_VALS-1; i++)
        printf("%d, ", arrayPt1[i]);
    printf("%d <--\n", arrayPt1[N_VALS - 1]);

    /* Parte 2: Con Random, No input utente */
    printf("\nEsercizio 2: Parte 2\n");

    /* Input dei dati */
    // Controllo Min e Max richiedendo l'inserimento dei valori finchè max non è maggiore di min.
    while (!inputCheck)
    {
        printf("Inserisci l\'intervallo di generazione (min max): ");
        scanfReturn = scanf("%d %d", &min, &max);
        fflush(stdin); // Elimina eventuali caratteri indesiderati presenti in stdin.

        if(max >= min && min > 0 && scanfReturn == 2)
            inputCheck = true;
        else if(scanfReturn != 2)
            printf("L'input dei valori min e max non e\' corretto, per favore inserisci solo dei numeri!\n");
        else if(min > max)
            printf("Min non puo\' essere maggiore di Max, riprova!\n");
        else if(min < 0)
            printf("Min non puo\' essere minore di 0 (ovvero un numero negativo)!\n");
    }

    /* Generazione numeri random e inserimento nel vettore */
	for(int i = 0; i < N_VALS; i++)
        arrayPt2[i] = min + (rand()+time(NULL))%(max+1-min); // Genera numeri tra min e max.

    /* Output valori vettore */
    printf("\nI valori contenuti nel vettore sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < N_VALS-1; i++)
        printf("%d, ", arrayPt2[i]);
    printf("%d <--\n", arrayPt2[N_VALS - 1]);

    // Comando che invita l'utente a premere il tasto "invio" per chiudere il programma.
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

}