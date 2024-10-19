#include <iostream>
using namespace std;

int main(){
    float totalBill, cachPaid;
    cout << "Enter total bill: ";
    cin >> totalBill;
    cout << "Enter cash paid: ";
    cin >> cachPaid;
    float res = cachPaid - totalBill;
    cout << "res is: " << res << endl;
    return 0;
    
}