#include <iostream>
using namespace std;


void ReadNUmbers(float& length, float& width)   
{
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
}


float RectangleArea(float& length, float& width)
{   
    return length * width;
}

void printRectangleArea(float area){
    cout << "The area of the rectangle is: " << area << endl;
}


int main()
{
    float length, width;
    ReadNUmbers(length, width);
    printRectangleArea(RectangleArea(length, width));
    return 0;
}