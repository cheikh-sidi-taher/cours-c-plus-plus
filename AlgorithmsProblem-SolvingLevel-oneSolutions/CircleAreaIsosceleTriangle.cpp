#include <iostream>
#include <cmath>
using namespace std;



void ReadCircleAreaIsosceleTriangle(float& a, float& b){
    cout << "Please enter triangle side A ? " << endl;
    cin >> a;
    cout << "Please enter triangle side B ? " << endl;
    cin >> b;
    
}


float CircleAreaIsosceleTriangle(float a, float b){
    float area = M_PI * (pow(b, 2) / 4) * (2 * a - b) / (2 * a + b);
    return area;
}


void PrintResult(float area){
    cout << "The area of the circle is: " << area << endl;
}



int main(){
    float a, b;
    ReadCircleAreaIsosceleTriangle(a, b);
    float area = CircleAreaIsosceleTriangle(a, b);
    PrintResult(area);
    return 0;

}