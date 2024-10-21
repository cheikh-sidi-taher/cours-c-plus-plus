#include <iostream>
using namespace std;


int mySumFUnction(int num1, int num2){
    return num1 + num2;
}
int main()
{
    int num1,num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;
    cout << "Sum = " << mySumFUnction(num1, num2) << "" << endl;
    
    return 0;
}