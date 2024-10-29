#include <iostream>
using namespace std;


struct stInfo
{
    string firstName;
    string lastName;
    
};


stInfo readInfo(){
    stInfo Info;
    cout << "Please enter your first name?\n";
    getline(cin, Info.firstName);
    cout << "Please enter your last name?\n";
    getline(cin, Info.lastName);
    return Info;
}


string  getFullName(stInfo Info,bool Reversed){
    string fullName = ""; 
    if(Reversed)
    fullName = Info.lastName + " " + Info.firstName;
    else
    fullName = Info.firstName + " " + Info.lastName;
    return fullName;
}
void printFullName(string fullName){
    cout << "Your full name is: " << fullName << endl;
}
int main() {
    printFullName(getFullName(readInfo(),true));
    return 0;
}