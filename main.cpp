#include <iostream>
#include "dictionnaire.h"

int main() {
    Dictionnaire dict;

    // Ajouter des mots
    dict.ajouterMot("abas");
    dict.ajouterMot("arbre");
    dict.ajouterMot("arbuste");
    dict.ajouterMot("bas");
    dict.ajouterMot("las");
    dict.ajouterMot("lasse");
    dict.ajouterMot("lit");

    // Afficher le dictionnaire
    std::cout << "Dictionnaire :" << std::endl;
    dict.afficherDict();

    // Chercher des mots
    std::cout << "\nRecherche de 'arbre' : " << (dict.chercherMot("arbre") ? "Trouvé" : "Non trouvé") << std::endl;
    std::cout << "Recherche de 'arbremagique' : " << (dict.chercherMot("arbremagique") ? "Trouvé" : "Non trouvé") << std::endl;

    // Enlever un mot
    dict.enleverMot("las");
    std::cout << "\nAprès suppression de 'las' :" << std::endl;
    dict.afficherDict();

    return 0;
}
