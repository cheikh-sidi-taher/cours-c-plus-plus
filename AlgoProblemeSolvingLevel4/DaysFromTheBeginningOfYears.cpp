#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (
        Month < 1 ||
        Month > 12)
        return 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}


int totalDays(short Day, short Month, short Year)
{
    int total = 0;
    for (int i = 1; i < Month; i++)
    {
        total += NumberOfDaysInAMonth(i, Year);
    }
    total += Day;
    return total;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    cout << totalDays(Day, Month, Year) << endl;
    system("pause>0");
    return 0;
}