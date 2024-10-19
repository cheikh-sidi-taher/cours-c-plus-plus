#include <iostream>
using namespace std;
int main()
{
    int numberOne, numberTwo,numberThree;
    cout << "Enter the first number: ";
    cin >> numberOne;
    cout << "Enter the second number: ";
    cin >> numberTwo;
    cout << "Enter the third number: ";
    cin >> numberThree;
    int sum = numberOne + numberTwo + numberThree;
    cout << "The sum of the three numbers is: " << sum << endl;
    return 0;
}