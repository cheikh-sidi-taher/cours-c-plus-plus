#include <iostream>
#include <cmath>
using namespace std;

double circleArea(double A)
{
    double area = M_PI * pow(A, 2) / 4;
    return area;
}
int main()
{
   cout << "Enter the A of the circle: ";
   double A;
   cin >> A;
   double area = circleArea(A);
   cout << "The area of the circle is: " << area << endl;
   return 0;
}