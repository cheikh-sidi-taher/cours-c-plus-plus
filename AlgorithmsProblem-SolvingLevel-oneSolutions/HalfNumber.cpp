#include <iostream>
using namespace std;



double ReadHalfNumber(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}


float CalculateHalfNumber(float number){
    return (float)number / 2;
}


void PrintHalfNumber(float number){
    string Result = "The half number of " + to_string(number) + " is " + to_string(CalculateHalfNumber(number));
    cout << Result << endl;
}


int main(){ 
    PrintHalfNumber(ReadHalfNumber());
    return 0;
}