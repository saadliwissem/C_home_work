#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    liste l;

    init(&l);
     afficher(l);

    ajouter_debut(&l,10);
    afficher(l);

    ajouter_debut(&l,20);
    afficher(l);

    ajouter_fin(l,30);
    afficher(l);

    ajouter_position(&l,40,3);
    afficher(l);

    supprimer_position(&l,2);
    afficher(l);

    supprimer_fin(l);
    afficher(l);

    supprimer_debut(&l);
    afficher(l);

    return 0;
}
