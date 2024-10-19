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
    if(average >= 50){
        cout << average << endl;
        cout << "Pass" << endl;
    }else{
         cout << "Fail" << endl;
    }
    return 0;
}