#include <iostream>
#include <string>
#include <limits> // pour std::numeric_limits
using namespace std;


// Function to check if a year is a leap year
bool isLeapYear(short year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
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

// Function to calculate the number of hours in a month
short NumberOfHoursInMonth(short year, short month){
    return NumberOfDaysInMonth(year, month) * 24;
}


// Function to calculate the number of minutes in a month
int NumberOfMinutesInMonth(short year, short month){
    
    return NumberOfHoursInMonth(year, month) * 60;
}
// Function to calculate the number of seconds in a month
int NumberOfSecondsInMonth(short year, short month){
    
    return NumberOfMinutesInMonth(year, month) * 60;
}


// Function to read a positive integer
short ReadPositiveNumber(){
    short Number;
    while (true) {
        cin >> Number;
        // Check if the input is a positive integer
        if (cin.fail() || Number < 0) {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return Number;
        }
    }
}


// Function to read the number of years
short ReadYears(){
   cout << "Enter the number of years: ";
   return ReadPositiveNumber();
}


// Function to read the number of months
short ReadMonths(){
   cout << "Enter the number of months: ";
   return ReadPositiveNumber();
}
int main(){

    // Read the number of years and months
    short Years = ReadYears();
    short Months = ReadMonths(); 
    // Calculate the number of days, hours, minutes, and seconds
    cout << NumberOfDaysInMonth(Years, Months) << " days\n";
    cout << NumberOfHoursInMonth(Years, Months) << " hours\n";
    cout << NumberOfMinutesInMonth(Years, Months) << " minutes\n";
    cout << NumberOfSecondsInMonth(Years, Months) << " seconds\n";
   

    return 0;
}
