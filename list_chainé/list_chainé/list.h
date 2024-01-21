#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} elem;


typedef struct liste {
    elem *first;
}liste;

/*
pas de necisseté
void init(liste *lst);
*/

void init(liste *l);

int sizeList(liste l);

int ajouter_debut(liste *l,int x);

int ajouter_fin(liste l, int x);

int ajouter_position (liste *l, int x , int p);
//int supprimer_debut (liste *l)
//int supprimer_fin (liste l)
//int supprimer_position (liste l,int p)

void afficher(liste l);
