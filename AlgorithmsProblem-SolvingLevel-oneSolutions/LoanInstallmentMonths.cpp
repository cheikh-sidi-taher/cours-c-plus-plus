#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}



float ToatalMonths(float LoanAmount, float MonthsPayment){
    return (float) LoanAmount / MonthsPayment;
   




int main()
{
  float LoanAmount = ReadPositiveNumber("Please enter the loan amount: ");
  float MonthsPayment = ReadPositiveNumber("Please enter the months payment: ");
  cout << "The loan installment months is: " <<  ToatalMonths(LoanAmount, MonthsPayment) << endl; //ToatalMonths(LoanAmount, MonthsPayment) << endl;
  return 0;
}

