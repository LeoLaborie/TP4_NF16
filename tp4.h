#ifndef TP4_H
#define TP4_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Sommet{
    
int borneInf;
int borneSup;
struct Sommet* filsGauche;
struct Sommet* filsDroit;


}T_Sommet;

typedef T_Sommet* T_Arbre;

T_Sommet *creerSommet(int element);

T_Arbre insererElement(T_Arbre abr, int element);

T_Sommet *rechercherElement(T_Arbre abr, int element);

void afficherSommets(T_Arbre abr);

void afficherElements(T_Arbre abr);

T_Arbre supprimerElement(T_Arbre abr, int element);

void tailleMemoire(T_Arbre abr);

bool validiteSommet(int element);

bool validiteElements(int nombre_elements);

bool arbreNonVide(T_Arbre abr);
