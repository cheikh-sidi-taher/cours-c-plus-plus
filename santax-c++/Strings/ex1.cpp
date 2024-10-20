#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string MyString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The list of characters in MyString is: " << MyString.length() << endl;

    string S1 = "10", S2 = "20";
    string S3 = S1 + S2;
    cout << "S3 = " << S3 << endl;

    int Sum = stoi(S1) + stoi(S2);
    cout << "Sum = " << Sum << endl;
    return 0;
}