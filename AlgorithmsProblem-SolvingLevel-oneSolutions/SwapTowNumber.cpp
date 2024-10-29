#include <iostream>
using namespace std;


void ReadNumber(int& num1, int& num2 ){
    cout << "Please enter your number 1 ? " << endl;
    cin >> num1;
    cout << "Please enter your number 2 ? " << endl;
    cin >> num2;
}


int SwapNumber(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    return num1, num2;
}


void PrintResult(int num1, int num2){
    cout << "The first number is: " << num1 << endl;
    cout << "The second number is: " << num2 << endl;
}


int main(){

   int num1, num2;
   ReadNumber(num1, num2);
   PrintResult(num1, num2);
   SwapNumber(num1, num2);
   PrintResult(num1, num2);
   
}