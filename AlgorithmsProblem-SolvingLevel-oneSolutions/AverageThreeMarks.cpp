#include <iostream>
using namespace std;


void ReadThreeNumber(int& mark1, int& mark2, int& mark3)
{
    cout << "Please enter your mark 1 ? " << endl;
    cin >> mark1;
    cout << "Please enter your mark2 ? " << endl;
    cin >> mark2;
    cout << "Please enter your mark 3 ? " << endl;
    cin >> mark3;
}


float averageMark(int mark1, int mark2, int mark3)
{
    return (float)(mark1 + mark2 + mark3) / 3;
}

void PrintResult(float average)
{
    cout << "Average = " << average << endl;
}

int main()
{
    int mark1, mark2, mark3;
    ReadThreeNumber(mark1, mark2, mark3);
    PrintResult(averageMark(mark1, mark2, mark3));
    return 0;
}