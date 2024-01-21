#include <stdio.h>
#include <stdbool.h>

typedef int tab[100];

void tri(tab t, int n);
void remplir(tab t, int n);
void saisir(int *n);
void afficher(tab t, int n);
void saisir_val_rech(int *x);
int rech_dicho(tab t,int val, int deb,int fin);
int rech_dicho_iterative(tab t,int n, int val);

int main() {

    int n;
    int x;
    tab t;
    int result_rech;

    saisir(&n);
    remplir(t, n);
    afficher(t, n);
    printf("\n tri du tableau :\n");
    tri(t,n);
    afficher(t, n);

    do{
        saisir_val_rech(&x);
        //result_rech = rech_dicho(t,x, 0 , n-1 );
        result_rech = rech_dicho_iterative(t,n,x);
        if(result_rech!=-1)
            printf("%d rechercher est se trouve a la position %d",x, result_rech  );
        else
            printf("%d n'existe pas dans le tableau",x, result_rech  );
    }while(true);

    return 0;
}

void saisir(int *n) {
    int reading;
    do {
        printf("N = ");
        reading = scanf("%d", n);

        if (reading == 1) {
            if (*n < 0) {
                printf("\n Le nombre doit être positif !\n");
            }
        } else {
            printf("Merci d'entrer un nombre (n'est pas des lettres).\n");
            // Vider le tampon d'entrée en cas d'échec de scanf
            getchar();
        }
    } while (!reading || *n < 0);
}

void saisir_val_rech(int *x) {
    printf("\n");
    int reading;
    do {
        printf("X = ");
        reading = scanf("%d", x);

        if (!reading) {
            printf("Merci d'entrer un nombre (n'est pas des lettres).\n");
            // Vider le tampon d'entrée en cas d'échec de scanf
            getchar();
        }
    } while (!reading);
    printf("\n");
}

void remplir(tab t, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int reading;
        do {
            printf("\n T[%d] = ", i);
            reading = scanf("%d", &t[i]);
            if (!reading) {
                printf("\n Verifier votre saisie !\n");
            }
            // Vider le tampon d'entrée en cas d'échec de scanf
            getchar();
        } while (!reading);
    }
}

void afficher(tab t, int n) {
    int i;
     printf("\n");
    for (i = 0; i < n; i++) {
        printf("| %d ", t[i]);
    }
    printf("\n");
}

void tri(tab t, int n) {
    // tri a bulle asc
     int aux;
      int permut;
      int i ;
    do{
        permut = 0;
        for (i = 0; i < n-1; i++) {
            if(t[i] >t[i+1]){
                aux = t[i];
                t[i] = t[i+1];
                t[i+1] = aux;
                permut = 1;
            }
        }
        n-- ;
    }while( permut || n>1 );
}

int rech_dicho(tab t,int val, int deb,int fin){
    //la fonction retourne la position du valeur a cherche "x" s'il existe sinon -1
    if(deb>fin) return -1;

    int milieu = (deb + fin)  /2 ;

    if(t[milieu] == val )
        return milieu;
    else{
        if(t[milieu] > val )
            return  rech_dicho(t,val, deb,milieu-1);

        else return rech_dicho(t,val, milieu+1,fin);
    }

}

int rech_dicho_iterative(tab t, int n , int val){
    int deb = 0;
    int fin = n-1;
    int milieu ;

    do{
            milieu = (deb + fin)  /2 ;

        if(val < t[milieu] )
            fin = milieu -1;
        else
            if(val > t[milieu] )
              deb = milieu +1 ;

    }while( t[milieu]!=val && deb<=fin );

    if(deb>fin) return -1 ;
    else return milieu;
}
