#ifndef GIOCATORI_H_INCLUDED
#define GIOCATORI_H_INCLUDED

#include <stdbool.h>

#define DIM_GIOC 50

typedef struct giocatore{
    char nome[DIM_GIOC];
    int punteggio;
} Giocatore;

struct node {
    Giocatore player;
    struct node *next;
};
typedef struct node* Node;

struct list {
    Node head;
    Node cursor;
};
typedef struct list* List;


List createList(void);

void insertFirst(List l, Giocatore data);

Giocatore deleteFirst(List l);

bool isEmpty(List l);

int length(List l);

Giocatore* find(List l, const char *nome);

bool insert_sorted(List l, Giocatore data);

bool delete(List l, Giocatore data);

void printList(List l);

bool hasNextNode(List l);

Node nextNode(List l);

void rewindCursor(List l);

void sort(List l);

#endif // GIOCATORI_H_INCLUDED
