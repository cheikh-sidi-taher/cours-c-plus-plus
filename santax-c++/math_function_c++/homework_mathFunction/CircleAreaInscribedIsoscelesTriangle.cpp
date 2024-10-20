#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b;
    cout << "Enter (a): ";
    cin >> a;
    cout << "Enter(b): ";
    cin >> b;
    double area = (M_PI * pow(b, 2) / 4 ) * ((2*a-b)/ (2*a+b));
    cout << "The area of the circle is: " << round(area) << endl;
    return 0;
}