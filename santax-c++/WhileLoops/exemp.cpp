#include <iostream>

using namespace std;


int main(){


    int Number;
    cout << "Please enter  a positive number?\n: ";
    cin >> Number;

    while (Number < 0)
    {
        cout << "Please enter a positive number?\n: ";
        cin >> Number;
    }

    cout << "The number is " << Number << endl;

    return 0;
    
}