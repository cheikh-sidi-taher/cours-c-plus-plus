#include <iostream>
using namespace std;


float ReadPositiveNumber(string message){
    float number;
    do{
        cout << message;
        cin >> number;
    }while(number <= 0);
    return number;
}


float CalculateServiceTax(float TotalBill){
    TotalBill = TotalBill * 1.1;
    TotalBill = TotalBill * 1.16;
    return TotalBill;
}


int main(){
    float TotalBill = ReadPositiveNumber("Please enter total bill: ");
    cout << "Total bill with tax is: " << CalculateServiceTax(TotalBill) << endl;
    return 0;
}


