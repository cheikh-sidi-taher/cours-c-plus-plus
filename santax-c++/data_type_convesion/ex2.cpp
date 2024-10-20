#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str = "123.456";

    // Convert string to ineger
    int num_int  = stoi(str);
    // Convert string to float
    float num_float = stof(str);
    // Convert string to double
    double num_double = stod(str);
    cout << num_int << endl;
    cout << num_float << endl;
    cout << num_double << endl; 
    return 0;
}
