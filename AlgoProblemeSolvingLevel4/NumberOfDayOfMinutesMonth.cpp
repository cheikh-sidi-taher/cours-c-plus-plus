#include <iostream>
using namespace std;
bool isLeapYear(short Year)
{
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short NumberOfDaysInAMonth(short Month, short Year)
{
    if(Month < 1 || Month > 12){
        return 0;
    }
    if(Month == 2){
        return isLeapYear(Year) ? 29 : 28;
    }
    if(Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12){
        return 31;
    }
    return 30;
}


short NumberOfHoursInAMonth(short Month, short Year)
{
return NumberOfDaysInAMonth(Month, Year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short Year)
{
return NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year)
{
return NumberOfMinutesInAMonth(Month, Year) * 60;
}







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
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

int main(){

   short Year = ReadYear();
   short Month = ReadMonth();
   cout << "\nNumber of Days in Month [" << Month << "] is "
         << NumberOfDaysInAMonth(Month, Year);
    cout << "\nNumber of Hours in Month [" << Month << "] is "
         << NumberOfHoursInAMonth(Month, Year);
    cout << "\nNumber of Minutes in Month [" << Month << "] is "
         << NumberOfMinutesInAMonth(Month, Year);
    cout << "\nNumber of Seconds in Month [" << Month << "] is "
         << NumberOfSecondsInAMonth(Month, Year);
    system("pause>0");
    return 0;
   

}