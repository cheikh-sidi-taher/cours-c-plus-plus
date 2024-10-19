#include <iostream>
using namespace std;
int main()
{
    const float p = 3.14;
    float A , Area;
    cout << "Enter D: ";
    cin >> A;
    Area = (p * A * A)/4;
    cout << "The area intcribed of the circle is: " << Area << endl;
    return 0;
}