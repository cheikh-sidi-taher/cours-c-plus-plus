#include <iostream>
#include <string>
using namespace std;    

int main()
{
   int num1 = 123;
   double num2 = 18.99;
   
   string St1 , St2;
   St1 = to_string(num1);
   St2 = to_string(num2);
   cout << St1 << endl;
   cout << St2 << endl;
    return 0;
}