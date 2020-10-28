/**HEADER********************************************************************
 *  AUTORI: Lorenzo Gessi, Andrea Bedei, Fabio Notaro e Luca Venturi.
 *  EMAIL:  lorenzo.gessi@studio.unibo.it, andrea.bedei2@studio.unibo.it, fabio.notaro2@studio.unibo.it, luca.venturi29@studio.unibo.it
 *  DATA:   2020/10/23
 *  ES n.1: Siano dati due vettori di interi di lunghezza differente i cui valori sono inseriti da tastiera.
            Scrivere un programma C che generi un terzo vettore contenente l’intersezione tra i due vettori di input.
            Se un elemento è comune ai due vettori e presente più volte in un vettore farlo comparire anche nel vettore risultato.
            Implementare la variante in cui le ripetizioni non sono presenti nel risultato.
            Implementare inoltre anche l'inserimento random dei valori nei vettori.
***END************************************************************************/

// Inclusione delle librerie.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // Per l'utilizzo del tipo bool.
#include <time.h>   // Per le generazione di numeri random.

// Macro che definiscono le dimensioni dei due vettori
#define DIMENSIONE 8
#define DIMENSIONE2 8

// Macro per definire il range dei valori generato casualmente.
#define MIN -20
#define MAX 20

int main()
{
    // Inizializzazione dei vettori.
    int vet1[DIMENSIONE]={0};
    int vet2[DIMENSIONE2]={0};
    int vetRis[DIMENSIONE*DIMENSIONE2]={0};

    int indiceRis=0;    // Variabile di controllo sull'indice del vettore.
    char risposta;  // Variabile contenente la risposta inserita dall'utente.
    int contB, contA;   // Contatori dei valori ripetuti comuni ad entrambi i vettori.
    int scostamento=0;  // Tiene il conto dell'offset dei valori del vettore senza e con ripetizioni.
    do
    {
        printf("INSERIMENTO VALORI RANDOM NEI DUE VETTORI?(y/n)");
        fflush(stdin);  //Pulizia del buffer di memoria dedicato all'input.
        risposta=getchar();
    }while((risposta!='y'&&risposta!='n')&&(risposta!='Y'&&risposta!='N'));

    // Se l'utente desidera l'inserimento random.
    if(risposta=='y'||risposta=='Y')
    {
        // Inizializzazione dei due vettori.
        for(int i=0;i<DIMENSIONE;i++)
            vet1[i]=MIN + (rand()+time(NULL))%(MAX+1-MIN);

        for(int i=0;i<DIMENSIONE2;i++)
            vet2[i]=MIN + (rand()+time(NULL))%(MAX+1-MIN);

        // Stampa dei due vettori appena generati casualmente.
        printf("vettore1={");
        for(int i=0;i<DIMENSIONE;i++)
        {
            // Controllo utile esclusivamente ad un formato di stampa migliore.
            if(i==DIMENSIONE-1)
                printf("%d", vet1[i]);
            else
                printf("%d, ", vet1[i]);
        }
        printf("};");
        printf("\nvettore2={");
        for(int i=0;i<DIMENSIONE2;i++)
        {
            // Controllo utile esclusivamente ad un formato di stampa migliore.
            if(i==DIMENSIONE2-1)
                printf("%d", vet2[i]);
            else
                printf("%d, ", vet2[i]);
        }
        printf("};");
    }
    else    // Se l'utente vuole inserire manualmente tutti i valori dei due vettori.
    {
        // Inserimento primo vettore.
        printf("INSERIMENTO DATI PRIMO VETTORE (LUNGHEZZA %d): \n", DIMENSIONE);
        for(int i=0;i<DIMENSIONE;i++)
        {
            printf("Inserire l'elemento %d: ", i );
            scanf("%d", &vet1[i]);
            fflush(stdin);
        }

        // Inserimento secondo vettore.
        printf("\nINSERIMENTO DATI SECONDO VETTORE (LUNGHEZZA %d): \n", DIMENSIONE2);
        for(int i=0;i<DIMENSIONE2;i++)
        {
            printf("Inserire l'elemento %d: ", i );
            scanf("%d", &vet2[i]);
            fflush(stdin);
        }
    }

    // Creazione del vettore risultato senza ripetizioni.
    for(int i=0;i<DIMENSIONE;i++)
    {
        for(int j=0;j<DIMENSIONE2;j++)
        {
            // Tramite questo controllo si evita la ripetizione dei valori.
            if(vet1[i]==vet2[j])
            {
                bool presente=false;
                for(int k=0; k<indiceRis;k++)
                {
                    if(vet1[i]==vetRis[k])
                    {
                        // Valore già presente.
                        presente=true;
                        break;
                    }
                }
                if(!presente)
                {
                    // Se il valore non è presente, lo inserisce.
                    vetRis[indiceRis]=vet1[i];
                    indiceRis++;
                }
            }
        }
    }

    // Stampa del vettore senza ripetizioni.
    printf("\n\nVETTORE INTERSEZIONE SENZA RIPETIZIONI: \n");
    printf("vettore={");
    for(int i=0;i<indiceRis;i++)
    {
        if(i==indiceRis-1)
            printf("%d", vetRis[i]);
        else
            printf("%d, ", vetRis[i]);
    }
    printf("};\n");

    // Creazione vettore con ripetizioni tramite conteggio dei valori ripetuti di entrambi i vettori.
    for(int i=0; i<indiceRis;i++)   // Lettura di tutti i valori del vettore risultato.
    {
        contA=0;
        contB=0;
        for(int j=0; j<DIMENSIONE;j++)
        {
            // Aumento il contatore ogni volta che è presente anche nel primo vettore l'elemento considerato nel vettore risultato.
            if(vetRis[i]==vet1[j])
                contA++;
        }
        for(int k=0; k<DIMENSIONE2;k++)
        {
            // Aumento il contatore ogni volta che è presente anche nel secondo vettore l'elemento considerato nel vettore risultato.
            if(vetRis[i]==vet2[k])
                contB++;
        }

        // Considero il minore tra i due conteggi per definire quante volte si dovrnno aggiungere i valori ripetuti nel vettore risultato.
        int ripetizioni=contA<contB ? contA : contB;

        // Aggiungo tante volte il valore ripetuto tante volte quante sono le ripetizioni meno 1 (il valore che è già stato inserito senza ripetizioni).
        for(int x=0;x<ripetizioni-1;x++)
        {
            vetRis[indiceRis+scostamento]=vetRis[i];    // L'elemento ripetuto va inserito nell'indice successivo (dato dallo scostamento).
            scostamento++;
        }
    }

    // Stampa del vettore con ripetizioni.
    printf("\nVETTORE INTERSEZIONE CON RIPETIZIONI: \n");
    printf("vettore={");
    for(int i=0;i<indiceRis+scostamento;i++)
    {
        if(i==indiceRis+scostamento-1)
            printf("%d", vetRis[i]);
        else
            printf("%d, ", vetRis[i]);
    }
    printf("};");

    getchar();  // Attendo l'inserimento di un carattere per evitare la chiusura istantanea dell'eseguibile.
    return 0;
}
