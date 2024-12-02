#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::out); // Write Mode
    if (MyFile.is_open())
    {
        MyFile << "Hi, cheikh sidi taher\n";
        MyFile << "Hi, cheikh sidi taher\n";
        MyFile << "Hi, cheikh sidi taher\n";
        MyFile.close();
    }
    return 0;
}