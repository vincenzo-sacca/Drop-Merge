#ifndef CLASSIFICA_H_INCLUDED
#define CLASSIFICA_H_INCLUDED

#include<stdbool.h>

bool caricaClassifica(const char* filename);
void aggiornaClassifica(const char* filename);
int puntiGiocatore(const char* giocatore);
void aggiungiPuntiAGiocatore(const char* giocatore, int punti);
void stampaClassifica();

#endif // CLASSIFICA_H_INCLUDED
