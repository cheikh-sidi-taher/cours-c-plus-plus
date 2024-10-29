#include <iostream>
using namespace std;


void ReadThreeNumber(int& num1, int& num2, int& num3)
{
    cout << "Please enter your number 1 ? " << endl;
    cin >> num1;
    cout << "Please enter your number 2 ? " << endl;
    cin >> num2;
    cout << "Please enter your number 3 ? " << endl;
    cin >> num3;
}


int SumThreeNumber(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

void PrintResult(int total)
{
    cout << "Sum = " << total << endl;
}

int main()
{
    int num1, num2, num3;
    ReadThreeNumber(num1, num2, num3);
    PrintResult(SumThreeNumber(num1, num2, num3));
    return 0;
}