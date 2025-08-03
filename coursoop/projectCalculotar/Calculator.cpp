#include <iostream>
using namespace std;

class clsCalculator
{
private:
    int _Number;
    enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE } lastOperation;  // Enum avec toutes les opérations

public:
    // Constructeur pour initialiser _Number et lastOperation
    clsCalculator() : _Number(0), lastOperation(ADD) {}  // Par défaut, on suppose une addition

    // Fonction d'addition
    int Add(int Number)
    {
        _Number += Number;
        lastOperation = ADD;  // Enregistre l'opération "Add"
        return _Number;
    }

    // Fonction de soustraction
    int Subtract(int Number)
    {
        _Number -= Number;
        lastOperation = SUBTRACT;  // Enregistre l'opération "Subtract"
        return _Number;
    }

    // Fonction de multiplication
    int Multiply(int Number)
    {
        _Number *= Number;
        lastOperation = MULTIPLY;  // Enregistre l'opération "Multiply"
        return _Number;
    }

    // Fonction de division
    int Divide(int Number)
    {
        if (Number != 0) {
            _Number /= Number;
            lastOperation = DIVIDE;  // Enregistre l'opération "Divide"
        } else {
            cout << "Erreur: Division par zéro impossible !" << endl;
        }
        return _Number;
    }

    // Fonction pour réinitialiser _Number à 0
    void Clear()
    {
        _Number = 0;
        lastOperation = ADD;  // Réinitialise l'opération à "ADD" (par défaut)
        cout << "Le calculateur a été réinitialisé." << endl;
    }

    // Fonction pour obtenir la valeur actuelle de _Number
    int GetNunmber()
    {
        return _Number;
    }

    // Fonction pour afficher le résultat après l'opération la plus récente
    void PrintResult()
    {
        if (lastOperation == ADD)
        {
            cout << "Le résultat après l'addition est : " << GetNunmber() << endl;
        }
        else if (lastOperation == SUBTRACT)
        {
            cout << "Le résultat après la soustraction est : " << GetNunmber() << endl;
        }
        else if (lastOperation == MULTIPLY)
        {
            cout << "Le résultat après la multiplication est : " << GetNunmber() << endl;
        }
        else if (lastOperation == DIVIDE)
        {
            cout << "Le résultat après la division est : " << GetNunmber() << endl;
        }
        else
        {
            cout << "Aucune opération effectuée !" << endl;
        }
    }
};

int main()
{
    clsCalculator calculator;

    // Effectuer l'addition et afficher le résultat
    calculator.Add(20);
    calculator.PrintResult();  // Affiche "Le résultat après l'addition est : 20"

    // Effectuer la multiplication et afficher le résultat
    calculator.Multiply(3);
    calculator.PrintResult();  // Affiche "Le résultat après la multiplication est : 60"

    // Effectuer la division et afficher le résultat
    calculator.Divide(5);
    calculator.PrintResult();  // Affiche "Le résultat après la division est : 12"

    // Effectuer la soustraction et afficher le résultat
    calculator.Subtract(5);
    calculator.PrintResult();  // Affiche "Le résultat après la soustraction est : 7"

    // Réinitialiser le calculateur et afficher le résultat
    calculator.Clear();
    calculator.PrintResult();  // Affiche "Le résultat après l'addition est : 0"

    return 0;
}
