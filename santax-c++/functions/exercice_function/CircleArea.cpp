#include <iostream>
#include <cmath>
using namespace std;

double circleArea(double radius) {
    return pow(radius, 2) * M_PI;
}
int main()
{
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    double area = circleArea(radius);
    cout << "The area of the circle is: " << area << endl;
    return 0;
}