#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double d;
    cout << "Enter the diameter of the circle: ";
    cin >> d;
    double area = M_PI * pow(d, 2) /4;
    cout << "The area of the circle is: " << ceil(area) << endl;
    return 0;
}