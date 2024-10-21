#include <iostream>
#include <cmath>
using namespace std;

void getPower(int number){
    cout << "Power of the number is: " << round(pow(number,2)) << endl; 
    cout << "Power of the number is: " << round(pow(number,3)) << endl;
    cout << "Power of the number is " <<  round(pow(number,4)) << endl;
}
int main()
{

    int number;
    cout << "Enter the number: ";
    cin >> number;
    getPower(number);

    
    return 0;
}