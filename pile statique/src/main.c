#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int main(){

    pile p = (pile) malloc(sizeof(pile));
    init(p);
    afficher(p);
    //ajouter valeur 20 a la pile
    push(p,20);
    afficher(p);

     //ajouter valeur 30 a la pile
    push(p,30);
    afficher(p);
//depiler
    pop(p);
    afficher(p);
    /*
    int a = 3;
    int *ptr;
    ptr = &a;
    printf("a= %d",a);
    printf("\n ptr= %d",ptr);
    printf("\n *ptr= %d",*ptr);
    */
}



