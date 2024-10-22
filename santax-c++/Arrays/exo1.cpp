#include <iostream>
using namespace std;

int main() {
    int grades[3];
    cout << "Enter  numbers  by one: ";
    cin >> grades[0];
    cout << "Enter  numbers  by two: ";
    cin >> grades[1];
    cout << "Enter  numbers  by three: ";
    cin >> grades[2];
    double avg = (grades[0] + grades[1] + grades[2]) / 3;
    cout << "The average is: " << avg;
    return 0;
}