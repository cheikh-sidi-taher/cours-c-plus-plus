#include <iostream>
using namespace std;
int main()
{
    double days , hours , minutes , seconds;
    cout << "Enter the number of days: ";
    cin >> days;
    cout << "Enter the number of hours: ";
    cin >> hours;  
    cout << "Enter the number of minutes: ";    
    cin >> minutes;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    if(days >= 0 && hours >= 0 && minutes >= 0 && seconds >= 0){
    days = days * 24 * 60 * 60;
    hours = hours * 60 * 60;
    minutes = minutes * 60;
    double total = days + hours + minutes + seconds;
    cout << total << " " << "seconds" << endl;
    }else{
        cout << "The number of days, hours, minutes and seconds are negatif: ";
    }
    return 0;
}