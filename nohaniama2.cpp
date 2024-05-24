 
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Fonction pour obtenir les taux de change par rapport au MAD
unordered_map<string, double> obtenirTauxDeChange() {
    return {
        {"MAD", 1.0},    // Dirham marocain (référence)
        {"USD", 0.11},   // Dollar américain
        {"EUR", 0.092},  // Euro
        {"GBP", 0.081},  // Livre sterling
        {"JPY", 12.0},   // Yen japonais
        {"CAD", 0.136},  // Dollar canadien
        {"AUD", 0.148},  // Dollar australien
        {"CHF", 0.100},  // Franc suisse
        {"CNY", 0.69},   // Yuan chinois
        {"INR", 8.0},    // Roupie indienne
        {"RUB", 8.04},   // Rouble russe
        {"BRL", 0.58},   // Réal brésilien
        {"ZAR", 1.58},   // Rand sud-africain
        {"KRW", 126.0},  // Won sud-coréen
        {"SGD", 0.148}   // Dollar de Singapour
    };
}

// Fonction pour afficher les devises disponibles
void afficherDevises(const unordered_map<string, double>& tauxDeChange) {
    cout << "Devises disponibles : ";
    for (const auto& paire : tauxDeChange) {
        cout << paire.first << " ";
    }
    cout << endl;
}

// Fonction pour obtenir le taux de change d'une devise
double obtenirTaux(const unordered_map<string, double>& tauxDeChange, const string& devise) {
    if (tauxDeChange.find(devise) != tauxDeChange.end()) {
        return tauxDeChange.at(devise);
    } else {
        cerr << "Devise non valide." << endl;
        exit(1);  // Quitter le programme si la devise n'est pas valide
    }
}

// Fonction pour convertir une devise en une autre
double convertir(double montant, double tauxDeChangeDepart, double tauxDeChangeDestination) {
    return montant * (tauxDeChangeDestination / tauxDeChangeDepart);
}

// Fonction principale du programme
int main() {
    auto tauxDeChange = obtenirTauxDeChange();

    string deviseDepart, deviseDestination;
    double montant;

    cout << "Application de Conversion de Devises Simplifiée\n";
    afficherDevises(tauxDeChange);

    cout << "Entrez la devise de départ : ";
    cin >> deviseDepart;
    cout << "Entrez la devise de destination : ";
    cin >> deviseDestination;
    cout << "Entrez le montant à convertir : ";
    cin >> montant;

    double tauxDepart = obtenirTaux(tauxDeChange, deviseDepart);
    double tauxDestination = obtenirTaux(tauxDeChange, deviseDestination);

    double resultat = convertir(montant, tauxDepart, tauxDestination);
    cout << montant << " " << deviseDepart << " = " << resultat << " " << deviseDestination << endl;

    return 0;
}
