#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLicense;
};

stInfo ReadInfo()
{
    stInfo Info;
    cout << "Please enter Age?\n";
    cin >> Info.Age;
    cout << "Please enter HasDrivingLicense?\n";
    cin >> Info.HasDrivingLicense;
    return Info;
}

bool IsAccepted(stInfo Info)
{

    return Info.Age >= 18 && Info.HasDrivingLicense == true;
}

void printResult(stInfo Info)
{
    if (IsAccepted(Info))
        cout << "Driver Accepted" << endl;
    else
        cout << "Driver Rejected" << endl;
}

int main()
{
    printResult(ReadInfo());
    return 0;
}