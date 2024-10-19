#include <iostream>
using namespace std;

int main()
{

    string name = "cheikh sidi taher";
    int age = 44;
    string city = "Nouakchott";
    string country = "Mauritanie";
    float monthSalary = 5000;
    float yearSalary = monthSalary * 12;
    char gender = 'M';
    bool married = true;

    cout << "************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Monthly Salary: " << monthSalary << endl;
    cout << "Yearly Salary: " << yearSalary << endl;
    cout << "Gender: " << gender << endl;
    cout << "Married: " << married << endl;
    cout << "************************" << endl;

    return 0;
}