#include <iostream>
using namespace std;
int main()
{

    int sum = 0;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        i++;
    }
    cout << "The sum of even numbers from 1 to " << n << " is " << sum << endl;
    return 0;
}
   