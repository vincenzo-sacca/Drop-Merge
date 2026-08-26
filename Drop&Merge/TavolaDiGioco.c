#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Constants.h"
#include "TavolaDiGioco.h"

// Stampa la linea dritta che si trova sopra e sotto le caselle
void stampalinea(int dimensione) {
    int i;
    for (i = 0; i < dimensione * 6 + 1; i++) {
        printf("%c", (char)TRATTO);
    }
    printf("\n");
}


void resetTavolaGioco(int tavola[][COLONNE]) {
    int i, j;
    for (i = 0; i < RIGHE; i++) {
        for (j = 0; j < COLONNE; j++) {
            tavola[i][j] = VUOTO;
        }
    }
}

void stampaTavolaDiGioco(int tavola[][COLONNE]) {
    int i, j;
    printf("\n");
    // Stampa gli indicatori delle colonne (1, 2, 3, 4, 5)
    printf(" ");
    for (j = 0; j < COLONNE; j++) {
        printf("  [%d] ", j + 1);
    }
    printf("\n");

    for (i = 0; i < RIGHE; i++) {
        stampalinea(COLONNE);
        for (j = 0; j < COLONNE; j++) {
            if (tavola[i][j] == VUOTO) {
                printf("|     ");
            } else {
                // %4d lascia spazio a 4 caratteri,se il numero ha meno di 4 cifre inserisce spazi vuoti a sinistra
                printf("|%4d ", tavola[i][j]);
            }
        }
        printf("|\n");
    }
    stampalinea(COLONNE);
    printf("\n");
}


bool salvaTavolaSuFile(const char* filename, int tavola[][COLONNE]) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("ERRORE: Impossibile creare o aprire il file %s per il salvataggio.\n", filename);
        return false;
    }

    int i, j;
    for (i = 0; i < RIGHE; i++) {
        for (j = 0; j < COLONNE; j++) {
            fprintf(fp, "%d ", tavola[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return true;
}


bool caricaTavolaDaFile(const char* filename, int tavola[][COLONNE]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERRORE: File %s non trovato o non accessibile.\n", filename);
        return false;
    }

    int i, j;
    int valoreLetto;
    bool tavolaValida = true;

    for (i = 0; i < RIGHE && tavolaValida; i++) {
        for (j = 0; j < COLONNE && tavolaValida; j++) {
            if (fscanf(fp, "%d", &valoreLetto) != 1) { //se fscanf restituirà un valore diverso da 1 allora significa che ci sono elementi non letti correttamente
                tavolaValida = false;
            } else {
                tavola[i][j] = valoreLetto;
            }
        }
    }

    fclose(fp);

    if (!tavolaValida) {
        printf("ERRORE\n", filename, RIGHE, COLONNE);
        resetTavolaGioco(tavola);
        return false;
    }

    return true;
}
