#include <iostream>
using namespace std;


float rectangleArea(float length, float width){
    return length * width;

}
int main()
{
    float length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    float area = rectangleArea(length, width);
    cout << "The area of the rectangle is: " << area << endl;
    return 0;
}
