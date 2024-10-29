#include <iostream>
#include <cmath>
using namespace std;



float ReadNumber(){
    float radius;
    cout << "Enter the radius of the circle: " << endl;
    cin >> radius;
    return radius;
}
float CircleArea(float radius){
    float area = M_PI * pow(radius, 2);
    return area;
}

void PrintResult(float area){
    cout << "The area of the circle is: " << area << endl;
}


int main(){
    PrintResult(CircleArea(ReadNumber()));
    return 0;
}