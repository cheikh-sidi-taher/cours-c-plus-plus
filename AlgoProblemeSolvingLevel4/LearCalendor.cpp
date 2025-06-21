#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

string NamesOfMonths(short month)
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}
short ReadYear()
{
    short year;
    cout << "\nPlease enter a year to check? ";
    cin >> year;
    return year;
}

short NumberDayInMonth(short month, short year)
{
    if (month < 1 || month > 12)
        return 0;

    int
        days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

void PrintCalender(short month, short year)
{
    for (int day = 1; day <= NumberDayInMonth(month, year); day++)
    {
        cout << day << " ";
    }
}
short ReadMonth()
{
    short month;
    cout << "\nPlease enter a Month? ";
    cin >> month;
    return month;
}
int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    PrintCalender(month, year);
}
