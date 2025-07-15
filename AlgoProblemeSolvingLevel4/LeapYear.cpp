#include <iostream>
using namespace std;


bool isLeapYear(short year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short ReadYear()
{
    short year;
    cout << "Enter a year: ";
    cin >> year;
    return year;
}

int main()
{

    short year = ReadYear();
    if(isLeapYear(year))
        cout << year << " is a leap year.";
    else
        cout << year << " is NOT a leap year.";
    return 0;
}