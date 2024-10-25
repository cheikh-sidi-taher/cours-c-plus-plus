#include <iostream>
using namespace std;

int readIntNumberInRange(int form, int to){
    int number;
    cout << "Please enter a number between " << form << " and " << to << "\n: ";
    cin >> number;
    while (number < form || number > to)
    {
        cout << "Wrong number" << endl;
        cout << "Please enter a number between " << form << " and " << to << "\n: ";
        cin >> number;
    }
    return number;
}
int main()
{
    int number = readIntNumberInRange(1, 10);
    cout << "The number is " << number << endl;
}