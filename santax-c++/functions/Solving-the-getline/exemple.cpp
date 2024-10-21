#include <iostream>
using namespace std;

int main()
{
    int Number;
    string Name;
    string Country;

    cout << "Please enter your number?\n ";
    cin >> Number;
    cout << "Please enter your name?\n ";
    cin.ignore(1,'\n');
    getline(cin, Name);
    cout << "Please enter your country?\n ";
    cin >> Country;
   

}