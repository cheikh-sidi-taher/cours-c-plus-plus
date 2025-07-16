
#include <iostream>
#include <string>
#include <limits> // pour std::numeric_limits
using namespace std;



// Function to calculate the day of the week
short DayOfWeekOrder(
    short
        Day,
    short
        Month,
    short
        Year)
{
    short
        a,
        y, m;
    a = (14 -
         Month) /
        12;
    y =
        Year - a;
    m =
        Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (
               Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) %
           7;
}

// Function to get the short name of the day
string
DayShortName(
    short
        DayOfWeekOrder)
{
    string
        arrDayNames[] = {
            "Sun",
            "Mon",
            "Tue",
            "Wed",
            "Thu",
            "Fri",
            "Sat"};
    return arrDayNames[DayOfWeekOrder];
}
short ReadPositiveNumber()
{
    short Number;
    while (true)
    {
        cin >> Number;
        // Check if the input is a positive integer
        if (cin.fail() || Number < 0)
        {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Number;
        }
    }
}

// Function to read the number of years
short ReadYears()
{
    cout << "Enter the number of years: ";
    return ReadPositiveNumber();
}

// Function to read the number of months
short ReadMonths()
{
    cout << "Enter the number of months: ";
    return ReadPositiveNumber();
}

short ReadDays()
{
    cout << "Enter the number of days: ";
    return ReadPositiveNumber();
}
int main()
{

    // Read the number of years and months
    short Years = ReadYears();
    short Months = ReadMonths();
    short Days = ReadDays();

    cout << "The date is: " << Days << "/" << Months << "/" << Years << "/" << endl;
    cout << " Day Order: " << DayOfWeekOrder(Days, Months, Years) << endl;
    cout << " Day Name: " << DayShortName(DayOfWeekOrder(Days, Months, Years)) << endl;
    return 0;
}
