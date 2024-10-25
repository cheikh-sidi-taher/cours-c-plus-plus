#include <iostream>
using namespace std;
int main()
{

    int m =1;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        m = m * i;
        i++;
    }
    cout << "The factorial of " << n << " is " << m << endl;
    return 0;
    
}