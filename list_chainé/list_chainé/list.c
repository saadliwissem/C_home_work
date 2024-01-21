#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int ajouter_debut (liste *l,int x)
{
    elem *temp = malloc(sizeof(elem));
    if (temp==NULL){
        return 0;
    }
    (*temp).data = x;
    (*temp).next = (*l).first;
    (*l).first = temp;
    return 1;

}

int sizeList(liste l){

     elem *tempc = l.first;
    int i =0;

    while (tempc!=NULL){
        tempc=(*tempc).next;
        i++;
    }

    return i;

}

int ajouter_fin (liste l, int x)
{
    elem *temp =malloc(sizeof(elem));
    (*temp).data=x;
    (*temp).next=NULL;
    if (temp==NULL){
        return 0;
    }
    elem *tempc = l.first;
    while ((*tempc).next!=NULL){
        tempc=(*tempc).next;
    }
    (*tempc).next= temp;
    return 1;
}


int ajouter_position (liste *l, int x , int p)
{

     if (p == 1){
        return ajouter_debut(l,x);
    }

    if( p==sizeList(*l) + 1 ){
        return ajouter_fin(*l,x);
    }

    if(p>sizeList(*l)){
      //  la positition depasse la taille des elements!
            return 0;
    }



    int k=1;
    elem *tempc=l->first;
    while((*tempc).next!=NULL && k<p-1){
        tempc=(*tempc).next;
        k++;
    }

    elem* temp =malloc(sizeof(elem));
    (*temp).data=x;
    (*temp).next=(*tempc).next;
    (*tempc).next=temp;

    if(temp == NULL){
        return 0;
    }
    return 1;
}

void init (liste* l)
{
    (*l).first=NULL;

}

int supprimer_debut(liste *l) {
    if (l->first == NULL) {
        return 0; // Empty list
    }

    elem *temp = l->first;
    l->first = temp->next;
    free(temp);

    return 1;
}

int supprimer_fin (liste l){

    elem *tempc = l.first;

    if (tempc->next == NULL) {
        free(tempc);
        l.first = NULL;
        return 1;
    }

    while (((*tempc).next)->next!=NULL){
        tempc=(*tempc).next;
    }

    free((*tempc).next);
    (*tempc).next= NULL;

    return 1;

}


int supprimer_position (liste *l , int p)
{
     if (p == 1){
        return supprimer_debut(l);
    }

    if(p==sizeList(*l)){
        return supprimer_fin(*l);
    }

    if(p>sizeList(*l)){
            // la positition depasse la taille des elements!

        return 0;
    }

    int k=1;
    elem *tempc=l->first;
    while((*tempc).next!=NULL && k<p-1){
        tempc=(tempc)->next;
        k++;
    }

    elem *tmp = tempc->next;

    tempc->next = tmp->next;

    free(tmp);
    return 1;
}


void afficher(liste l){
    printf("\n");
    printf("liste :[ ");

if(sizeList(l)>0){

 int i = 1;

    elem *temp = l.first;
 printf("p%d : %d ,",i,temp->data);

    while (temp->next!=NULL){

        i++;
          temp = temp->next;
       printf("p%d : %d ",i,temp->data);

       if(temp->next!=NULL )
        printf(",");

    }

}

    printf(" ]");
      printf("\n");




}


