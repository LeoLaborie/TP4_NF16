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

T_Arbre supprimerElement(T_Arbre abr, int element, T_Sommet *pere);

bool validiteSommet(int element);

bool validiteElements(int nombre_elements);

bool arbreNonVide(T_Arbre abr);

void tailleMemoire(T_Arbre abr);

size_t calculerTailleNoeud(T_Sommet* sommet);

size_t calculerTailleArbre(T_Arbre abr);

int compterNombreElements(T_Sommet* sommet);

void libererMemoire(T_Arbre abr);

void insertion_sommet(T_Arbre abr, T_Sommet* sommet);

T_Arbre choixCreationArbre(T_Arbre abr);

T_Arbre appelCreerSommet(T_Arbre arbre);

T_Arbre appelInsererNElement(T_Arbre arbre);

void appelRechercherElement(T_Arbre arbre);

void appelAfficherSommets(T_Arbre arbre);

void appelAfficherElements(T_Arbre arbre);

T_Arbre appelSupprimerElement(T_Arbre arbre);

void appelTailleMemoire(T_Arbre arbre);

bool appelQuitter(T_Arbre arbre);

#endif
