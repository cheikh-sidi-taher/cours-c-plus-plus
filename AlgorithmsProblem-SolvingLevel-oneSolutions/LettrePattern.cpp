#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


void PrintLetterPattern(int Number)
{
    for(int i =65 ; i <= 65 + Number - 1; i++)
    {
        for (int j=1 ; j<= i - 65 + 1 ; j++) 
        {
            cout << char(i);
        }
        cout << "\n";
    }
}


int main()
{
    int Number = ReadPositiveNumber("Enter the Number of Letters : ");
    PrintLetterPattern(Number);
    return 0;
}