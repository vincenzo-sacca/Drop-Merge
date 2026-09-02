#ifndef PARTITA_H_INCLUDED
#define PARTITA_H_INCLUDED

#include "stdbool.h"
#include "Constants.h"

void resetPartita(int tavola[RIGHE][COLONNE], int *punteggio);

int generaNumeroCasuale(void);

int isColonnaValida(int tavola[RIGHE][COLONNE], int colonna);

void eseguiMossa(int tavola[RIGHE][COLONNE], int colonna, int valore, int *punteggio);

void giocaPartita(int tavola[][COLONNE],int *punteggio, char nomeGiocatore[]);

bool isGameOver(int tavola[RIGHE][COLONNE]);

#endif // PARTITA_H_INCLUDED
