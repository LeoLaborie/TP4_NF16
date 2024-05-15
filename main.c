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
                if(non_vide == false){
                    creer = false;
                    while (creer == false){
                        printf("Veuillez saisir l'element du sommet a creer\n");
                        scanf("%d", &element);
                        creer = validiteSommet(element);
                        if (creer == false){
                            printf("rentrez un sommet valide svp\n");
                        }
                    }
                    arbre = creerSommet(element);
                }else{
                    arbre = choixCreationArbre(arbre);
                }
                

                break;


            case 2: //Inserer N elements
                printf("Veuillez saisir le nombre d'elements a inserer\n");
                scanf("%d", &nombre_elements);
                inserer = validiteElements(nombre_elements);
                if (inserer == true){
                    int element;
                    for (int i = 0; i < nombre_elements; i++){
                        printf("rentrez un element a inserer\n");
                        scanf("%d", &element);
                        if (validiteElements(element)==true){
                            arbre = insererElement(arbre, element);
                        }
                        else{
                            printf("element non valide\n");
                            i--;
                        }

                    }
                }else{
                    printf("Vous ne pouvez construire un arbre qu'avec un nombre d'elements positif");
                }

                break;

            case 3: //Rechercher un element
                printf("Veuillez saisir l'element que vous souhaitez rechercher\n");
                scanf("%d", &element_recherche);
                non_vide = arbreNonVide(arbre);
                rechercher = validiteSommet(element_recherche);
                if(non_vide == true && rechercher == true){
                    T_Sommet *s;
                    s = rechercherElement(arbre, element_recherche);
                    if (s == NULL){
                        printf("L'élément %d n'a pas été trouvé dans l'arbre !", element_recherche);
                    }
                    else{
                        printf("L'élément %d a été trouvé dans l'arbre", element_recherche);
                    }
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 4: //Afficher tous les sommets
                non_vide = arbreNonVide(arbre);
                if(non_vide == true){
                    afficherSommets(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 5: //Afficher tous les elements
                non_vide = arbreNonVide(arbre);
                if(non_vide == true){
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
                if(non_vide == true && supprimer == true){
                    supprimerElement(arbre, element_suppression);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }
                break;

            case 7: //Afficher la taille de la memoire
                non_vide = arbreNonVide(arbre);
                if(non_vide == true){
                    tailleMemoire(arbre);
                }else{
                    printf("Veuillez dans un premier temps creer un arbre");
                }

                break;

            case 8: //Quitter
                non_vide = arbreNonVide(arbre);
                if(non_vide == true){
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

