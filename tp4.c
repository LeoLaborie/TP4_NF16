#include "tp4.h"
#include <stdlib.h>
#include <stdio.h>

void appelCreerSommet(){
    T_Arbre arbre = NULL;
    bool non_vide, creer;
    int element;
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
        choixCreationArbre(arbre);
    }
}

void appelInsererElement(){
    T_Arbre arbre;
    bool inserer;
    int nombre_elements;
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
}

void appelRechercherElement(){
    T_Arbre arbre;
    int element_recherche;
    bool non_vide, rechercher;
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
}

void appelAfficherSommets(){
    T_Arbre arbre;
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        afficherSommets(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
}

void appelAfficherElements(){
    T_Arbre arbre;
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        afficherElements(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
}

void appelSupprimerElement(){
    T_Arbre arbre;
    bool non_vide, supprimer;
    int element_suppression, element_recherche;
    printf("Veuillez saisir l'element que vous souhaitez supprimer\n");
    scanf("%d", &element_suppression);
    non_vide = arbreNonVide(arbre);
    supprimer = validiteSommet(element_recherche);
    if(non_vide == true && supprimer == true){
        supprimerElement(arbre, element_suppression);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
}

void appelTailleMemoire(){
    T_Arbre arbre;
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        tailleMemoire(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }

}

T_Sommet *creerSommet(int element){
    T_Sommet *sommet = (T_Sommet *)malloc(sizeof(T_Sommet));
    sommet->borneInf = element;
    sommet->borneSup = element;
    sommet->filsGauche = NULL;
    sommet->filsDroit = NULL;
    return sommet;
}

T_Arbre insererElement(T_Arbre abr, int element){
    T_Sommet *y = NULL;
    T_Sommet *x = abr;
    while (x!=NULL){
        y = x;
        if (x->borneInf > element+1){
            x = x->filsGauche;
        }
        else if (x->borneSup < element-1){
            x = x->filsDroit;
        }
        else {
            if (element == x->borneInf - 1) x->borneInf = element;
            if (element == x->borneSup + 1) x->borneSup = element;
            return abr;
        }
    }
    if (y == NULL) return creerSommet(element);
    else if (element < y->borneInf) y->filsGauche = creerSommet(element);
    else if (element > y->borneSup) y->filsDroit = creerSommet(element);
    return abr;
}


void afficherSommets(T_Arbre abr) {
    if (abr != NULL){
        afficherSommets(abr->filsGauche);
        printf("[%d ;%d], ",abr->borneInf, abr->borneSup);
        afficherSommets(abr->filsDroit);
    }
}

void afficherElements(T_Arbre abr){
    if (abr != NULL){
        afficherElements(abr->filsGauche);
        for (int i = abr->borneInf; i<=abr->borneSup; i++){
            printf("%d, ", i);
        }
        afficherElements(abr->filsDroit);
    }
}

bool validiteElements(int element){
    if(element>0){
        return true;
    }
    return false;
}

bool validiteSommet(int element){
    
    bool creer;
    creer = true;
    if(element==0 || element>0 || element<0){
        creer = true;
    }else{
        creer = false;
    }
    
    return creer;

}

bool arbreNonVide(T_Arbre abr){
    // bool non_vide = false;
    // if(abr == NULL){
    //     non_vide = false;
    // }else{
    //     non_vide = true;
    // }   
    // return non_vide;
    return (abr != NULL);
}
void insertion_sommet(T_Arbre abr, T_Sommet* sommet){
    if (sommet != NULL){
        insertion_sommet(abr, sommet->filsGauche);
        insertion_sommet(abr, sommet->filsDroit);
        for (int i = sommet->borneInf; i <= sommet->borneSup; i++){
            insererElement(abr, i);
        }
    }
    

}

T_Arbre supprimerElement(T_Arbre abr, int element){
    T_Sommet *x = abr;
    if (x == NULL) return abr;
    else if (element < x->borneInf) supprimerElement(x->filsGauche, element);
    else if (element > x->borneSup) supprimerElement(x->filsDroit, element);
    else if (element <= x->borneSup && element >= x->borneInf){
        if (element == x->borneInf && element < x->borneSup) x->borneInf++;
        else if (element == x->borneSup && element > x->borneInf) x->borneInf--;
        else if (element == x->borneInf && element == x->borneSup){
            printf("in\n");
            T_Sommet *fils_gauche = x->filsGauche;
            T_Sommet *fils_droit = x->filsDroit;
            x = NULL;
            insertion_sommet(abr, fils_gauche);
            insertion_sommet(abr, fils_droit);
        }
        else {
            int bornesup = x->borneSup;
            x->borneSup = element-1;
            T_Sommet* new_sommet = creerSommet(element+1);
            new_sommet->borneSup = bornesup;
            new_sommet->filsDroit = x->filsDroit;
            x->filsDroit = new_sommet;
        }
    }
    return abr;
}

T_Sommet *rechercherElement(T_Arbre abr, int element){
    if (abr == NULL || (element >= abr->borneInf && element <= abr->borneSup)) {
        return abr;
    }

    if (element < abr->borneInf) {
        return rechercherElement(abr->filsGauche, element);
    } else {
        return rechercherElement(abr->filsDroit, element);
    }
}

T_Arbre choixCreationArbre(T_Arbre abr){
    char choix_suppression;
    int element;
    bool creer = false;

    while(choix_suppression != 'Y' && choix_suppression != 'N' && choix_suppression != 'y' && choix_suppression != 'n'){
        printf("Un arbre existe deja, voulez vous le supprimer pour en creer un nouveau ? (Y/N)\n");
        while (getchar() != '\n');
        choix_suppression = getchar();
    }
    if(choix_suppression == 'Y' || choix_suppression == 'y'){
        //supprimer proprement l'arbre precedent
        libererMemoire(abr);
        while (creer == false){
            printf("Veuillez saisir l'element du sommet a creer\n");
            scanf("%d", &element);
            creer = validiteSommet(element);
            if (creer == false){
                printf("Vous ne pouvez construire un sommet qu'avec un element corresppondant a un nombre entier\n");
            }
        }
        abr = creerSommet(element);
     }else{
         printf("Vous avez choisi de garder l'arbre precedent, vous pouvez utiliser les autres fonctionnalites du menu\n");
     }
     return abr;

}

void libererMemoire(T_Arbre abr){
    if (abr != NULL){
        libererMemoire(abr->filsGauche);
        libererMemoire(abr->filsDroit);
        free(abr);
    }
}


void tailleMemoire(T_Arbre abr){
    
    size_tree *taille_arbre = calculeTailleArbre(abr);
    printf("la taille (en octets) occupés par l’ABR est de %d", taille_arbre->taille_abr);
    printf("la taille (en octets) qu’aurait occupé un ABR dans la représentation classique est de %d", taille_arbre->taille_classique);
    printf("le nombre d’octets gagnés par cette représentation par intervalles est de %d", taille_arbre->taille_economise);

}

size_tree* calculeTailleNoeud(T_Sommet* sommet){
    size_tree *taille;
    taille->taille_classique = (sommet->borneSup+1-sommet->borneInf)*(sizeof(int)+__SIZEOF_POINTER__*2);
    taille->taille_economise = taille->taille_classique - sizeof(T_Sommet);
    taille->taille_abr = sizeof(T_Sommet);
    return taille;
}

size_tree* calculeTailleArbre(T_Arbre abr){
    if (abr != NULL){
        size_tree *taille;
        size_tree *taille_gauche;
        size_tree *taille_droit;
        taille_gauche = calculeTailleArbre(abr->filsGauche);
        taille_droit = calculeTailleArbre(abr->filsDroit);
        taille = calculeTailleNoeud(abr);
        taille->taille_classique += taille_gauche->taille_classique + taille_droit->taille_classique;
        taille->taille_economise += taille_gauche->taille_economise + taille_droit->taille_economise;
        taille->taille_abr = taille_gauche->taille_abr + taille_droit->taille_abr;
        return taille;
    }

    // Si l'arbre est NULL, on retourne une taille de 0
    size_tree *taille;
    taille->taille_classique = 0;
    taille->taille_economise = 0;
    return taille;
}
