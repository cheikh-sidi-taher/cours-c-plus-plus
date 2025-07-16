
#include <iostream>
#include <string>
#include <limits> 
#include <iomanip>
using namespace std;


bool isLeapYear(short year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


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

// Function to calculate the number of days in a month
short NumberOfDaysInMonth(short year, short month){
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}
string MonthShortName(short month){
    string
        arrMonthNames[] = {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"};
    return arrMonthNames[month - 1];
}


void PrintMonthCalendar(short year, short month) {
    cout << "\n-------------"<< MonthShortName(month).c_str() << " " << year << "--------\n";
    cout << "Sun Mon Tue Wed Thu Fri Sat\n";

    short firstDay = DayOfWeekOrder(1, month, year);
    short totalDays = NumberOfDaysInMonth(year, month);

    // Espace vide avant le 1er jour
    for (short i = 0; i < firstDay; i++) {
        cout << "    ";
    }

    // Affichage des jours
    for (short day = 1; day <= totalDays; day++) {
        cout << setw(3) << day << " ";
        if ((firstDay + day) % 7 == 0)
            cout << endl;
    }
    cout << endl;

    cout << "----------------------------\n";
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


int main()
{

    // Read the number of years and months
    short Years = ReadYears();
    short Months = ReadMonths();

    PrintMonthCalendar(Years, Months);
    cout << endl;
    return 0;
    
   
   
}
