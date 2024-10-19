#include <iostream>
using namespace std;
int main()
{
    float Pennies, Nickels, Dimes, Quarters, Dollars;
    cout << "Enter the amount of money in pennies: ";
    cin >> Pennies;
    cout << "Enter the amount of money in nickels: ";
    cin >> Nickels;
    cout << "Enter the amount of money in dimes: ";
    cin >> Dimes;
    cout << "Enter the amount of money in quarters: ";
    cin >> Quarters;
    cout << "Enter the amount of money in dollars: ";
    cin >> Dollars;

    Pennies =   Pennies + Nickels * 5 + Dimes * 10 + Quarters * 25 + Dollars * 100;
    Dollars = Pennies / 100;

    cout << Pennies << " " << "Pennies" << endl;
    cout << Dollars << " " <<  "Dollars"  << endl;
  
    return 0;
}