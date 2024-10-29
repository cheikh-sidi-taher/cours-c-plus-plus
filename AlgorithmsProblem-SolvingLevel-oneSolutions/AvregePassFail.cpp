#include <iostream>
using namespace std;

enum enPassFail
{
    Pass = 1,
    Fail = 2
};

void ReadThreeNumber(int &mark1, int &mark2, int &mark3)
{
    cout << "Please enter your mark 1 ? " << endl;
    cin >> mark1;
    cout << "Please enter your mark2 ? " << endl;
    cin >> mark2;
    cout << "Please enter your mark 3 ? " << endl;
    cin >> mark3;
}

int SumOfMarks(int mark1, int mark2, int mark3)
{
    return mark1 + mark2 + mark3;
}

float CalulateaverageMark(int mark1, int mark2, int mark3)
{
    return (float)(mark1 + mark2 + mark3) / 3;
}

enPassFail CheckAverageMark(float average)
{
    if (average == enPassFail::Pass)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

void PrintResult(float average)
{
    cout << "Average = " << average << endl;

    if (CheckAverageMark(average) == enPassFail::Pass)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

int main()
{
    int mark1, mark2, mark3;
    ReadThreeNumber(mark1, mark2, mark3);
    PrintResult(CalulateaverageMark(mark1, mark2, mark3));
    return 0;
}