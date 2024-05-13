#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp4.c"
#include "tp4.h"



int main(){
    printf("NF16 - P024 - TP4 : Les Arbres Binaires de Recherche\n");
    printf("Laborie Leo - Playez Romain\n");
    bool continuer, creer, non_vide, rechercher, supprimer, inserer;
    continuer = true;
    T_Arbre arbre = NULL;
    int choix, element, nombre_elements, element_recherche, element_suppression;
    char choix_suppression;
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
                non_vide = arbreNonVide(arbre);
                if(non_vide == true){
                    printf("Veuillez saisir l'element du sommet a creer\n");
                    scanf("%d", &element);
                    creer = validiteSommet(element);
                    if (creer == true){
                        creerSommet(element);
                    }else{
                        printf("Un arbre existe deja, voulez vous le supprimer pour en creer un nouveau ? (Y/N)\n");
                        scanf("%c", &choix_suppression);
                        choixCreationArbre(arbre, choix_suppression);
                    }
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
                non_vide = arbreNonVide(arbre);
                rechercher = validiteSommet(element_recherche);
                if(non_vide == false && rechercher == true){
                    rechercherElement(arbre, element_recherche);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 4: //Afficher tous les sommets
                non_vide = arbreNonVide(arbre);
                if(non_vide == false){
                    afficherSommets(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 5: //Afficher tous les elements
                non_vide = arbreNonVide(arbre);
                if(non_vide == false){
                    afficherElements(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 6: //Supprimer un element
                printf("Veuillez saisir l'element que vous souhaitez supprimer\n");
                scanf("%d", &element_suppression);
                non_vide = arbreNonVide(arbre);
                supprimer = validiteSommet(element_recherche);
                if(non_vide == false && supprimer == true){
                    supprimerElement(arbre, element_suppression);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 7: //Afficher la taille de la memoire
                non_vide = arbreNonVide(arbre);
                if(non_vide == false){
                    tailleMemoire(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }

                break;

            case 8: //Quitter
                non_vide = arbreNonVide(arbre);
                if(non_vide == false){
                    libererMemoire(arbre);
                    continuer = false;
                }else{
                    continuer = false;
                }

                break;

            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}

