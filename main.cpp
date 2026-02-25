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
    dict.affcherDict();

    // Chercher des mots
    std::cout << "\nRecherche de 'arbre' : " << (dict.chercheMot("arbre") ? "Trouvé" : "Non trouvé") << std::endl;
    std::cout << "Recherche de 'arbremagique' : " << (dict.chercheMot("arbremagique") ? "Trouvé" : "Non trouvé") << std::endl;

    // Enlever un mot
    dict.enleveMot("las");
    std::cout << "\nAprès suppression de 'las' :" << std::endl;
    dict.affcherDict();

    return 0;
}
