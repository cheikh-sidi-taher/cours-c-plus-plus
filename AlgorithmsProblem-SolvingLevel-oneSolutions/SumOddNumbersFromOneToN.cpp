#include <iostream>
using namespace std;

enum enOddOrEven{Odd =1, Even = 2};
int ReadNumber(){
    int N;
    cout << "Please enter a number: " << endl;
    cin >> N;
    return N;
}

enOddOrEven CheckOddOrEven(int number){
    if (number % 2 != 0)
    return enOddOrEven::Odd;
    else
    return enOddOrEven::Even;
}

int SumOddNumbersFromOneToN(int number){
    int sum = 0;
    for (int i = 1; i <= number; i++)
    if (CheckOddOrEven(i) == enOddOrEven::Odd)
    sum += i;
    return sum;
}


void PrintResult(int sum){
    cout << "Sum = " << sum << endl;
}


int main(){
    PrintResult(SumOddNumbersFromOneToN(ReadNumber()));
    return 0;
}