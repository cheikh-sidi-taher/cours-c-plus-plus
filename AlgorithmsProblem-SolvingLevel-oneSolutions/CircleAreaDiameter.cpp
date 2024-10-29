#include <iostream>
#include <cmath>
using namespace std;


float ReadNumber(){
    float D;
    cout << "Enter the D of the circle: ";
    cin >> D;
    return D;
}


float  CircleAreaDiameter(float diameter) {
    float area = (M_PI * pow(diameter, 2)) / 4;
    return area;
}

void PrintResult(float area){
    cout << "The area of the circle is: " << area << endl;
}


int main() {

    PrintResult(CircleAreaDiameter(ReadNumber()));
}
