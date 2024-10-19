#include <iostream>
using namespace std;

int main()
{
    string name, city, country;
    int age;
    float monthSalary, yearSalary;
    char gender;
    bool married;

    cout << "entre votre name: \n";
    cin >> name;
    cout << "entre votre age: \n";
    cin >> age;
    cout << "entre votre city: \n";
    cin >> city;
    cout << "entre votre country: \n";
    cin >> country;
    cout << "entre votre monthSalary: \n";
    cin >> monthSalary;
    cout << "entre votre gender: \n";
    cin >> gender;
    cout << "entre votre married: \n";
    cin >> married;

    yearSalary = monthSalary * 12;

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
}