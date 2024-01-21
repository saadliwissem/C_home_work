
#include <stdio.h>
#include "pile.h"


void init (pile p){
    p->sp = 0;
}
int push (pile p,int elt){
    if(tester_pleine (p)){
        return 0;
    }

    p->data[p->sp++] = elt;
    return 1;

}
int pop(pile p){
    if(!tester_vide(p)){
          p->sp--;
          return 1;

    }
    return 0;
}

int tester_vide(pile p){
    return (p->sp ==0);
}
int tester_pleine(pile p){
    return (p->sp ==10);
}
int sommet(pile p){
    if(tester_vide(p)){
     printf("pile is vide \n");
     return -1;
    }
    return p->data[p->sp];
}

afficher(pile p){
    int i ;
    printf("sp = %d \n",p->sp);
     printf("data = [");
    for(i=0;i<p->sp;i++){
        printf(" %d ",p->data[i] );
        if(i!= p->sp-1){
            printf(",");
        }
    }
     printf("]");

        printf("\n");
        printf("\n");
}
