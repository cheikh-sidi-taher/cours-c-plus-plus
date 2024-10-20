#include <iostream>
using namespace std;
int main()
{
   int num1;
   double num2 = 18.99;
   num1 = num2; // Implicit conversion from double to int
   num1 = (int) num2; // Explicit conversion
   num1 = int (num2); // Explicit conversion
   cout << num1 << endl;
}