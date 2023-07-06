#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>

struct Vente {
    std::string produit;
    int quantite;
    double prixUnitaire;
};

std::vector<Vente> lireFichierCSV(const std::string& nomFichier) {
    std::vector<Vente> ventes;

    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return ventes;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        std::string produit;
        int quantite;
        double prixUnitaire;

        if (std::getline(iss, produit, ';') && iss >> quantite && iss.ignore() >> prixUnitaire) {
            ventes.push_back({ produit, quantite, prixUnitaire });
        }
    }

    fichier.close();

    return ventes;
}

void afficherVentes(const std::vector<Vente>& ventes) {
    for (const auto& vente : ventes) {
        std::cout << "Produit : " << vente.produit << ", Quantite : " << vente.quantite
            << ", Prix unitaire : " << vente.prixUnitaire << std::endl;
    }
}

double calculerTotalVentes(const std::vector<Vente>& ventes) {
    double total = 0.0;
    for (const auto& vente : ventes) {
        total += vente.quantite * vente.prixUnitaire;
    }
    return total;
}

double calculerMoyenneVentes(const std::vector<Vente>& ventes) {
    if (ventes.empty()) {
        return 0.0;
    }

    double total = calculerTotalVentes(ventes);
    return total / ventes.size();
}

int main() {
    std::string nomFichier = "ventes.csv";
    std::vector<Vente> ventes = lireFichierCSV(nomFichier);

    std::cout << "Ventes :" << std::endl;
    afficherVentes(ventes);

    double totalVentes = calculerTotalVentes(ventes);
    std::cout << "Total des ventes : " << totalVentes << std::endl;

    double moyenneVentes = calculerMoyenneVentes(ventes);
    std::cout << "Moyenne des ventes : " << moyenneVentes << std::endl;

    return 0;
}

