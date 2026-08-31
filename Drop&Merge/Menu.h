#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


typedef enum {
    SCELTA_ESCI = 0,
    SCELTA_NUOVA_PARTITA = 1,
    SCELTA_CLASSIFICA = 2,
    SCELTA_CARICA_PARTITA = 3
} SceltaMenu;


void mostraMenuGrafico(void);

int leggiSceltaMenu(void);

#endif // MENU_H_INCLUDED
