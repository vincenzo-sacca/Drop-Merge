#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#include "Classifica.h"
#include "Giocatori.h"

List classifica = NULL;

bool caricaClassifica(const char* filename) {
    classifica = createList();
    FILE *f = fopen(filename, "r");
    bool loaded = false;
    if (f != NULL) {
        Giocatore gCurr;
        while(fscanf(f, "%s%d", gCurr.nome, &gCurr.punteggio) != EOF)
            insert_sorted(classifica, gCurr);

        fclose(f);
        loaded = true;
    }
    else
        printf("ERRORE di apertura del file %s\n", filename);
    return loaded;

}

void aggiornaClassifica(const char* filename) {
    FILE *f = fopen(filename, "w");
    if (f != NULL) {
        rewindCursor(classifica);
        while(hasNextNode(classifica)) {
            Giocatore gCurr = nextNode(classifica)->player;
            fprintf(f, "%s %d\n", gCurr.nome, gCurr.punteggio);
        }
        fclose(f);
    }
}

int puntiGiocatore(const char* giocatore) {
    int punti = -1;

    Giocatore* found = find(classifica, giocatore);
    if (found != NULL)
        punti = found->punteggio;

    return punti;
}

void aggiungiPuntiAGiocatore(const char* giocatore, int punti) {
    Giocatore* found = find(classifica, giocatore);

    if (found != NULL) {
        found->punteggio = found->punteggio + punti;
        sort(classifica);
    }
    else {
        Giocatore newG;
        strcpy(newG.nome, giocatore);
        newG.punteggio = punti;
        insert_sorted(classifica, newG);
    }
}

void stampaClassifica() {
    printList(classifica);
}
