/*

    AUTORI: ----
    EMAIL:  ----
    DATA:   20201001
    ES:     Scrivere un programma C che dichiari una variabile per ogni tipo studiato (usando anche i qualificatori
            short, long, signed e unsigned), ne stampi il valore e l’occupazione di memoria in byte. Utilizzare TUTTI
            gli argomenti della funzione printf() studiati e TUTTE le diverse varianti (modificatore, campoMinimo, precisione,
            modificatoreLunghezza). Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che
            quest’ultima ha stampato. Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato.

*/

/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#ifndef M_PI
       #define M_PI 3.14159265358979323846
#endif

int main()
{
    /* Dichiriazione di una variabile per ogni tipo studiato */
    // Carattere
    char char0 = 'S';
    unsigned char charUC = 'I';
    signed char charSC = 'L';

    // Interi
    unsigned int intU = 1;
    unsigned short int intUSI = 2;
    unsigned long int intULI = 3;
    signed int intSI = -4;
    signed short int intSSI = -5;
    signed long int intSLI = -6;

    // Virgola Mobile
    float float0 = 7.111f;                 // Singola Precisione
    double double0 = 8.222222;             // Doppia Precisione
    long double doubleLD = 9.333333333;    // Doppia Precisione Estesa

    // Variabile utilizzata per "testare" gli argomenti della printf()
    double pi = M_PI;

    /* Stampa dei valori assegnati alle variabili e relativa occupazione di memoria in byte */
    // Caratteri
    printf("Stampa dei valori assegnati alle variabili CHAR: \n");
    printf("\tChar:\t\t%c\t\t Peso: %dB\n", char0, sizeof(char0));
    printf("\tChar Unsigned:\t%c\t\t Peso: %dB\n", charUC, sizeof(charUC));
    printf("\tChar Signed:\t%c\t\t Peso: %dB\n", charSC, sizeof(charSC));

    // Interi
    printf("\nStampa dei valori assegnati alle variabili INT: \n");
    printf("\tInt Unsigned:\t\t %d\t Peso: %dB\n", intU, sizeof(intU));
    printf("\tInt Unsigned Short:\t %d\t Peso: %dB\n", intUSI, sizeof(intUSI));
    printf("\tInt Unsigned Long:\t %d\t Peso: %dB\n", intULI, sizeof(intULI));
    printf("\tInt Signed:\t\t%d\t Peso: %dB\n", intSI, sizeof(intSI));
    printf("\tInt Signed Short:\t%d\t Peso: %dB\n", intSSI, sizeof(intSSI));
    printf("\tInt Signed Long:\t%d\t Peso: %dB\n", intSLI, sizeof(intSLI));

    // Virgola Mobile
    printf("\nStampa dei valori assegnati alle variabili FLOAT e DOUBLE: \n");
    printf("\tFloat:\t\t%g\t\t Peso: %dB\n", float0, sizeof(float0));
    printf("\tDouble:\t\t%g\t\t Peso: %dB\n", double0, sizeof(double0));
    __mingw_printf("\tDouble Long:\t%Lf\t Peso: %dB\n", doubleLD, sizeof(doubleLD)); //Abbiamo usato __mingw_printf()
                                                                                     // Perche double long da errori
    /* Esempi di utilizzo degli argomenti della funzione printf() */
    printf("\nEsempi di utilizzo degli argomenti della funzione printf(): \n");
    printf("\t|%-10c|\n", char0);
    printf("\t|%+10d|\n", intU);
    printf("\t|%10c|\n", char0);
    printf("\t|%010d|\n", intU);
    printf("\t|%-10.10g|\n", pi);
    printf("\t|%+10.15g|\n", pi);
    printf("\t|% 10.8g|\n", pi);
    printf("\t|%013.10g|\n", pi);
    printf("\t|% 5.3hd|\n", intUSI);
    __mingw_printf("\t|%+13.8Lf|\t\n", doubleLD);
    printf("\t|%-15.4ld|\n", intULI);

    /* Stampa numero caratteri printf(): */
    printf("\nStampa numero caratteri printf(): \n");

    int cont = printf("\t\'Lorenzo, Andrea, Fabio e Luca!\'");
    printf("\t--> \t%d caratteri\n", cont);

    cont = printf("\t\'Gessi, Bedei, Notaro e Venturi!\'");
    printf("\t--> \t%d caratteri\n", cont);

    /* Stampa il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato */
    printf("\nStampa il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato: \n");
    printf("\t\t\t\t\tMAX\t\t\tMIN\n");
    printf("        ----------------------------------------------------------------------");

    // Carattere
    printf("\n\tChar: \t\t\t\t%d\t\t\t%d", CHAR_MAX, CHAR_MIN);
    printf("\n\tChar Unsigned: \t\t\t%d\t\t\t0", UCHAR_MAX);
    printf("\n\tChar Signed: \t\t\t%d\t\t\t%d", SCHAR_MAX, SCHAR_MIN);

    // Interi
    printf("\n\tInt Unsigned: \t\t\t%d\t\t\t0", UINT_MAX);
    printf("\n\tInt Unsigned Short: \t\t%d\t\t\t0", USHRT_MAX);
    printf("\n\tInt Unsigned Long: \t\t%lu\t\t\t0", ULONG_MAX);
    printf("\n\tInt Signed: \t\t\t%d\t\t%d", INT_MAX,INT_MIN);
    printf("\n\tInt Signed Short: \t\t%d\t\t\t%d", SHRT_MAX,SHRT_MIN);
    printf("\n\tInt Signed Long: \t\t%ld\t\t%ld", LONG_MAX,LONG_MIN);

    // Virgola Mobile
    printf("\n\tFloat: \t\t\t\t%e\t\t%e", FLT_MAX,FLT_MIN);
    printf("\n\tDouble: \t\t\t%e\t\t%e", DBL_MAX, DBL_MIN);
    __mingw_printf("\n\tDouble Long: \t\t\t%Le\t\t%Le\n", LDBL_MAX, LDBL_MIN);
    printf("        ----------------------------------------------------------------------\n\n");

    system("PAUSE"); // pone in attesa il processo corrente, finchè non viene ricevuto un segnale

    return 0;
}
