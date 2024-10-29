#include <iostream>
using namespace std;    



void ReadNumber(int& num1, int& num2){
    cout << "Please enter your number 1 ? " << endl;
    cin >> num1;
    cout << "Please enter your number 2 ? " << endl;
    cin >> num2;
}

int MaxTwoNumber(int num1, int num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
    
}

void PrintResult(int max){
    cout << "The max number is : " << max << endl;
}

int main(){
    int num1, num2;
    ReadNumber(num1, num2);
    PrintResult(MaxTwoNumber(num1, num2));
    return 0;
}