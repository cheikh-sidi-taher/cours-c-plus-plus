#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, d;
    cout << "Enter the length of one side (a): ";
    cin >> a;
    cout << "Enter the length of the diagonal (d): ";
    cin >> d;
    double b = sqrt(d * d - a * a);
    double area = a * b;
    cout << "The length of the other side (b) is: " << b << endl;
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
