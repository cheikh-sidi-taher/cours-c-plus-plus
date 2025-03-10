#include <vector>
#include <iostream>
using namespace std;


void ReadNamesPlayers(vector<string> &names)
{   char MoreNames = 'Y';
    string name;

    while (MoreNames == 'Y' || MoreNames == 'y')
    {
        cout << "Please enter player name? ";
        cin >> name;
        names.push_back(name);
        cout << "\nDo you want to read more names? Y/N ?";
        cin >> MoreNames;
    }
    

}

void PrintNamesPlayers(vector<string> names)
{
    for (string name : names){
        cout << name << endl;
    }
}


int main()
{
    vector<string> names;
    ReadNamesPlayers(names);
    PrintNamesPlayers(names);
    return 0;
}