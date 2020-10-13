/**HEADER********************************************************************
 *  AUTORI: Lorenzo Gessi, Andrea Bedei, Fabio Notaro e Luca Venturi.
 *  EMAIL:  lorenzo.gessi@studio.unibo.it, andrea.bedei2@studio.unibo.it, fabio.notaro2@studio.unibo.it, luca.venturi29@studio.unibo.it
 *  DATA:   2020/10/09
 *  ES n.1: Scrivere un programma C che mostri l�utilizzo di tutti gli operatori studiati.
            Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi non appropriati alla dimensione delle variabili,
            quello che si ottiene usando pi� operatori con side effects all�interno della stessa istruzione,
            quello che si ottiene quando le regole di conversione implicita sono applicate e
            quando si supera il range dei valori disponibili per un tipo di dato.
            Il programma deve poi mostrare l�utilizzo di tutte le funzioni matematiche della libreria math.h.
***END************************************************************************/

/* Inclusione delle librerie */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Dichiarazione variabili.
    int a,b,c, bool1;
    float fl;
    char ch;
    double d;

    // Operatore assegnamento.
    printf("OPERATORE \t ESEMPIO \t\t FUNZIONE\n");
    printf("\nOPERATORE ASSEGNAMENTO\n");
    a=8;
    b=4;
    c=2;
    printf("=\t\t a=8; \t\t\t Assegna il valore 8 alla variabile a\n\n");

    // Operatori composti.
    printf("OPERATORI COMPOSTI\n");
    a+=2;
    printf("+=\t\t a+=2; \t\t\t Assegna il risultato di a+2 alla variabile a\n");
    a-=2;
    printf("-=\t\t a-=2; \t\t\t Assegna il risultato di a-2 alla variabile a\n");
    a*=2;
    printf("*=\t\t a*=2; \t\t\t Assegna il risultato di a*2 alla variabile a\n");
    b/=2;
    printf("/=\t\t b/=2; \t\t\t Assegna il risultato di b/2 alla variabile b\n");
    b%=2;
    printf("%%=\t\t b%%=2; \t\t\t Assegna il risultato di b%%2 alla variabile b\n\n");

    // Operatore virgola.
    printf("OPERATORE VIRGOLA\n");
    a=(b++, c);
    printf(",\t\t a=(b++, c++); \t\t Incrementa b, assegna ad a il valore di c e poi incrementa c\n\n");

    // Operatori aritmetici
    printf("OPERATORI ARITMETICI\n");
    a=a+2;
    printf("+\t\t a=a+2; \t\t Assegna il risultato di a+2 alla variabile a\n");
    a=a-2;
    printf("-\t\t a=a-2; \t\t Assegna il risultato di a-2 alla variabile a\n");
    a=a*2;
    printf("*\t\t a=a*2; \t\t Assegna il risultato di a*2 alla variabile a\n");
    b=b/2;
    printf("/\t\t b=b/2; \t\t Assegna il risultato di b/2 alla variabile b\n");
    b=b%2;
    printf("%%\t\t b=b%%2; \t\t Assegna il risultato di b%%2 alla variabile b\n\n");

    // Operatori di incremento e decremento.
    printf("OPERATORI DI INCREMENTO E DECREMENTO\n");

    // Prefissi.
    ++a;
    printf("++\t\t ++a; \t\t\t Incrementa di uno il valore di a e lo restituisce\n");
    --b;
    printf("--\t\t --b; \t\t\t Decrementa di uno il valore di b e lo restituisce\n");

    // Postfissi.
    a++;
    printf("++\t\t a++; \t\t\t Restituisce il valore di a e poi lo incrementa di uno\n");
    b--;
    printf("--\t\t --b; \t\t\t Restituisce il valore di b e poi lo decrementa di uno\n\n");

    // Operatori relazionali.
    printf("OPERATORI RELAZIONALI\n");
    bool1=a<b;
    printf("<\t\t a<b; \t\t\t Restituisce vero(1) se a<b, altrimenti falso(0)\n");
    bool1=a>b;
    printf(">\t\t a>b; \t\t\t Restituisce vero(1) se a>b, altrimenti falso(0)\n");
    bool1=a<=b;
    printf("<=\t\t a<=b; \t\t\t Restituisce vero(1) se a<=b, altrimenti falso(0)\n");
    bool1=a>=b;
    printf(">=\t\t a>=b; \t\t\t Restituisce vero(1) se a>=b, altrimenti falso(0)\n");
    bool1=a==b;
    printf("==\t\t a==b; \t\t\t Restituisce vero(1) se a==b, altrimenti falso(0)\n");
    bool1=a!=b;
    printf("!=\t\t a!=b; \t\t\t Restituisce vero(1) se a!=b, altrimenti falso(0)\n\n");

    //Operatori logici.
    // A questo punto dell'esecuzione a=32, b=-2, c=2.
    printf("OPERATORI LOGICI\n");
    bool1=!bool1;
    printf("!\t\t !(cond); \t\t Calcola il NOT logico della condizione\n");
    bool1=(a>b)&&(b<c);
    printf("&&\t\t cond1&&cond2\t\t Calcola l'AND logico tra le due condizioni\n");
    bool1=(a>b)||(b<c);
    printf("||\t\t cond1||cond2\t\t Calcola l'OR logico tra le due condizioni\n\n");

    // Operatori speciali.
    printf("OPERATORI SPECIALI\n");
    // sizeof().
    b= sizeof(a);
    printf("sizeof() \t b=sizeof(a);\t\t Restituisce la quantita' di memoria richiesta per memorizzare la variabile\n");
    // Casting.
    ch='a';
    b=(int)ch;
    printf("(tipo)espr \t b=(int)ch; \t\t Conversione esplicita della variabile char in intero\n\n");

    // Operatore ternario.
    printf("OPERATORE TERNARIO\n");
    a=(b>a)?b:a;
    printf("exp1?exp2:exp3; a=(b>a)?b:a;\t\t Restituisce exp2 se expr1 e' vera, altrimenti restituisce exp3\n\n");

    // Operatori bitwise.
    a=10;
    b=5;
    c=2;
    printf("OPERATORI BITWISE\n");
    c=a&b;
    printf("&\t\t a&b; \t\t\t Esegue l'AND logico bit a bit\n");
    c=a|b;
    printf("|\t\t a|b; \t\t\t Esegue l'OR logico bit a bit\n");
    c=a^b;
    printf("^\t\t a^b; \t\t\t Esegue l'OR esclusivo bit a bit\n");
    c=~c;
    printf("~\t\t a~b; \t\t\t Complemento a 1\n");
    c=a>>3;
    printf(">>\t\t a>>b; \t\t\t Shift a destra il primo operando per un numero di bit pari al secondo\n");
    c=b<<2;
    printf("<<\t\t a<<b; \t\t\t Shift a sinistra il primo operando per un numero di bit pari al secondo\n\n");

    // Tipi non appropriati alla dimensione delle variabili.
    a=12345678987654321;
    fl=100000000000000000.12f;
    // Overflow.
    printf("TIPI NON APPROPRIATI ALLA DIMENSIONE DELLE VARIABILI\nOVERFLOW\n");
    printf("a=12345678987654321 --> overflow --> comportamento non definito --> valore stampato=%d\n", a);
    printf("fl=100000000000000000.12 --> overflow --> comportamento non definito --> valore stampato=%f\n\n", fl);

    // Underflow.
    a=-12345678987654321;
    fl=-100000000000000000.12f;
    printf("UNDERFLOW\n");
    printf("a=-12345678987654321 --> underflow --> comportamento non definito --> valore stampato=%d\n", a);
    printf("fl=-100000000000000000.12 --> underflow --> comportamento non definito --> valore stampato=%f\n\n", fl);

    // Side effects.
    printf("UTILIZZO DI OPERATORI CON SIDE EFFECTS NELLA STESSA ISTRUZIONE\n");
    a=1;
    a=a++;
    printf("a=a++; --> non definito per conflitto tra = e ++ --> in questo caso a=%d --> ma il valore potrebbe cambiare\n", a);
    printf("Soluzione: l'assegnamento e' implicito --> occorre una singola istruzione --> a++;\n", a);

    a=(b++)+c;
    printf("a=(b++)+c; --> non definito per conflitto tra + e ++ --> in questo caso a=%d --> ma il valore potrebbe cambiare\n", a);
    printf("Soluzione: occorre separare le due istruzioni --> b++; --> a=b+c;\n\n", a);

    // Conversione implicita.
    printf("APPLICAZIONE DELLE REGOLE DI CONVERSIONE IMPLICITA\nOrdine di grandezza dei tipi: char < int < float < double\n");
    fl=10.3f;
    ch='a';
    a=10;
    d=10.3456;
    a=ch;
    printf("int=char --> carattere convertito in intero --> a=10 --> a=%d\n", a);
    fl=a;
    printf("float=intero --> intero convertito in float --> fl=10.3 --> fl=%f\n", fl);
    d=fl;
    printf("double=float --> float convertito in double --> d=10.3456 --> d=%g\n", d);
    d=a;
    printf("double=int --> int convertito in double --> d=10.3 --> d=%g\n", d);
    b=10;
    a=3;
    fl=b/a;
    printf("float fl=10/3 --> divisione fra interi --> risultato intero --> fl=%f\n", fl);
    fl=(float)b/a;
    printf("float fl=(float)10/3 --> divisione fra un float e un intero --> risultato float --> fl=%f\n", fl);
    fl=b/3.0;
    printf("float fl=10/3.0 --> divisione fra un intero e un float --> risultato float --> fl=%f\n\n", fl);

    // Superamento del range dei valori disponibili per un tipo di dato.
    printf("SUPERAMENTO DEL RANGE DISPONIBILE PER UN TIPO DI DATO\n");
    a=10.10;
    printf("int a=10.10 --> perdita parte razionale --> a=%d\n", a);
    ch=10000;
    printf("char ch=10000 --> valore fuori range --> ch=%c --> risultato indefinito\n", ch);
    fl=1.0e100;
    printf("float fl=1.0e100 --> valore fuori range --> fl=%f --> risultato indefinito\n\n", fl);

    // Utilizzo delle funzione della libreria math.h.
    printf("LIBRERIA MATH.H\n");
    int x=-1;
    double y;
    printf("FUNZIONE \t ESEMPIO \t\t\tDESCRIZIONE\n");
    x=fabs(x);
    printf("fabs() \t\t fabs(x)=%d \t\t\tValore assoluto della variabile\n", x);
    y=acos(x);
    printf("acos() \t\t acos(x)=%g \t\t\tArcocoseno della variabile\n", y);
    y=asin(x);
    printf("asin() \t\t asin(x)=%g \t\tArcoseno della variabile\n", y);
    y=atan(x);
    printf("atan() \t\t atan(x)=%g \t\tArcotangente della variabile\n", y);
    x=ceil(y);
    printf("ceil() \t\t ceil(x)=%d \t\t\tIl piu' piccolo intero maggiore della variabile\n", x);
    y=cos(x);
    printf("cos() \t\t cos(x)=%g \t\tCoseno della variabile\n", y);
    y=cosh(0);
    printf("cosh() \t\t cosh(x)=%g \t\t\tCoseno iperbolico della variabile\n", y);
    x=floor(y);
    printf("floor() \t floor(x)=%d \t\t\tIl piu' grande intero minore della variabile\n", x);
    y=log(x);
    printf("log() \t\t log(x)=%g \t\t\tLogaritmo naturale della variabile\n", y);
    y=log10(10);
    printf("log10() \t log10(x)=%g \t\t\tLogaritmo in base 10 della variabile\n", y);
    x=pow(y, 100);
    printf("pow() \t\t pow(x, y)=%d \t\t\tElevazaione di x a y\n", x);
    y=sin(0);
    printf("sin() \t\t sin(x)=%g \t\t\tSeno della variabile\n", y);
    y=sinh(0);
    printf("sinh() \t\t sinh(x)=%g \t\t\tSeno iperbolico della variabile\n", y);
    y=sqrt(4);
    printf("sqrt() \t\t sqrt(x)=%g \t\t\tRadice quadrata della variabile\n", y);
    y=tan(1);
    printf("tan() \t\t tan(x)=%g \t\tTangente della variabile\n", y);

    getchar();  // Nel caso di apertura dell'eseguibile blocca l'esecuzione attendendo un carattere, evitando la chiusura immediata.
    return 0;
}
