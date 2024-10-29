#include <iostream>
#include <cmath>

using namespace std;

void  ReadNUmber(float& a ,float& d){
    cout << "Please enter your number 1 ? " << endl;
    cin >> a;
    cout << "Please enter your number 2 ? " << endl;
    cin >> d;
}

float RectangleAreaDiagonal(float a, float d){
    float area = a * sqrt (pow(d, 2) - pow(a, 2));
    return area;
}

void PrintResult(float area){
    cout << "The area of the rectangle is: " << area << endl;
}

int main(){
   float a, d;
   ReadNUmber(a, d);
   PrintResult(RectangleAreaDiagonal(a, d));
}
