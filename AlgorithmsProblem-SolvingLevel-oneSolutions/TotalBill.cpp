#include <iostream>
using namespace std;


float ReadPositiveNumber(string Message){
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

float   CalculateRemainder(float TotalBill, float CashPaid){
    float result = CashPaid - TotalBill;
    return result;
}


int main (){

    float TotalBill = ReadPositiveNumber("Please enter total bill: ");
    float CashPaid = ReadPositiveNumber("Please enter cash paid: ");

    cout << endl;
    cout << "Total bill is: " << TotalBill << endl;
    cout << "Cash paid is: " << CashPaid << endl;
    cout << "****************************\n";
    
    cout << "Remainder is: " << CalculateRemainder(TotalBill, CashPaid) << endl;
    return 0;

    
}