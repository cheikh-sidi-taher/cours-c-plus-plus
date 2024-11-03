#include <iostream>
#include <cmath>
using namespace std;

enum enMothOfYear
{
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Aug = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12
};

int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

enMothOfYear ReadMothOfYear()
{
    return enMothOfYear(ReadNumberInRange("Plase Enter the month: ", 1, 12));
}

string GetMonthOfYear(enMothOfYear Month)
{
    switch (Month)
    {
    case enMothOfYear::Jan:
        return "January";
    case enMothOfYear::Feb:
        return "February";
    case enMothOfYear::Mar:
        return "March";
    case enMothOfYear::Apr:
        return "April";
    case enMothOfYear::May:
        return "May";
    case enMothOfYear::Jun:
        return "June";
    case enMothOfYear::Jul:
        return "July";
    case enMothOfYear::Aug:
        return "August";
    case enMothOfYear::Sep:
        return "September";
    case enMothOfYear::Oct:
        return "October";
    case enMothOfYear::Nov:
        return "November";
    case enMothOfYear::Dec:
        return "December";
    default:
        return "Invalid Month";
        break;
    }
}

int main()
{
    cout << GetMonthOfYear(ReadMothOfYear()) << endl;
    return 0;
}
