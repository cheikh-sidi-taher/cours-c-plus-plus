#include <iostream>
using namespace std;

int main()
{
    int numberOne, numberTow;

    cout << "Please enter the first number :";
    cin >> numberOne;

    cout << "Please enter the last number : ";
    cin >> numberTow;

    cout << "numberOne == numberTow is :" << (numberOne == numberTow) << endl;
    cout << "numberOne == numberTow is :" << (numberOne != numberTow) << endl;
    cout << "numberOne == numberTow is :" << (numberOne > numberTow) << endl;
    cout << "numberOne == numberTow is :" << (numberOne < numberTow) << endl;
    cout << "numberOne == numberTow is :" << (numberOne >= numberTow) << endl;
    cout << "numberOne == numberTow is :" << (numberOne <= numberTow) << endl;

    return 0;
}