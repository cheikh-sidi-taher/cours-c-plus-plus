#include <iostream>
using namespace std;

int main(){
    int number_one, number_two;
    cout << "Enter the first number: ";
    cin >> number_one;
    cout << "Enter the second number: ";
    cin >> number_two;
    if(number_one > number_two){
        cout << "The maximum number is: " << number_one << endl;
    }else{
        cout << "The maximum number is: " << number_two << endl;
    }
    return 0;
}