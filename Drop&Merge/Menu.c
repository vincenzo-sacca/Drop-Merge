#include <stdio.h>
#include "Menu.h"


void mostraMenuGrafico(void) {
    printf("\n");
    printf("|=====================================|\n");
    printf("|         DROP & MERGE - 2048         |\n");
    printf("======================================|\n");
    printf("|                                     |\n");
    printf("|     [1] Nuova Partita               |\n");
    printf("|     [2] Visualizza Classifica       |\n");
    printf("|     [3] Carica Partita Precedente   |\n");
    printf("|     [0] Esci dal Gioco              |\n");
    printf("|                                     |\n");
    printf("|=====================================|\n");
    printf("Seleziona un'opzione: ");
}


int leggiSceltaMenu(void) {
    int scelta;

    do {
        mostraMenuGrafico();
        scanf("%d", &scelta);


        if (scelta < 0 || scelta > 3) {
            printf("\n>>> Opzione non valida! Inserisci un numero tra 0 e 3.\n");
        }
    } while (scelta < 0 || scelta > 3);

    return scelta;
}
