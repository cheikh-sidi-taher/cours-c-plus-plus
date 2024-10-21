#include <iostream>
using namespace std;


 int addNumber(){
        int a , b;
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        return a + b;
    }
int main()
{
   int result;
   result = addNumber();
   cout << "Result = " << result << endl;
   return 0;
}