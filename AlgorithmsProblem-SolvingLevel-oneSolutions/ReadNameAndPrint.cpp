#include <iostream>
using namespace std;

string ReadName()
{
    string name;
    cout << "Enter your Name:";
    getline(cin, name);
    return name;
};
void printName(string name)
{
    cout << "Your name is: " << name << endl;
}
int main()
{

    printName(ReadName());
    return 0;
}