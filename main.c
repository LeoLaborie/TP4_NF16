#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp4.h"


int main(){
    printf("NF16 - P024 - TP4 : Les Arbres Binaires de Recherche\n");
    printf("Laborie Leo - Playez Romain\n");
    bool continuer, creer, vide, rechercher, supprimer, inserer;
    continuer = true;
    T_Arbre arbre;
    arbre = NULL;
    int choix, element, nombre_elements, element_recherche, element_suppression;

    while (continuer==true){

        printf("\n------------------------------------------------\n");
        printf("1. Creer un sommet");
        printf("2. Inserer N elements\n");
        printf("3. Rechercher un element\n");
        printf("4. Afficher tous les sommets\n");
        printf("5. Afficher tous les elements\n");
        printf("6. Supprimer un element\n");
        printf("7. Afficher la taille de la memoire\n");
        printf("8. Quitter\n");
        printf("\n------------------------------------------------\n");

        scanf("%d", &choix);

        switch(choix){
            case 1: //Creer un sommet
                printf("Veuillez saisir l'element du sommet a creer\n");
                scanf("%d", &element);
                creer = validiteSommet(element);
                if (creer == true){
                    creerSommet(element);
                }else{
                    printf("Vous ne pouvez construire un sommet qu'avec un element corresppondant a un nombre entier");
                }
                break;

            case 2: //Inserer N elements
                printf("Veuillez saisir le nombre d'elements a inserer\n");
                scanf("%d", &nombre_elements);
                inserer = validiteElements(nombre_elements);

                if (inserer == true){
                    insererElement(arbre, nombre_elements);
                }else{
                    printf("Vous ne pouvez construire un arbre qu'avec un nombre d'elements positif");
                }

                break;

            case 3: //Rechercher un element
                printf("Veuillez saisir l'element que vous souhaitez rechercher\n");
                scanf("%d", &element_recherche);
                vide = arbreNonVide(arbre);
                rechercher = validiteSommet(element_recherche);
                if(vide == false && rechercher == true){
                    rechercherElement(arbre, element_recherche);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;
            case 4: //Afficher tous les sommets
                vide = arbreNonVide(arbre);
                if(vide == false){
                    afficherSommets(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 5: //Afficher tous les elements
                vide = arbreNonVide(arbre);
                if(vide == false){
                    afficherElements(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;
            case 6: //Supprimer un element
                printf("Veuillez saisir l'element que vous souhaitez supprimer\n");
                scanf("%d", &element_suppression);
                vide = arbreNonVide(arbre);
                supprimer = validiteSommet(element_recherche);
                if(vide == false && supprimer == true){
                    supprimerElement(arbre, element_suppression);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 7: //Afficher la taille de la memoire

                break;

            case 8: //Quitter
                continuer = false;

                break;
            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}
