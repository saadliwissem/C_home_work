
#include <stdio.h>

//fonction factoriel
int factoriel(int num){
    int fact = 1;
    if(num == 0 ){
        return fact;
    }
    else{

    while (num>1){
        fact= fact*num;
        num--;
    }
        return fact ;
    }
}
//fonction valeur absolue
int absolu (int x){
if(x<0){
    return -x;
}
else{
    return x;
}
}

//fonction factoriel inverse

int inverseFactoriel(int y) {
    int x = absolu(y);
     if (x == 1) {
        return -1;
    }

    int n = 2;

    while (x > 1) {
        if (x % n != 0) {
            return -1;
        }
        x /= n;
        n++;
    }

    return n - 1;

}


int main() {
    int numbr;
    printf("écrire un entier");
    scanf("%d",&numbr);
    printf("%d",factoriel(numbr));
    printf("factorel inverse : %d",inverseFactoriel(numbr));
}
