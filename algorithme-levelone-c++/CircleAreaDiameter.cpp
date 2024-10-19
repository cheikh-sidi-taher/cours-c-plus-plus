#include <iostream>
using namespace std;

int main(){
    float D ,Area;
    float P = 3.14;

    cout << "Enter the diameter of the circle: ";
    cin >> D;
    Area = P * (D * D)/4;
    cout << "The area of the circle is: " << Area << endl;
    return 0;
}