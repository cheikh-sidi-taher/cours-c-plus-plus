#include <iostream>
#include <string>
using namespace std;



float ReaddNumberOfHours(string Message){

    float  Hours;
    do
    {
        cout << Message << endl;
        cin >> Hours;
    } while (Hours < 0);
    return Hours;
}


float NumberOfDays(float Hours){
    float Days = Hours / 24;
    return (float)Days;
}

float NumberOfWeeks(float Hours){
    float Weeks = Hours / 168;
    return (float)Weeks;
}


int main()
{
    float Hours = ReaddNumberOfHours("Enter the possible number of hours: ");
    float Days = NumberOfDays(Hours);
    float Weeks = NumberOfWeeks(Hours);
    cout << Weeks << " " << "Weeks" << endl;
    cout << Days << " " << "Days" << endl;
    return 0;
}