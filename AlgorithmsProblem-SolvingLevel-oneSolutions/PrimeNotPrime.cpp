#include <iostream>
#include <cmath>
using namespace std;


enum enPrimeNotPrime{
    Prime =1,
    NotPrime=2
};

float ReadPositiveNumber(string Message){
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

enPrimeNotPrime CHeckPrime(int Number){
    int M = round(Number/2);
    for(int i = 2; i <= M; i++){
        if(Number % i == 0){
            return enPrimeNotPrime::NotPrime;
        }
    }
    return enPrimeNotPrime::Prime;
}

void PrintNuberType(int Number){
    if(CHeckPrime(Number) == enPrimeNotPrime::Prime){
        cout << "The number is Prime" << endl;
    }
    else{
        cout << "The number is Not Prime" << endl;
    }
}

int main(){
    int Number = ReadPositiveNumber("Please enter positive number: ");
    PrintNuberType(Number);
    return 0;
}