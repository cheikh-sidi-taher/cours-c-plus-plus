#include <iostream>
#include <cmath>    
using namespace std;

int main() {
    double  Number, M;
    cout << "Enter the number: ";
    cin >> Number;
    cout << "Enter the power: ";
    cin >> M;
    cout << "Power of the number is: " << pow(Number,M) << endl;
    return 0;

}