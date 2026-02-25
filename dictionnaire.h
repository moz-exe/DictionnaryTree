#pragma once

#include <string>
#include "noeud.h"

class Dictionnaire {
public :
	Dictionnaire(); // Constructeur
	Dictionnaire(const Dictionnaire& d); // Constructeur de copie
	~Dictionnaire(); // Destructeur

	void ajouterMot(const std::string& mot);
	bool enleverMot(const std::string& mot);
	void afficherDict() const;
	bool chercherMot(const std::string& mot) const;

private : 
	Noeud* racine; //racine de l'arbre
	Noeud* copierArbre(const Noeud* noeud);

	//int cpt; // Nombre de noeuds dans l'arbre
	//bool arbreVide();
	//void viderArbre();


	void ajouterMotRec(Noeud*& noeud, const std::string& mot, size_t index);
	bool enleverMotRec(Noeud*& noeud, const std::string& mot, size_t index);
	bool chercherMotRec(const Noeud* noeud, const std::string& mot, size_t index) const;
	void afficherDictRec(const Noeud* noeud, std::string mot) const;
	void detruireArbre(Noeud* noeud);
};