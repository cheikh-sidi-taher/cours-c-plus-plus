#include <iostream>
using namespace std;

int main(){
short Age;
    cout << "Enter your age: ";
    cin >> Age;
    if (Age >= 18 && Age <= 45){
        cout << "Valid Age" << endl;
    }else{
        cout << "Invalid Age" << endl;
    }
    return 0;
}