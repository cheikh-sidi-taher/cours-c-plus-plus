#include <iostream>
using namespace std;


double trinangleArea(double a, double h){
    double area = (a * h) / 2;
    return area;
}
int main()
{
    int a, h;
    cout << "Enter the length of the base (a): ";
    cin >> a;
    cout << "Enter the height (h): ";
    cin >> h;
    double area = trinangleArea(a, h);
    cout << "The area of the trinangle is: " << area << endl;
    return 0;
}