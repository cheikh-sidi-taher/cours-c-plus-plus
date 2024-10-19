#include <iostream>
using namespace std;

int main(){
    int number ,powerTow , powerThree,powerFour;
    cout << "Enter a number: ";
    cin >> number;
    powerTow = number * number;
    powerThree = number * number * number;
    powerFour = number * number * number * number;
    cout << "The power of 2 is: " << powerTow << endl;
    cout << "The power of 3 is: " << powerThree << endl;
    cout << "The power of 4 is: " << powerFour << endl;
    return 0;
}