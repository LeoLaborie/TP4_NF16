#include "tp4.h"
#include <stdlib.h>

T_Sommet *creerSommet(int element){
    T_Sommet *sommet = (T_Sommet *)malloc(sizeof(T_Sommet));
    sommet->borneInf = element;
    sommet->borneSup = element;
    sommet->filsGauche = NULL;
    sommet->filsDroit = NULL;
    return sommet;
}

T_Arbre insererElement(T_Arbre abr, int element){
    T_Sommet *y;
    T_Sommet *x = abr;
    while (x!=NULL){
        y = x;
        if (x->borneInf > element){
            x = x->filsGauche;
        }
        else if (x->borneSup < element){
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

bool validiteElements(int nombre_elements){
    
    bool inserer;
    inserer = true;
    if(nombre_elements==0){
        inserer = false;
    }else if(nombre_elements>0){
        inserer = true;
    }else{
        inserer = false;
    }
    
    return inserer;
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
    bool vide;
    vide = false;
    if(abr == NULL){
        vide = true;
    }else{
        vide = false;
    }
    return vide;
}

T_Arbre supprimerElement(T_Arbre abr, int element){
    T_Sommet *x = abr;
    if (x == NULL) return abr;
    else if (element < x->borneInf) supprimerElement(x->filsGauche, element);
    else if (element > x->borneSup) supprimerElement(x->filsDroit, element);
    else if (element <= x->borneSup && element >= x->borneInf){
        if (element == x->borneInf) x->borneInf++;
        else if (element == x->borneSup) x->borneInf--;
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

void choixCreationArbre(T_Arbre abr, char choix_suppression){

    int element;
    bool creer;

    while(choix_suppression != 'Y' || choix_suppression != 'N'){
         printf("Un arbre existe deja, voulez vous le supprimer pour en creer un nouveau ? (Y/N)\n");
         scanf("%c", &choix_suppression);
    }
    if(choix_suppression == 'Y'){
         //supprimer proprement l'arbre precedent
         printf("Veuillez saisir l'element du sommet a creer\n");
         scanf("%d", &element);
         creer = validiteSommet(element);
         if (creer == true){
             creerSommet(element);
         }else{
             printf("Vous ne pouvez construire un sommet qu'avec un element corresppondant a un nombre entier\n");
         }
     }else{
         printf("Vous avez choisi de garder l'arbre precedent, vous pouvez utiliser les autres fonctionnalites du menu\n");
     }

}
