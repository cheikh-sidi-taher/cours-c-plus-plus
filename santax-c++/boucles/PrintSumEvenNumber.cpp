#include <iostream>
using namespace std;

int main()
{
   int n;
   int sum = 0;
   cout << "Enter a number: ";
   cin >> n;
   for (int i = 1; i <= n; i++) {
       if (i % 2 == 0) {
           sum += i;
       }
   }
   cout << "The sum of even numbers from 1 to " << n << " is " << sum << endl;
   return 0;
}