#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp4.c"
#include "tp4.h"



int main(){
    printf("NF16 - P024 - TP4 : Les Arbres Binaires de Recherche\n");
    printf("Laborie Leo - Playez Romain\n");
    T_Arbre arbre = NULL;
    bool continuer = true;
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
                arbre = appelCreerSommet(arbre);

                break;

            case 2: //Inserer N elements
                arbre = appelInsererNElement(arbre);

                break;

            case 3: //Rechercher un element
                appelRechercherElement(arbre);

                break;

            case 4: //Afficher tous les sommets
                appelAfficherSommets(arbre);

                break;

            case 5: //Afficher tous les elements
                appelAfficherElements(arbre);

                break;

            case 6: //Supprimer un element
                arbre = appelSupprimerElement(arbre);

                break;

            case 7: //Afficher la taille de la memoire
                appelTailleMemoire(arbre);

                break;

            case 8: //Quitter
                continuer = appelQuitter(arbre);
                break;

            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}
