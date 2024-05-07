#include "tp4.h"

T_Sommet *creerSommet(int element){
    T_Sommet *sommet;
    sommet->borneInf = element;
    sommet->borneSup = element;
    sommet->filsGauche = NULL;
    sommet->filsDroit = NULL;
    return sommet;
}

T_Arbre insererElement(T_Arbre abr, int element){
    
}