#include <iostream>
using namespace std;



struct StrInfo
{
   string FirstName;
   string LastName;
   int Age; 
   int phone;
};


void readInfo(StrInfo &Info){

    cout << "Enter First Name?\n";
    cin >> Info.FirstName;
    cout << "Enter Last Name?\n";
    cin >> Info.LastName;
    cout << "Enter Age?\n ";
    cin >> Info.Age;
    cout << "Enter Phone Number?\n";
    cin >> Info.phone;

}



void printInfo(StrInfo &Info){
    cout << "\n************************\n" << endl;

    cout << "First Name: " << Info.FirstName << endl;
    cout << "Last Name: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone Number: " << Info.phone << endl;

    cout << "\n************************\n" << endl;
}

int main(){

    StrInfo PersonelInfo;
    readInfo(PersonelInfo);
    printInfo(PersonelInfo);
    return 0;

}