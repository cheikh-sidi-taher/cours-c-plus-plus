#include <iostream>
using namespace std;
int main()
{
    const float pi = 3.14;
    float a,b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    float x= (pi*b*b/4)*(2*b-a)/(2*b+a);
    cout << "The area is: " << x << endl;
    return 0;
}