#include <iostream>
using namespace std;


void ReadNumber(int& num1, int& num2, int& num3){
    cout << "Please enter your number 1 ? " << endl;
    cin >> num1;
    cout << "Please enter your number 2 ? " << endl;
    cin >> num2;
    cout << "Please enter your number 3 ? " << endl;
    cin >> num3;
}


int MaxThreeNumber(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3)
        return num1;
    else if(num2 > num1 && num2 > num3)
        return num2;
    else
        return num3;    
}

void PrintResult(int max){
    cout << "The max number is : " << max << endl;
}

int main(){

    int num1, num2, num3;
    ReadNumber(num1, num2, num3);
    PrintResult(MaxThreeNumber(num1, num2, num3));
    return 0;
}