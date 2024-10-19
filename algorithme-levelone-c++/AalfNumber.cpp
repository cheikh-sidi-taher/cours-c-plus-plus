#include <iostream>
using namespace std;

int main(){
    int number , halfNumber;
    cout << "Enter a number: ";
    cin >> number;
    halfNumber = number / 2;
    if(halfNumber > 0){
        cout  << "The half number of " << number << " is " << halfNumber << endl;
    }else{
        cout << "The half number of  is negative number" << endl;
    }
    return 0;
}
