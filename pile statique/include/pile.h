#include <stdio.h>
#include <stdlib.h>

#define Max_Sise 10

typedef struct stack{
    int data[Max_Sise];
    unsigned int sp;
} *pile;

void init (pile p);
int push (pile p,int elt);
int pop(pile p);
int tester_vide(pile p);
int tester_pleine(pile p);
int sommet(pile p);
afficher(pile p);
