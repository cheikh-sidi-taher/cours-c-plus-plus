#include <iostream>
#include <string>
using namespace std;


int ReadPositiveNumber(string Message)
{
    int Number ;
   do{
       cout << Message << endl;
       cin >> Number;
   }while(Number < 0);
   return Number;
}

int SumDigits(int Number)
{
    int Remainder = 0;
    int sum = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        sum += Remainder;
    }
    return sum;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter Positive a number: ");
    cout << "Sum = " << SumDigits(Number) << endl;
    return 0;
}