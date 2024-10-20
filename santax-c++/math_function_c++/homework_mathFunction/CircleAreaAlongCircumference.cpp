#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double circumference;
    cout << "Enter the circumference of the circle: ";
    cin >> circumference;
    double area = pow(circumference, 2) / (4 * M_PI);
    cout << "The area of the circle is: " << floor(area) << endl;
    return 0;
}