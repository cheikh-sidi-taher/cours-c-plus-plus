
#include <iostream>
#include <cmath>
using namespace std;   

double circleCircumference(double l){
    double area = pow(l, 2)  / (4 * M_PI);
    return area;
}

int main()
{
    double l;
    cout << "Enter the length of the circumference: ";
    cin >> l;
    double area = circleCircumference(l);
    cout << "The area of the circle is: " << area << endl;
    return 0;
}
