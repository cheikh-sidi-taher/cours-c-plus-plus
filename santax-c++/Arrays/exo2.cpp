#include <iostream>
using namespace std;

void readArrayGrades(float grades[3])
{
   cout << "Enter gredes by one: ";
   cin >> grades[0];
   cout << "Enter grades by two: ";
   cin >> grades[1];
   cout << "Enter grades by three: ";
   cin >> grades[2];
}




float averageGrades(float grades[3])
{
   return (grades[0] + grades[1] + grades[2]) / 3;
}

int main()
{
   float grades[3];
   readArrayGrades(grades);
   cout << "The average is: " << averageGrades(grades);
   return 0;
}