#include <iostream>
using namespace std;
int main()
{
    int numberOfHours, numberOfDays, numberofWeeks;
    cout << "Enter the number of hours: ";
    cin >> numberOfHours;
    if (numberOfHours > 0)
    {
        numberofWeeks = numberOfHours / 168;
        numberOfDays = numberOfHours / 24;
        cout << numberofWeeks << " " << "Weeks" << endl;
        cout << numberOfDays << " " << "Days" << endl;
    }
    else
    {
        cout << "The number of hours is negatif: ";
    }
    return 0;
}