#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp4.h"


int main(){
    printf("NF16 - P024 - TP4 : Les Arbres Binaires de Recherche\n");
    printf("Laborie Leo - Playez Romain\n");
    bool continuer=true;
    int choix;

    while (continuer==true){

        printf("\n------------------------------------------------\n");
        printf("1. Inserer N elements\n");
        printf("2. Rechercher un element\n");
        printf("3. Afficher tous les sommets\n");
        printf("4. Afficher tous les elements\n");
        printf("5. Supprimer un element\n");
        printf("6. Afficher la taille de la memoire\n");
        printf("7. Quitter\n");
        printf("\n------------------------------------------------\n");

        scanf("%d", &choix);

        switch(choix){
            case 1: //Inserer N elements
                
                break;
            case 2: //Rechercher un element
                
                break;
            case 3: //Afficher tous les sommets
                        
                break;
            case 4: //Afficher tous les elements

                break;
            case 5: //Supprimer un element
                
                break;
            case 6: //Afficher la taille de la memoire
                
                break;

            case 7: //Quitter
                continuer = false;

                break;
            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}
