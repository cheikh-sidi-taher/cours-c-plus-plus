#include <iostream>
#include <cmath>
using namespace std;

float circleAreaDiameter(float diameter) {
    float area = M_PI * pow(diameter, 2) / 4;
    return area;
}

int main()
{
    float diameter;
    cout << "Enter the diameter of the circle: ";
    cin >> diameter;
    float area = circleAreaDiameter(diameter);
    cout << "The area of the circle is: " << area << endl;
    return 0;
}