#include <iostream>
using namespace std;
int main(){
    int number_one, number_two, number_three;
    cout << "Enter the first number: ";
    cin >> number_one;
    cout << "Enter the second number: ";
    cin >> number_two;
    cout << "Enter the third number: ";
    cin >> number_three;
    if(number_one > number_two && number_one > number_three){
        cout << "The maximum number is: " << number_one << endl;
    }else if(number_two > number_one && number_two > number_three){
        cout << "The maximum number is: " << number_two << endl;
    }else{
        cout << "The maximum number is: " << number_three << endl;
    }
    return 0;

}