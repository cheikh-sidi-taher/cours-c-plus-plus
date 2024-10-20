#include <iostream>
#include <cmath>
using namespace std;

int main(){
   double a, d;
    cout << "Enter the length of one side (a): ";
    cin >> a;
    cout << "Enter the length of the diagonal (d): ";
    cin >> d;
    double b = sqrt(pow(d, 2) - pow(a, 2));
    double area = a * b;
    cout << "The area of the rectangle is: " << area << endl;

    return 0;

    return 0;
    
}
