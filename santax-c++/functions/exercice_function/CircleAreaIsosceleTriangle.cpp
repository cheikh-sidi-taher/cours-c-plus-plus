#include <iostream>
#include <cmath>
using namespace std;

double circleAreaIsosceleTriangle(double a, double b){
    double area = (M_PI * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
    return area;
}
int main()
{
   int a, b;
    cout << "Enter the length of one side (a): ";
    cin >> a;
    cout << "Enter the length of the other side (b): ";
    cin >> b;
    double area = circleAreaIsosceleTriangle(a, b);
    cout << "The area of the circle is: " << area << endl;
    return 0;
}