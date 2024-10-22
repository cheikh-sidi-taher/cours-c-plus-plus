#include <iostream>
using namespace std;

void readArrayData(int numbres[3])
{
    cout << "Enter numbersby one: ";
    cin >> numbres[0];
    cout << "Enter numbersby two: ";
    cin >> numbres[1];
    cout << "Enter numbersby three: ";
    cin >> numbres[2];
}

void printArrayData(int numbres[3])
{
    cout << "Numbers by one: " << numbres[0] << endl;
    cout << "Numbers by two: " << numbres[1] << endl;
    cout << "Numbers by three: " << numbres[2] << endl;
}
int main()
{
    int numbres[3];
    readArrayData(numbres);
    printArrayData(numbres);
    return 0;
}