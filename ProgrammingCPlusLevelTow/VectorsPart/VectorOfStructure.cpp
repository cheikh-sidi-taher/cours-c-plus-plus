#include <vector>
#include <iostream>
using namespace std;
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};


void ReadEmployees(vector<stEmployee> &vEmployees)
{
    char ReadMore = 'Y';
    stEmployee tempEmployee;

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Please enter employee first name? ";
        cin >> tempEmployee.FirstName;
        cout << "Please enter employee last name? ";
        cin >> tempEmployee.LastName;
        cout << "Please enter employee salary? ";
        cin >> tempEmployee.Salary;
        vEmployees.push_back(tempEmployee);
        cout << "\nDo you want to read more employees? Y/N ?";
        cin >> ReadMore;
    }
}
    void PrintEmployees(vector<stEmployee> &vEmployees)
    {
        cout << "\nEmployees Vector: \n\n";
        for(stEmployee &Employee : vEmployees)
        {
            cout << "FirstName: " << Employee.FirstName << endl;
            cout << "LastName : " << Employee.LastName << endl;
            cout << "Salalry : " << Employee.Salary << endl;
        }
    }
    



int main()
{
    vector<stEmployee> vEmployees;
    ReadEmployees(vEmployees);
    PrintEmployees(vEmployees);
    return 0;
}