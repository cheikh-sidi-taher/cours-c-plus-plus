#include <iostream>
using namespace std;

void ReadNUmber(float& a ,float& h){
    cout << "Please enter your number 1 ? " << endl;
    cin >> a;
    cout << "Please enter your number 2 ? " << endl;
    cin >> h;
}

float TrinagleArea(float a, float h){
    float area = (a / 2) * h;
    return area;
}

void PrintResult(float area){
    cout << "The area of the trinagle is: " << area << endl;
}


int main(){
    float a, h;
    ReadNUmber(a, h);
    PrintResult(TrinagleArea(a, h));
    return 0;
}