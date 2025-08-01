#include <iostream> 
using namespace std;
bool isLeapYear(
    short
        Year)
{
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (
               Year % 4 == 0 &&
               Year % 100 != 0) ||
           (Year % 400 ==
            0);
}
short NumberOfDaysInAMonth(
    short
        Month,
    short
        Year)
{
    if (
        Month < 1 ||
        Month > 12)
        return 0;
    int
        days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (
               Month == 2)
               ? (isLeapYear(
                      Year)
                      ? 29
                      : 28)
               : days[Month - 1];
}
short
    NumberOfDaysFromTheBeginingOfTheYear(
        short
            Day,
        short
            Month,
        short
            Year)
{
    short
        TotalDays = 0;
    for (
        int
            i = 1;
        i <=
        Month - 1;
        i++)
    {
        TotalDays += NumberOfDaysInAMonth(i,
                                          Year);
    }
    TotalDays +=
        Day;
    return TotalDays;
}
short ReadDay()
{
    short
        Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short
        Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short
        Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
int main()
{
    short
        Day = ReadDay();
    short
        Month = ReadMonth();
    short
        Year = ReadYear();
   cout << "Number of days from the beginning of the year: " << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
}