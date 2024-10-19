#include <iostream>
using namespace std;

int main()
{

    int A = 10, B = 20;

    A += B;
    cout << "A = " << A << endl; // = 30

    A -= B;
    cout << "A = " << A << endl; // = 10

    A *= B;
    cout << "A = " << A << endl; // 200

    A /= B;
    cout << "A = " << A << endl;  // 10 

    A %= B;
    cout << "A = " << A << endl;  // 10
}