#include <iostream>
using namespace std;

// Fonction pour échanger deux nombres
void swap(int a, int b) {
    int temp = a; // Stocker temporairement la valeur de a
    a = b;        // Assigner la valeur de b à a
    b = temp;    // Assigner la valeur temporaire à b
}

int main() {
    int x, y;

    // Demander à l'utilisateur d'entrer deux nombres
    cout << "Entrez le premier nombre: ";
    cin >> x;
    cout << "Entrez le deuxième nombre: ";
    cin >> y;

    // Afficher les valeurs avant le swap
    cout << "Avant le swap: x = " << x << ", y = " << y << endl;

    // Appeler la fonction swap
    swap(x, y);

    // Afficher les valeurs après le swap
    cout << "Après le swap: x = " << x << ", y = " << y << endl;

    return 0;
}
