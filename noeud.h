#pragma once

#include <string>

class Noeud
{
public:
	Noeud(char l);
	~Noeud();

	char lettre;
	bool finMot;
	Noeud* gauche; // Noeud fils de gauche
	Noeud* droite; // Noeud fils de droite
	//int card;
	//int hauteur;
};