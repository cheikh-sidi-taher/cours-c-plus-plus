#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    double area = M_PI * pow(r, 2);
    cout << "The area of the circle is: " << ceil(area) << endl;
    return 0;
}