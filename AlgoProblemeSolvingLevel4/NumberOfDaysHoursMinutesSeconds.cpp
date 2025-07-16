#include <iostream>
using namespace std;


bool isLeapYear(int year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


short NumberOfDays(int year){
    return isLeapYear(year) ? 366 : 365;
}

short NumberOfHours(int year){
    return NumberOfDays(year) * 24;
}

int  NumberOfMinutes(int year){
    return NumberOfHours(year) * 60;
}

int NumberOfSeconds(int year){
    return NumberOfMinutes(year) * 60;
}

short ReadYear(){
    short year;
    cout << "Enter a year: ";
    cin >> year;
    return year;
}

int main(){
     short year = ReadYear();
    cout << "There are " << NumberOfDays(year) << " days in " << year << endl;
    cout << "There are " << NumberOfHours(year) << " hours in " << year << endl;
    cout << "There are " << NumberOfMinutes(year) << " minutes in " << year << endl;
    cout << "There are " << NumberOfSeconds(year) << " seconds in " << year << endl;
    return 0;
}