#include <iostream>
using namespace std;
int main()
{
    float billValue ,service , salTax;
    cout << "Enter your BillValue";
    cin >> billValue;
    if(billValue>0){
    service = (100 * 0.1);
    salTax = (100 * 0.16);
    float totalBill = billValue + service + salTax;
    cout << "The totalBill is :" << totalBill << endl ;
    }else{
       cout << "The billValue  is negatif:";
    }
    
} 