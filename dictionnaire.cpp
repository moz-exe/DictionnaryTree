#include "dictionnaire.h"
#include <iostream>

Dictionnaire::Dictionnaire() : racine(nullptr) {}

Dictionnaire::Dictionnaire(const Dictionnaire& d) : racine(copierArbre(d.racine)) {}

Dictionnaire::~Dictionnaire() {
    detruireArbre(racine);
}

void Dictionnaire::ajouterMot(const std::string& mot) {
    if (mot.empty()) return;
    ajouterMotRec(racine, mot, 0);
}

void Dictionnaire::ajouterMotRec(Noeud*& noeud, const std::string& mot, size_t index) {
    // JSP si c'est nécessaire
    if (!noeud) {
        noeud = new Noeud(mot[index]);
    }
    // JSP si c'est nécessaire

    if (index >= mot.length()) {
        noeud->finMot = true;
        return;
    }

    // ajouterMotRec(noeud->gauche, mot, index + 1);

    if (!noeud->gauche) {

        // Si pas de fils de gauche, on est sur une feuille, on ajoute forcément la prochaine lettre dans un nouveau neoud
        // Si pas de fils de gauche alors pas de fils de droite non plus
        // Noeud* nouveauNoeud = new Noeud(mot[index + 1]);
        // std::cout << "oui" << std::endl;
        // noeud->gauche = nouveauNoeud;
        noeud->gauche = new Noeud(mot[0]);
        // ajouterMotRec(noeud->gauche, mot, index + 1);
    }

    // else if (noeud->lettre == mot[index]) {
    //     if (index == mot.size() - 1) {
    //         noeud->finMot = true;
    //         return;
    //     }

    //     else {
    //         ajouterMotRec(noeud->gauche, mot, index + 1);
    //     }
    // }

    // else if (!noeud->droite) {
    //     if (mot[index] < noeud->gauche->lettre) { // Trie l'arbre par ordre alphabétique
    //         noeud->droite = noeud->gauche;
    //         noeud->gauche = new Noeud(mot[index]);
    //         ajouterMotRec(noeud->gauche, mot, index);
    //     }

    //     else {
    //         noeud->droite = new Noeud(mot[index]);
    //         ajouterMotRec(noeud->droite, mot, index);
    //     }
    // }

    // else {
    //     ajouterMotRec(noeud->droite, mot, index);
    // }
}

bool Dictionnaire::enleverMot(const std::string& mot) {
    return enleverMotRec(racine, mot, 0);
}

bool Dictionnaire::enleverMotRec(Noeud*& noeud, const std::string& mot, size_t index) {
    if (!noeud) return false;

    if (index == mot.size() - 1) {
        if (noeud->finMot) {
            noeud->finMot = false;
            return true;
        }
        return false;
    }

    return enleverMotRec(noeud->gauche, mot, index + 1);
}

bool Dictionnaire::chercherMot(const std::string& mot) const {
    return chercherMotRec(racine, mot, 0);
}

bool Dictionnaire::chercherMotRec(const Noeud* noeud, const std::string& mot, size_t index) const {
    if (!noeud) return false;

    if (index == mot.size() - 1) {
        return noeud->finMot;
    }

    return chercherMotRec(noeud->gauche, mot, index + 1);
}

void Dictionnaire::afficherDict() const {
    afficherDictRec(racine, "");
}

void Dictionnaire::afficherDictRec(const Noeud* noeud, std::string mot) const {
    if (!noeud) return;

    std::string nouveauMot = mot + noeud->lettre;

    if (noeud->finMot) {
        std::cout << nouveauMot << std::endl;
    }

    afficherDictRec(noeud->gauche, nouveauMot);
    afficherDictRec(noeud->droite, mot);
}

Noeud* Dictionnaire::copierArbre(const Noeud* noeud) {
    if (!noeud) return nullptr;

    Noeud* nouveauNoeud = new Noeud(noeud->lettre);
    nouveauNoeud->finMot = noeud->finMot;
    nouveauNoeud->gauche = copierArbre(noeud->gauche);
    nouveauNoeud->droite = copierArbre(noeud->droite);

    return nouveauNoeud;
}

void Dictionnaire::detruireArbre(Noeud* noeud) {
    if (!noeud) return;
    detruireArbre(noeud->gauche);
    detruireArbre(noeud->droite);
    delete noeud;
}
