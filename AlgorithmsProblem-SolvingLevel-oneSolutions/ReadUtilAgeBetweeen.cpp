#include <iostream>
using namespace std;

int ReadAge()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    return age;
}

bool ValidateNumberInRange(int Number, int from, int to)
{
    return Number >= from && Number <= to;
}

int ReadUtilAgeBetweeen(int from, int to)
{
    int age = 0;
    do
    {
        age = ReadAge();
    } while (!ValidateNumberInRange(age, from, to));
    return age;
}

void PrintResult(int age)
{
   cout << "Your Age is " << age << endl;
}
int main()
{
    PrintResult(ReadUtilAgeBetweeen(18, 45));
    return 0;
}