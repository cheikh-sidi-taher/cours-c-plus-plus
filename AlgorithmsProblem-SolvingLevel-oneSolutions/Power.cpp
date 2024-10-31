#include <iostream>
using namespace std;


int ReadNumber(){
    int N;
    cout << "Please enter a number: " << endl;
    cin >> N;
    return N;
}


void PowerOf2_3_4(int number){
    int a, b, c;
    a = number * number;
    b = number * number * number;
    c = number * number * number * number;
    cout << "Power of 2: " << a << endl;
    cout << "Power of 3: " << b << endl;
    cout << "Power of 4: " << c << endl;
}



int main(){
    PowerOf2_3_4(ReadNumber());
    return 0;
}