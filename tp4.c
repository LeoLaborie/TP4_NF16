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

}
