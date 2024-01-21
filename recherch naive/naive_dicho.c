#include <stdio.h>

int rech_Naive(int t[5],int n ,int val);
int rech_dicho(int t[5],int val, int deb,int fin);

int main() {

    int t[5] = {3,5,12,15,48};
    int values[4] = {3,12,48,4};
    int i;

    printf("Resultats avec la methode Recherche Naive : \n");
    for(i=0;i<4;i++){
        printf("pour la valeur %d le resultat est : ",values[i]);
        if(rech_Naive(t,5,values[i]))
            printf("True");
        else
            printf("False");
        printf("\n");

    }

     printf("\n");
     printf("\n");

    printf("Resultats avec la methode Recherche Dichotomique : \n");
    for(i=0;i<4;i++){
        printf("pour la valeur %d le resultat est : ",values[i]);
        if(rech_dicho(t,values[i],0,4) )
            printf("True");
        else
            printf("False");
        printf("\n");
    }

    return 0;
}


int rech_Naive(int t[10], int n , int val){
    int i=0;
    while(t[i] != val && i<n ){
        i++;
    }
    return i<n ;
}


int rech_dicho(int t[10],int val, int deb,int fin){
    if(deb>fin) return 0;

    int milieu = (deb + fin)  /2 ;

    if(t[milieu] == val )
        return 1;
    else{
        if(t[milieu] > val )
            return  rech_dicho(t,val, deb,milieu-1);

        else return rech_dicho(t,val, milieu+1,fin);
    }

}

