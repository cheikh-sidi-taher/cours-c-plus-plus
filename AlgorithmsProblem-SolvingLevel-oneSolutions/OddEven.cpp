#include <iostream>
using namespace std;

enum enNumberType {
    Odd = 1,
    Even = 2
};

int ReadNumber() {
    int Number;
    cout << "Enter a number: ";
    cin >> Number;
    return Number;
}

enNumberType checkNumberType(int Number) {
    if (Number % 2 == 0) {
        return enNumberType::Even;
    } else {
        return enNumberType::Odd;
    }
}
    

void printNumberType(enNumberType NumberType) {
   if (NumberType == enNumberType::Even) {
        cout << "The number is even" << endl;
    } else {
        cout << "The number is odd" << endl;
    }
}


int main() {
   printNumberType(checkNumberType(ReadNumber()));
   return 0;
}