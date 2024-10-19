#include <iostream>
using namespace std;
int main(){
    int number1, number2, temp;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;
    temp = number2;
    number2 = number1;
    number1 = temp;
    cout << "The first number is: " << number1 << endl;
    cout << "The second number is: " << number2 << endl;
    return 0;
}