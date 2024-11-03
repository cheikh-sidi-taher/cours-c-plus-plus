#include <iostream>
using namespace std;



struct  stTaskDuration
{
    int NumberOfDays; NumberOHours; NumberOfMinutes; NumberOfSeconds;
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





stTaskDuration ReadTaskDuration()
{
    stTaskDuration TaskDuration;
    TaskDuration.NumberOfDays = ReadPossitvieNumber("Enter the number of days: ");
    TaskDuration.NumberOfHours = ReadPossitvieNumber("Enter the number of hours: ");
    TaskDuration.NumberOfMinutes = ReadPossitvieNumber("Enter the number of minutes: ");
    TaskDuration.NumberOfSeconds = ReadPossitvieNumber("Enter the number of seconds: ");
    return TaskDuration;
}


int TaskDurationInSecond(stTaskDuration TaskDuration)
{
   int DurationInSecond = 0;
   DurationInSecond = TaskDuration.NumberOfDays * 24 * 60 * 60;
   DurationInSecond += TaskDuration.NumberOfHours * 60 * 60;
   DurationInSecond += TaskDuration.NumberOfMinutes * 60;
   DurationInSecond += TaskDuration.NumberOfSeconds;
   return DurationInSecond; 
}   

int main()
{
    cout << "\nTask duration in second : " << TaskDurationInSecond(ReadTaskDuration()) << endl;
    cout << endl;
    return 0;
}