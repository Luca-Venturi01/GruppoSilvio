/**HEADER********************************************************************
 *  AUTORI: Lorenzo Gessi, Andrea Bedei, Fabio Notaro e Luca Venturi.
 *  EMAIL:  lorenzo.gessi@studio.unibo.it, andrea.bedei2@studio.unibo.it, fabio.notaro2@studio.unibo.it, luca.venturi29@studio.unibo.it
 *  DATA:   20201023
 *  ES n.2: Scrivere un programma C che legga N numeri interi da tastiera e li memorizzi in un vettore. 
            Il programma deve generare un secondo vettore compattando i numeri contenuti nel primo vettore. 
            In particolare:
                - ogni numero che compare ripetuto nel primo vettore, deve comparire una sola volta nel secondo vettore
                - ogni numero uguale a zero presente nel primo vettore non deve comparire nel secondo vettore
            Prevedere anche la versione in cui i numeri sono generati random.
***END************************************************************************/

/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N_VALS 10

int main() {

    // TODO:
    // 1 - Controllare se la fase di input, esempio: valore > x ecc. ecc.
    // Refactoring? Meno codice stesse funzioni?

    /* Dichiarazione delle Variabili */
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.
    int nVals = 0; // Variabile che rappresenta il numero di elementi che l'utente vuole inserire nel vettore.
    int random; // Rappresenta volta per volta il numero random generato da inserire nel vettore.
    int min, max; // Rappresentano l'intervallo, inserito in input dall'utente, di generazione di numeri random.
    int arrayPt1[N_VALS]; // E' il vettore utilizzato nella prima parte.
    int arrayPt2[N_VALS]; // E' il vettore utilizzato nella seconda parte.
    bool inputCheck = false; // Variabile utilizzata per verificare che l'input dell'utente sia corretto.

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
        else if( arrayPt1[i] < 0){
            i--;
            printf("Ultimo valore non valido, per favore inserire solo valori > o = a 0!");
        }
        fflush(stdin);
    }
    
    /* Output valori vettore */
    printf("\nI valori contenuti nel vettore sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < N_VALS-1; i++)
        printf("%d, ", arrayPt1[i]);
    printf("%d <--\n", arrayPt1[N_VALS - 1]);

    /* Compattazione */
    for (int i = 0; i < N_VALS; i++)
    {
        for (int j = i + 1; j < N_VALS; j++)
        {
            if (arrayPt1[i] == arrayPt1[j])
            {
                
            }
            
        }
        
    }
    

    /* Parte 2: Con Random, No input utente */
    printf("\nEsercizio 2: Parte 2\n");

    /* Input dei dati */
    // Controllo Min e Max richiedendo l'inserimento dei valori finchè max non è maggiore di min.
    // Codice riusabile, WOW!
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