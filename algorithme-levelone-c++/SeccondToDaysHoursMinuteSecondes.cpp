#include <iostream>
#include  <cmath>
using namespace std;

struct  stNumberOfSecondes
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPossitvieNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < 0);
    return Number;
}




stNumberOfSecondes SecondTotalTasDuration(int TotalSecondes){
    stNumberOfSecondes TaskDuration;
    const int SecondsInDay = 24 * 60 * 60;
    const int SecondsInHour = 60 * 60;
    const int SecondsInMinute = 60;

    int Remainder = 0;
    TaskDuration.NumberOfDays = floor(TotalSecondes / SecondsInDay);
    Remainder = TotalSecondes % SecondsInDay;
    TaskDuration.NumberOfHours = floor(Remainder / SecondsInHour);
    Remainder = Remainder % SecondsInHour;
    TaskDuration.NumberOfMinutes = floor(Remainder / SecondsInMinute);
    Remainder = Remainder % SecondsInMinute;
    TaskDuration.NumberOfSeconds = Remainder;
    return TaskDuration;
}


int main(){

    int TotalSecondes = ReadPossitvieNumber("Enter the total secondes: ");
    stNumberOfSecondes TaskDuration = SecondTotalTasDuration(TotalSecondes);
    cout << "Number of days: " << TaskDuration.NumberOfDays << endl;
    cout << "Number of hours: " << TaskDuration.NumberOfHours << endl;
    cout << "Number of minutes: " << TaskDuration.NumberOfMinutes << endl;
    cout << "Number of seconds: " << TaskDuration.NumberOfSeconds << endl;

    return 0;

}