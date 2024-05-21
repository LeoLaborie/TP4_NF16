#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp4.c"
#include "tp4.h"



int main(){
    printf("NF16 - P024 - TP4 : Les Arbres Binaires de Recherche\n");
    printf("Laborie Leo - Playez Romain\n");
    bool continuer;
    int choix;

    while (continuer==true){

        printf("\n------------------------------------------------\n");
        printf("1. Creer un sommet\n");
        printf("2. Inserer N elements\n");
        printf("3. Rechercher un element\n");
        printf("4. Afficher tous les sommets\n");
        printf("5. Afficher tous les elements\n");
        printf("6. Supprimer un element\n");
        printf("7. Afficher la taille de la memoire\n");
        printf("8. Quitter");
        printf("\n------------------------------------------------\n");

        scanf("%d", &choix);

        switch(choix){

            case 1: //Creer un sommet
                appelCreerSommet();

                break;

            case 2: //Inserer N elements
                appelInsererElement();

                break;

            case 3: //Rechercher un element
                appelRechercherElement();

                break;

            case 4: //Afficher tous les sommets
                appelAfficherSommets();

                break;

            case 5: //Afficher tous les elements
                appelAfficherElements();

                break;

            case 6: //Supprimer un element
                appelSupprimerElement();

                break;

            case 7: //Afficher la taille de la memoire
                appelTailleMemoire();

                break;

            case 8: //Quitter
                appelQuitter();

                break;

            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}
