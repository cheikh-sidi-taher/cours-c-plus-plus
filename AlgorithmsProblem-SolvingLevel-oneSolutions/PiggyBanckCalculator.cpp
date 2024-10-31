#include <iostream>
using namespace std;

struct stPiggyBanckCalculator
{
    int Penny; Nickel;Dime ;Quater;Doller;
};


stPiggyBanckCalculator ReadPiggyContent()
{
   stPiggyBanckCalculator PiggyBankContent;
   cout << "Please enter a Total Pennies";
   cin >> PiggyBankContent.Penny;
   cout << "Please enter a Total Nickels";
   cin >> PiggyBankContent.Nickel;
   cout << "Please enter a Total Dimes";
   cin >> PiggyBankContent.Dime;
   cout << "Please enter a Total Quaters";
   cin >> PiggyBankContent.Quater;
   cout << "Please enter a Total Dollers";
   cin >> PiggyBankContent.Doller;

   return PiggyBankContent;

   
}


int CalculateTotalPennies(stPiggyBanckCalculator PiggyBankContent)

{
    int TotalPennies = 0;

    TotalPennies = PiggyBankContent.Penny * 1 + PiggyBankContent.Nickel * 5 + PiggyBankContent.Dime * 10 + PiggyBankContent.Quater * 25 + PiggyBankContent.Doller * 100;  
    return TotalPennies;
}


int main()
{
    
   int  TotalPennies = CalculateTotalPennies(ReadPiggyContent());
    cout << "Total Pennies: " << TotalPennies << endl;
    cout << "Total Dollars: " << TotalPennies / 100 << endl;
    return 0;
}
