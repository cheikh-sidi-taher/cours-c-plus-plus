#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;
    int fact = 1;
    for (int i = 1; i <= N; i++) {
        fact = fact * i;
    }
    cout << "The factorial of " << N << " is " << fact << endl;
    return 0;
}