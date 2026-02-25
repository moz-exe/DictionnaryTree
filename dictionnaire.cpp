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
    if (!noeud) {
        noeud = new Noeud(mot[index]);
    }

    if (index == mot.size() - 1) {
        noeud->finMot = true;
        return;
    }

    ajouterMotRec(noeud->gauche, mot, index + 1);
}

bool Dictionnaire::enleveMot(const std::string& mot) {
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

bool Dictionnaire::chercheMot(const std::string& mot) const {
    return chercheMotRec(racine, mot, 0);
}

bool Dictionnaire::chercheMotRec(const Noeud* noeud, const std::string& mot, size_t index) const {
    if (!noeud) return false;

    if (index == mot.size() - 1) {
        return noeud->finMot;
    }

    return chercheMotRec(noeud->gauche, mot, index + 1);
}

void Dictionnaire::affcherDict() const {
    afficherDictRec(racine, "");
}

void Dictionnaire::afficherDictRec(const Noeud* noeud, std::string mot) const {
    if (!noeud) return;

    std::string nouveauMot = mot + noeud->lettre;

    if (noeud->finMot) {
        std::cout << nouveauMot << std::endl;
    }

    afficherDictRec(noeud->gauche, nouveauMot);
    afficherDictRec(noeud->droit, mot);
}

Noeud* Dictionnaire::copierArbre(const Noeud* noeud) {
    if (!noeud) return nullptr;

    Noeud* nouveauNoeud = new Noeud(noeud->lettre);
    nouveauNoeud->finMot = noeud->finMot;
    nouveauNoeud->gauche = copierArbre(noeud->gauche);
    nouveauNoeud->droit = copierArbre(noeud->droit);

    return nouveauNoeud;
}

void Dictionnaire::detruireArbre(Noeud* noeud) {
    if (!noeud) return;
    detruireArbre(noeud->gauche);
    detruireArbre(noeud->droit);
    delete noeud;
}
