#include <iostream>
using namespace std;

int main()
{
    char caracters[6] = {'A','B','C','D','E','F'};
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 0; j< i; j++)
        {
            cout << caracters[j];  
        }
        cout << "\n";
    }

    return 0;
}
