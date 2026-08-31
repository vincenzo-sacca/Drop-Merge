#include "Giocatori.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


List createList(void) {
    List l = (List)malloc(sizeof(struct list));
    if (l != NULL) {
        l->head = NULL;
        l->cursor = NULL;
    }
    return l;
}


void insertFirst(List l, Giocatore data) {
    if (l == NULL) return;

    Node n = (Node)malloc(sizeof(struct node));
    if (n != NULL) {
        n->player = data;
        n->next = l->head;
        l->head = n;
    }
}


Giocatore deleteFirst(List l) {
    Giocatore oldHeadData = {"", 0};
    if (l == NULL || l->head == NULL) {
        return oldHeadData;
    }

    oldHeadData = l->head->player;
    Node oldHeadNext = l->head->next;

    free(l->head);
    l->head = oldHeadNext;

    return oldHeadData;
}


bool isEmpty(List l) {
    return (l == NULL || l->head == NULL);
}


int length(List l) {
    int len = 0;
    if (l == NULL) return 0;

    Node curr = l->head;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    return len;
}


Giocatore* find(List l, const char *nome) {
    if (l == NULL) return NULL;

    Node curr = l->head;
    bool trovato = false;

    while (!trovato && curr != NULL) {
        if (strcasecmp(curr->player.nome, nome) == 0)
            trovato = true;
        else
            curr = curr->next;
    }

    if (!trovato)
        return NULL;

    return &(curr->player);
}


bool insert_sorted(List l, Giocatore data) {
    bool inserted = false;

    if (l != NULL) {
        Node newNode = (Node)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->player = data;
            Node curr = l->head;
            Node prec = NULL;

            while (curr != NULL && data.punteggio < curr->player.punteggio) {
                prec = curr;
                curr = curr->next;
            }

            if (prec == NULL) {
                newNode->next = l->head;
                l->head = newNode;
            } else {
                prec->next = newNode;
                newNode->next = curr;
            }
            inserted = true;
        }
    }
    return inserted;
}


bool delete(List l, Giocatore data) {
    if (l == NULL || l->head == NULL) return false;

    Node prev = NULL;
    Node curr = l->head;
    bool trovato = false;

    while (!trovato && curr != NULL) {
        if (strcasecmp(curr->player.nome, data.nome) == 0)
            trovato = true;
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr != NULL) {
        if (curr == l->head) {
            deleteFirst(l);
        } else {
            prev->next = curr->next;
            free(curr);
        }
    }
    return trovato;
}


void printList(List l) {

    Node curr = l->head;

    while(curr != NULL) {

        printf("%s (%d)\n", curr->player.nome, curr->player.punteggio);

        curr = curr->next;
    }

}


bool hasNextNode(List l) {
    return (l != NULL && l->cursor != NULL);
}

Node nextNode(List l) {
    Node tempN = NULL;
    if (hasNextNode(l)) {
        tempN = l->cursor;
        l->cursor = l->cursor->next;
    }
    return tempN;
}

void rewindCursor(List l) {
    if (l != NULL) {
        l->cursor = l->head;
    }
}


void sort(List l) {
    if (l == NULL || l->head == NULL) return;

    char nomeTemp[DIM_GIOC];
    int punteggioTemp;

    rewindCursor(l);
    while (hasNextNode(l)) {
        Node gi = nextNode(l);
        Node gj = gi->next;
        while (gj != NULL) {
            if ((gj->player).punteggio > (gi->player).punteggio) {
                strcpy(nomeTemp, (gj->player).nome);
                punteggioTemp = (gj->player).punteggio;

                strcpy((gj->player).nome, (gi->player).nome);
                (gj->player).punteggio = (gi->player).punteggio;

                strcpy((gi->player).nome, nomeTemp);
                (gi->player).punteggio = punteggioTemp;
            }
            gj = gj->next;
        }
    }
}
