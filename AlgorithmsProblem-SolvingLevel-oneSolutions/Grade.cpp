#include <iostream>
using namespace std;

int ReadNumberInRange(int From, int To)
{
    int Grade;
    do
    {
        cout << "Please enter your grade between 0 and 100: " << endl;
        cin >> Grade;
    } while (Grade < From || Grade > To);
    return Grade;
}


char GetLetterGrade(int Grade)
{
    if (Grade >= 90)
    {
        return 'A';
    }
   else if (Grade >= 80)
    {
        return 'B';
    }
    else if (Grade >= 70)
    {
        return 'C';
    }
    else if (Grade >= 60)
    {
        return 'D';
    }
    return 'F';
}


int main(){
    cout << endl << "Result: " << GetLetterGrade(ReadNumberInRange(0, 100)) << endl;
}