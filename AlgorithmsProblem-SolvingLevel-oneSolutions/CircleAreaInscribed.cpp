#include <iostream>
#include <cmath>
using namespace std;

float ReadSquareSide()
{
    float A;
    cout << "Enter the A of the circle: ";
    cin >> A;
    return A;
}

float CircleAreaInscribed(float A)
{
    float area = (M_PI * pow(A, 2)) / 4;
    return area;
}

void PrintResult(float area)
{
    cout << "The area of the circle is: " << area << endl;
}

int main()
{

    PrintResult(CircleAreaInscribed(ReadSquareSide()));
    return 0;
}
