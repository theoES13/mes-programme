#include <iostream>
using namespace std;

void triBulle(int tableau[], int taille) {
    bool estTri�;
    for (int i = 0; i < taille - 1; i++) {
        estTri� = true;
        for (int j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // �change les �l�ments
                int temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                estTri� = false;
            }
        }
        // Verifie si le tableau � d�j� �t� tri�
        if (estTri�) {
            break;
        }
    }
}

int main() {
    int tableau[] = { 5, 2, 8, 6, 1, 3 };
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    cout << "Tableau avant le tri : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }

    triBulle(tableau, taille);

    cout << "\nTableau apr�s le tri : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }

    return 0;
}
