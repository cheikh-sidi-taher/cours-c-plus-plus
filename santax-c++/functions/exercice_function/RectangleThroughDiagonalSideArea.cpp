#include <iostream>
#include <cmath>
using namespace std;    


float rectangleAreaDiagonal(float a, float d){
    double b = sqrt(d * d - a * a);
    double area = a * b;
    return area;
}
int main() {
    double a, d;
    cout << "Enter the length of one side (a): ";
    cin >> a;
    cout << "Enter the length of the diagonal (d): ";
    cin >> d;
    rectangleAreaDiagonal(a,d);
    cout << "The length of the other side (b) is: " << rectangleAreaDiagonal(a,d) << endl;

    rectangleAreaDiagonal(5,10);

    cout << "The length of the other side (b) is: " << rectangleAreaDiagonal(5,10) << endl;
}