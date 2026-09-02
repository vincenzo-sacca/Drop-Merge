#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constants.h"
#include "Classifica.h"
#include "TavolaDiGioco.h"
#include "Partita.h"
#include "Giocatori.h"
#include "Menu.h"
int main() {
    int scelta;
    int tavola[RIGHE][COLONNE];
    int punteggio;
    bool game=true;
    bool controlloTavolaCaricata=false;
    char nomeGiocatore[DIM_GIOC];
    char partitaSalvata[DIM_GIOC];
    while(game){
        scelta=leggiSceltaMenu();
        switch(scelta){
        case SCELTA_ESCI:
            game=false;
            break;

        case SCELTA_NUOVA_PARTITA:
            printf("\nInserisci il tuo nome --> ");
            scanf("%s", nomeGiocatore);
            resetTavolaGioco(tavola);
            punteggio=0;
            giocaPartita(tavola,&punteggio,nomeGiocatore);
            caricaClassifica(FILENAME_CLASSIFICA);
            aggiungiPuntiAGiocatore(nomeGiocatore, punteggio);
            aggiornaClassifica(FILENAME_CLASSIFICA);
            break;
        case SCELTA_CLASSIFICA:
            caricaClassifica(FILENAME_CLASSIFICA);
            stampaClassifica();
            break;
        case SCELTA_CARICA_PARTITA:
            printf("\nInserire il nome dela partita salvata --> ");
            scanf("%s", &partitaSalvata);

            controlloTavolaCaricata = caricaTavolaDaFile(partitaSalvata, tavola, nomeGiocatore, &punteggio);
            if(!controlloTavolaCaricata){
                printf("\nPartita non trovata!");
            }
            else{
                giocaPartita(tavola,&punteggio,nomeGiocatore);
                caricaClassifica(FILENAME_CLASSIFICA);
                aggiungiPuntiAGiocatore(nomeGiocatore, punteggio);
                aggiornaClassifica(FILENAME_CLASSIFICA);
            }
            break;
        }
    }

}
