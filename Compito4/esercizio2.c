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

int main() {

    // TODO:
    // 1 - Controllare se la fase di input, esempio: valore > x ecc. ecc.
    // 2 - Cercare un modo per creare pseudo-dinamicamente i nuovi vettori con i duplicati.
    // 4 - Controllare commenti.

    /* Dichiarazione delle Variabili */
    short int scanfReturn = 0; // Variabile utilizzata per controllare se la scanf ha ricevuto quello che si aspettava.
    int nVals = 0; // Variabile che rappresenta il numero di elementi che l'utente vuole inserire nel vettore.
    int min, max; // Rappresentano l'intervallo, inserito in input dall'utente, di generazione di numeri random.
    bool inputCheck = false; // Variabile utilizzata per verificare che l'input dell'utente sia corretto.
    bool duplicateCheck = true; // Variabile utilizzata per evitare che piú duplicati di un singolo numero vengano considerati nella creazione del nuovo array (e nell'inserimento dei valori).
    int cont = 0; // Variabile utilizzata per contare il numero di elementi che dovranno essere presenti nel nuovo vettore.
    int index = 0; // Variabile che rappresenta l'indice dei nuovi vettori (no duplicati e/o 0) che ci permette di inserire nella posizione giusta gli elementi.

    /* Inizio del Programma */

    /* Parte 1: Input utente, No random */
    printf("Esercizio 2: Parte 1\n");

    /* Input dei dati */

    // Richiedo e Controllo il numero di elementi che l'utente vuole inserire nel vettore.
    while(!inputCheck){

        printf("Quanti elementi vuoi inserire all'interno del primo vettore? ");
        scanfReturn = scanf("%d", &nVals);
        fflush(stdin);

        if (nVals > 1 && scanfReturn == 1)
            inputCheck = true;
        else
            printf("Inserire un valore valido, per favore.\n");
    }
    int arrayPt1[nVals]; // E' il vettore utilizzato nella prima parte.


    // Inserisco gli elementi nel vettore.
    for (int i = 0; i < nVals; i++)
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
    for (int i = 0; i < nVals - 1; i++)
        printf("%d, ", arrayPt1[i]);
    printf("%d <--\n", arrayPt1[nVals - 1]);

    /* Cerco i valori duplicati */
    for (int i = 0; i < nVals; i++)
    {
        duplicateCheck = true;

        for (int j = i - 1; j >= 0; j--)
            if(arrayPt1[i] == arrayPt1[j])
                duplicateCheck = false;
        
        if(duplicateCheck)
            cont++;
        
    }

    /* Compattazione: Creo il nuovo array */\
    int arrayNoDuplicatiPt1[cont]; // E' il vettore senza duplicati ne' 0 utilizzato nella prima parte.
    for (int i = 0; i < nVals; i++)
    {
        // Cosí trovo gli elementi del vettore = 0.
        if(arrayPt1[i] == 0)
        {
            cont--;
            continue;
        }

        duplicateCheck = true;
        for (int j = i - 1; j >= 0; j--)
            if(arrayPt1[i] == arrayPt1[j])
                duplicateCheck = false;
        
        if(duplicateCheck) {
            arrayNoDuplicatiPt1[index] = arrayPt1[i];
            index++;
        }
    }

    /* Output valori vettore senza duplicati e/o 0 */
    printf("\nI valori contenuti nel nuovo vettore (no duplicati e/o 0) sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < cont - 1; i++)
        printf("%d, ", arrayNoDuplicatiPt1[i]);
    printf("%d <--\n", arrayNoDuplicatiPt1[cont - 1]);

    /* Parte 2: Con Random, No input utente */
    printf("\n/--------------------------------------------------------------------\\\n");
    printf("----------------------------------------------------------------------\n");
    printf("\\--------------------------------------------------------------------/\n");
    printf("\nEsercizio 2: Parte 2\n");

    /* Input dei dati */

    // Richiedo e Controllo il numero di elementi che l'utente vuole inserire nel vettore.
    inputCheck = false;
    while(!inputCheck){

        printf("Quanti elementi vuoi inserire all'interno del secondo vettore? ");
        scanfReturn = scanf("%d", &nVals);
        fflush(stdin);

        if (nVals > 1 && scanfReturn == 1)
            inputCheck = true;
        else
            printf("Inserire un valore valido, per favore.\n");
    }
    int arrayPt2[nVals]; // E' il vettore utilizzato nella seconda parte.

    // Controllo Min e Max richiedendo l'inserimento dei valori finchè max non è maggiore di min.
    // Codice riusabile, WOW!
    inputCheck = false;
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

    /* Generazione numeri random e inserimento dei valori nel vettore */
	for(int i = 0; i < nVals; i++)
        arrayPt2[i] = min + (rand()+time(NULL))%(max+1-min); // Genera numeri tra min e max.

    /* Output valori vettore */
    printf("\nI valori contenuti nel vettore sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < nVals-1; i++)
        printf("%d, ", arrayPt2[i]);
    printf("%d <--\n", arrayPt2[nVals - 1]);

    /* Cerco i valori duplicati */
    duplicateCheck = true;
    cont = 0;
    for (int i = 0; i < nVals; i++)
    {
        duplicateCheck = true;

        for (int j = i - 1; j >= 0; j--)
            if(arrayPt2[i] == arrayPt2[j])
                duplicateCheck = false;
        
        if(duplicateCheck)
            cont++;
        
    }

    /* Compattazione: Creo il nuovo array */
    int arrayNoDuplicatiPt2[cont]; // E' il vettore senza duplicati ne' 0 utilizzato nella prima parte.
    index = 0;
    for (int i = 0; i < nVals; i++)
    {
        // Cosí trovo gli elementi del vettore = 0.
        if(arrayPt2[i] == 0)
        {
            cont--;
            continue;
        }

        duplicateCheck = true;
        for (int j = i - 1; j >= 0; j--)
            if(arrayPt2[i] == arrayPt2[j])
                duplicateCheck = false;
        
        if(duplicateCheck) {
            arrayNoDuplicatiPt2[index] = arrayPt2[i];
            index++;
        }
    }

    /* Output valori vettore senza duplicati e/o 0 */
    printf("\nI valori contenuti nel nuovo vettore (no duplicati e/o 0) sono: \n");
    printf("\tValori: --> ");
    for (int i = 0; i < cont - 1; i++)
        printf("%d, ", arrayNoDuplicatiPt2[i]);
    printf("%d <--\n", arrayNoDuplicatiPt2[cont - 1]);

    // Comando che invita l'utente a premere il tasto "invio" per chiudere il programma.
    printf("\n\n\nPremi invio per chiudere il terminale...");
    getchar();
    return 0;

}