#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

int Factorial(int N)
{
    int Factorial = 1;
    for (int counter = N; counter >= 1; counter--)
    {
        Factorial *= counter;
    }
    return Factorial;
}


int main()
{
    
   cout << Factorial(ReadPositiveNumber("Please enter positive number: ")) << endl;
    return 0;
}