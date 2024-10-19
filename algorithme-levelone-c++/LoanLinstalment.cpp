#include <iostream>
using namespace std;

int main(){
    float loanAmount;
    int months;
    cout << "Enter loan amount: ";
    cin >> loanAmount;
    cout << "Enter number of months: ";
    cin >> months;
    cout << "The monthly installment is " << loanAmount/months << endl;

    double amout = loanAmount/months;
    cout << "The amount is: " << amout << endl;
    return 0;

}