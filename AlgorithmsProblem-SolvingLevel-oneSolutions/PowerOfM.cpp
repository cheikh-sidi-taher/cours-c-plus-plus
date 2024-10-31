#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(int &N, int &M)
{
    cout << "Please enter N: " << endl;
    cin >> N;
    cout << "Please enter M: " << endl;
    cin >> M;
}

int PowerOfM(int N, int M)
{
    return pow(N, M);
}

void PrintPower(int power)
{
    cout << "Power: " << power << endl;
}

int main()
{
    int N, M;
    ReadNumber(N, M);
    PrintPower(PowerOfM(N, M));
    return 0;
}