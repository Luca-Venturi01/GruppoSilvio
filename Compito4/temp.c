    // Controllo il numero di elementi che l'utente vuole inserire nel vettore.
    while(!inputCheck){

        printf("Quanti elementi vuoi inserire all'interno del vettore? ");
        scanfReturn = scanf("%d", &nVals);
        fflush(stdin);

        if (nVals > 1 && scanfReturn == 1)
            inputCheck = true;
        else
            printf("Inserire un valore valido, per favore.\n");
    }