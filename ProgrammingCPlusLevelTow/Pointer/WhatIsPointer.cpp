#include <iostream>
using namespace std;
int main()
{
   int arr[4] = {10, 20, 30, 40};
   int *ptr;
   for(int i = 0; i < 4; i++)
   {
       ptr = &arr[i];
       cout << *ptr << " ";
   }
   cout << "\n";
}