#include <iostream>
using namespace std;

enum enPassFail
{
    Pass = 1,
    Fail = 2
};

int ReadMark()
{
    int mark;
    cout << "Please enter your mark? " << endl;
    cin >> mark;
    return mark;
}

enPassFail CheckMark(int mark)
{
    if (mark >= 50)
    {
        return enPassFail::Pass;
    }
    else
    {
        return enPassFail::Fail;
    }
}

void PrintResult(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
    {
        cout << "YouPass" << endl;
    }
    else
    {
        cout << "You Fail" << endl;
    }
}

int main()
{
    PrintResult(ReadMark());
    return 0;
}
