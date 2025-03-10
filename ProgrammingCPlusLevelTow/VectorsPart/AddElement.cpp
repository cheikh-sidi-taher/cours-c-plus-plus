#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector <string> vPlayesrNames;
    vPlayesrNames.push_back("John");
    vPlayesrNames.push_back("Mark");
    vPlayesrNames.pop_back("Jill");
    


    for (string &PlayerName : vPlayesrNames)
    {
        cout << PlayerName << endl;
    }
    return 0;
}