#include <iostream>
using namespace std;


enum enDayOfWeek
{
    Sat = 1,
    Sun =2,
    Mon =3,
    Tue =4,
    Wed =5,
    Thu =6,
    Fri =7
};


int ReadNumberInRange(string Message, int From, int To)
{
    int Number =0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}


enum enDayOfWeek ReadDayOfWeek()
{ 
    return (enDayOfWeek) ReadNumberInRange("Please enter a number between 1 to 7", 1, 7);
}


string GetDayOfWeekName(enDayOfWeek Day){

    switch (Day)
  {
    case enDayOfWeek::Sat:
      return "Saturday";
      break;
    case enDayOfWeek::Sun:
      return "Sunday";
      break;
    case enDayOfWeek::Mon:
      return "Monday";
      break;
    case enDayOfWeek::Tue:
      return "Tuesday";
      break;
    case enDayOfWeek::Wed:
      return "Wednesday";
      break;
    case enDayOfWeek::Thu:
      return "Thursday";
      break;
    case enDayOfWeek::Fri:
      return "Friday";
      break;
    default:
      return "Invalid Day";
      break;
  }



  
}


int main ()
  {
    cout << GetDayOfWeekName(ReadDayOfWeek()) << endl;
    return 0;
  }