#include <iostream>
using namespace std;

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a month to check? ";
    cin >> Month;
    return Month;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a day to check? ";
    cin >> Day;
    return Day;
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

string NameOfDyes(short Day)
{
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return Days[Day];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << Day << "/ " << Month << " /" << Year << endl;
    cout << "Day of order : " << DayOfWeekOrder(Day, Month, Year) << endl;
    cout << "Day of name : " << NameOfDyes(DayOfWeekOrder(Day, Month, Year)) << endl;
    system("pause>0");
    return 0;
}
