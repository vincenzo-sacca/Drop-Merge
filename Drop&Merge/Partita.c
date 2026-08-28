#include <stdio.h>
#include <stdlib.h>
#include "Partita.h"
#include "TavolaDiGioco.h"

void resetPartita(int tavola[RIGHE][COLONNE], int *punteggio) {
    resetTavolaGioco(tavola);
    if (punteggio != NULL) {
        *punteggio = 0;
    }
}

int generaNumeroCasuale(void) {
    int r = rand() % 100;
    if (r < 75) {
        return 2; //75% di probabilita'
    } else {
        return 4;//25% di probabilita'
    }
}

//controllo per la colonna scelta dall'utente
int isColonnaValida(int tavola[RIGHE][COLONNE], int colonna) {
    if (colonna < 0 || colonna >= COLONNE) {
        return 0;
    }
    if (tavola[0][colonna] != VUOTO) {
        return 0;
    }
    return 1;
}


static int applicaGravita(int tavola[RIGHE][COLONNE]) {
    int avvenutoSpostamento = 0;

    for (int j = 0; j < COLONNE; j++) {
        for (int i = RIGHE - 1; i > 0; i--) { //la fuznione parte ad analizzare dall'anglo in basso a sinistra
            if (tavola[i][j] == VUOTO) {
                for (int k = i - 1; k >= 0; k--) {
                    if (tavola[k][j] != VUOTO) {
                        tavola[i][j] = tavola[k][j];
                        tavola[k][j] = VUOTO;
                        avvenutoSpostamento = 1;
                        break;
                    }
                }
            }
        }
    }
    return avvenutoSpostamento;
}


static int controllaEFondi(int tavola[RIGHE][COLONNE], int *punteggio) {
    int avvenutaFusione = 0;


    for (int i = RIGHE - 1; i >= 0; i--) {
        for (int j = 0; j < COLONNE; j++) {
            if (tavola[i][j] != VUOTO) {

                //controllo se il blocco sotto contiene lo stesso numero
                if (i + 1 < RIGHE && tavola[i + 1][j] == tavola[i][j]) {
                    tavola[i + 1][j] = tavola[i + 1][j]*2;
                    *punteggio = *punteggio + tavola[i + 1][j];
                    tavola[i][j] = VUOTO;
                    avvenutaFusione = 1;
                }
                //controllo se il blocco a sinistra contiene lo stesso numero
                else if (j - 1 >= 0 && tavola[i][j - 1] == tavola[i][j]) {
                    tavola[i][j] = tavola[i][j]*2;
                    *punteggio = *punteggio + tavola[i][j];
                    tavola[i][j - 1] = VUOTO;
                    avvenutaFusione = 1;
                }
                //controllo se il blocco a destra contiene lo stesso numero
                else if (j + 1 < COLONNE && tavola[i][j + 1] == tavola[i][j]) {
                    tavola[i][j] = tavola[i][j]*2;
                    *punteggio = *punteggio + tavola[i][j];
                    tavola[i][j + 1] = VUOTO;
                    avvenutaFusione = 1;
                }
            }
        }
    }
    return avvenutaFusione;
}


void eseguiMossa(int tavola[RIGHE][COLONNE], int colonna, int valore, int *punteggio) {
    for (int i = RIGHE - 1; i >= 0; i--) {
        if (tavola[i][colonna] == VUOTO) {
            tavola[i][colonna] = valore;
            break;
        }
    }

    int continua = 1;
    while (continua) {
        int fuso = controllaEFondi(tavola, punteggio);
        int caduto = applicaGravita(tavola);
        if (!fuso && !caduto) {
            continua = 0;
        }
    }
}


int isGameOver(int tavola[RIGHE][COLONNE]) {
    for (int j = 0; j < COLONNE; j++) {
        if (tavola[0][j] == VUOTO) {
            return 0;
        }
    }
    return 1; //game over
}
