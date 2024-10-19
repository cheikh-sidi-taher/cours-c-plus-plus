#include <iostream>
using namespace std;


int main(){
    int mark_one, mark_two, mark_three;
    cout << "Enter the first mark: ";
    cin >> mark_one;
    cout << "Enter the second mark: ";
    cin >> mark_two;
    cout << "Enter the third mark: ";
    cin >> mark_three;
    int average = (mark_one + mark_two + mark_three) / 3;
    cout << "The average of the three marks is: " << average << endl;
    return 0;
}