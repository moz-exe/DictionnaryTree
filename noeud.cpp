#include "noeud.h"

Noeud::Noeud(char l) : lettre(l), finMot(false), gauche(nullptr), droit(nullptr) {}

Noeud::~Noeud() {
    delete gauche;
    delete droit;
}
