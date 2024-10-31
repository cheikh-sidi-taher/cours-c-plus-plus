#include <iostream>
#include <cmath>
using namespace std;

float ReadCircleCircumference(){
    float L;
    cout << "Please enter Circumference: ";
    cin >> L;
    return L;
}


float CircleAreaByCircumference(float L){
    float Area = pow(L, 2)/(4*M_PI);
    return Area;
}

void PrintResult(float area){
    cout << "The area of the circle is: " << area << endl;
}


int main(){
    PrintResult(CircleAreaByCircumference(ReadCircleCircumference()));
    return 0;
}