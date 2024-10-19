#include <iostream>
using namespace std;
int main()
{
    const float p = 3.14;
    float L ,area;
    cout << "Enter L: ";
    cin >> L;
    area = (L*L)/(4*p);
    cout << "The area of the circle is: " << area << endl;

    return 0;
}