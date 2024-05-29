#include "tp4.h"
#include <stdlib.h>
#include <stdio.h>

T_Arbre appelCreerSommet(T_Arbre arbre){
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
        arbre = choixCreationArbre(arbre);
    }
    return arbre;
}

T_Arbre appelInsererNElement(T_Arbre arbre){
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
    return arbre;
}

void appelRechercherElement(T_Arbre arbre){
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

void appelAfficherSommets(T_Arbre arbre){
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        afficherSommets(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
}

void appelAfficherElements(T_Arbre arbre){
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        afficherElements(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
}

T_Arbre appelSupprimerElement(T_Arbre arbre){
    bool non_vide, supprimer;
    int element_suppression, element_recherche;
    printf("Veuillez saisir l'element que vous souhaitez supprimer\n");
    scanf("%d", &element_suppression);
    non_vide = arbreNonVide(arbre);
    supprimer = validiteSommet(element_recherche);
    if(non_vide == true && supprimer == true){
        T_Sommet *pere;
        arbre = supprimerElement(arbre, element_suppression, pere);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }
    return arbre;
}

void appelTailleMemoire(T_Arbre arbre){
    bool non_vide;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        tailleMemoire(arbre);
    }else{
        printf("Veuillez dans un premier temps creer un arbre");
    }

}

bool appelQuitter(T_Arbre arbre){
    bool non_vide, continuer;
    non_vide = arbreNonVide(arbre);
    if(non_vide == true){
        libererMemoire(arbre);
        continuer = false;
    }
    else {
        continuer = true;
    }
    return continuer;
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

T_Arbre supprimerElement(T_Arbre abr, int element, T_Sommet* pere){
    T_Sommet *x = abr;
    if (x == NULL) return abr;
    else if (element < x->borneInf) supprimerElement(x->filsGauche, element, x);
    else if (element > x->borneSup) supprimerElement(x->filsDroit, element, x);
    else if (element <= x->borneSup && element >= x->borneInf){
        if (element == x->borneInf && element < x->borneSup) x->borneInf++;
        else if (element == x->borneSup && element > x->borneInf) x->borneSup--;
        else if (element == x->borneInf && element == x->borneSup){
            printf("Suppression du sommet [%d ; %d]\n", x->borneInf, x->borneSup);
            if (x->filsGauche == NULL && x->filsDroit == NULL){
                if (pere->filsDroit == x) pere->filsDroit = NULL;
                else pere->filsGauche = NULL;
                x = NULL;
            }
            else if (x->filsGauche == NULL){
                if (pere->filsDroit == x) pere->filsDroit = x->filsDroit;
                else pere->filsGauche = x->filsDroit;
                x = NULL;
            }
            else if (x->filsDroit == NULL){
                if (pere->filsDroit == x) pere->filsDroit = x->filsGauche;
                else pere->filsGauche = x->filsGauche;
                x = NULL;
            }
            else{
                T_Sommet *y = x->filsDroit;
                while (y->filsGauche != NULL){
                    y = y->filsGauche;
                }
                x->borneInf = y->borneInf;
                x->borneSup = y->borneSup;
                supprimerElement(x->filsDroit, y->borneInf, x);
            }

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
        printf("liberation du sommet [%d ; %d]\n", abr->borneInf, abr->borneSup);
        libererMemoire(abr->filsGauche);
        libererMemoire(abr->filsDroit);
        abr = NULL;
    }
}

void tailleMemoire(T_Arbre abr) {
    size_t tailleReelle = calculerTailleArbre(abr);
    int nombreElements = compterNombreElements(abr);
    size_t tailleRepresentationClassique = nombreElements * sizeof(T_Sommet);
    size_t gainMemoire = tailleRepresentationClassique - tailleReelle;

    printf("La taille de l'ABR est : %zu octets\n", tailleReelle);
    printf("La taille de l'ABR en representation classique est : %zu octets\n", tailleRepresentationClassique);
    printf("Le nombre d'octets gagnes grace a cette representation est : %zu octets\n", gainMemoire);
}

size_t calculerTailleNoeud(T_Sommet* sommet) {
    if (sommet == NULL) {
        return 0;
    }
    
    size_t tailleNoeud = sizeof(T_Sommet);
    tailleNoeud += calculerTailleNoeud(sommet->filsGauche);
    tailleNoeud += calculerTailleNoeud(sommet->filsDroit);
    
    return tailleNoeud;
}

size_t calculerTailleArbre(T_Arbre abr) {
    return calculerTailleNoeud(abr);
}

int compterNombreElements(T_Sommet* sommet) {
    if (sommet == NULL) {
        return 0;
    }
    
    int nombreTotalElements = sommet->borneSup - sommet->borneInf + 1;
    nombreTotalElements += compterNombreElements(sommet->filsGauche);
    nombreTotalElements += compterNombreElements(sommet->filsDroit);
    
    return nombreTotalElements;
}
