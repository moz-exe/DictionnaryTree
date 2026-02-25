#include "noeud.h"

Noeud::Noeud(char l) : lettre(l), finMot(false), gauche(nullptr), droite(nullptr) {}

Noeud::~Noeud() {
    delete gauche;
    delete droite;
}
