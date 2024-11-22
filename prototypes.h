#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED


#define TAILLE 20


int partie; //Variable permettant de quitter la partie



char motSecret[TAILLE];
int mode;
char indice[255];

char lireCaractere();
void AfficherAide();
char* piocherMot();
void Jouer(char motSecret[]);





#endif