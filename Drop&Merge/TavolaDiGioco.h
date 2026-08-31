#ifndef TAVOLADIGIOCO_H_INCLUDED
#define TAVOLADIGIOCO_H_INCLUDED

#include <stdbool.h>
#include "Constants.h"

void resetTavolaGioco(int tavola[][COLONNE]); //Imposta tutte le caselle a VUOTO

void stampaTavolaDiGioco(int tavola[][COLONNE]);

bool salvaTavolaSuFile(const char* filename, int tavola[][COLONNE], char nomeGiocatore[], int punteggio);

bool caricaTavolaDaFile(const char* filename, int tavola[][COLONNE], char nomeGiocatore[], int *punteggio);

#endif // TAVOLADIGIOCO_H_INCLUDED
