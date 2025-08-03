#include <iostream>
using namespace std;

class clsPerson
{
private:
    int _ID=10;
    string _FirstName;
    string _LastName;

public:
    void setFirsName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string getFirstName()
    {
        return _FirstName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string getLastName()
    {
        return _LastName;
    }

    string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }

    int GetID(){
        return _ID;
    }
};

int main()
{

    clsPerson Person1;

    Person1.setFirsName("cheikh sidi");
    Person1.setLastName("taher");
    cout << Person1.GetID() << endl;
    cout << Person1.getFirstName() << endl;
    cout << Person1.getLastName() << endl;
    cout << Person1.GetFullName() << endl;
}