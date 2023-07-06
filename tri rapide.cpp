#include <iostream>
using namespace std;


void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int partitionner(int tableau[], int debut, int fin) {
    int pivot = tableau[fin]; 
    int i = debut - 1; 

    for (int j = debut; j <= fin - 1; j++) {
        if (tableau[j] < pivot) {
            i++;
            echanger(tableau[i], tableau[j]);
        }
    }
    echanger(tableau[i + 1], tableau[fin]); 
    return (i + 1); 
}


void triRapide(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int indicePivot = partitionner(tableau, debut, fin); 
        triRapide(tableau, debut, indicePivot - 1); 
        triRapide(tableau, indicePivot + 1, fin); 
    }
}


void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl;
}

int main() {
    int tableau[] = { 7, 2, 1, 6, 8, 5, 3, 4 };
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    cout << "Tableau avant le tri rapide : ";
    afficherTableau(tableau, taille);

    triRapide(tableau, 0, taille - 1);

    cout << "Tableau après le tri rapide : ";
    afficherTableau(tableau, taille);

    return 0;
}
