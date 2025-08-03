#include <iostream>

using namespace std;

class clsPerson
{
public:
    string FirstName;
    string LastName;

    string getFullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{

    clsPerson Person1, Person2;
    

    Person1.FirstName = "cheikh";
    Person1.LastName = "taher";

    Person2.FirstName = "Messi";
    Person2.LastName = "taher";



    cout << Person1.getFullName() << endl;
     cout << Person2.getFullName() << endl;
}