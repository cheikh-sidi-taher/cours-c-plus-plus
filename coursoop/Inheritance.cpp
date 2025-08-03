#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _FullName;
    string _Email;
    int _PhoneNumber;

public:
    clsPerson(int ID, string FirstName, string LastName, string Email, int PhoneNumber)
    {
        _ID = ID; // Si aucun ID n'est passé, il prendra la valeur 10 par défaut
        _FirstName = FirstName;
        _LastName = LastName;
        _FullName = FirstName + " " + LastName; // Créer le nom complet automatiquement
        _Email = Email;
        _PhoneNumber = PhoneNumber;
    }

    // Getter pour _ID
    int GetID()
    {
        return _ID;
    }

    // Getter pour _FirstName
    string GetFirstName()
    {
        return _FirstName;
    }

    // Getter pour _LastName
    string GetLastName() const
    {
        return _LastName;
    }

    // Getter pour _FullName
    string GetFullName() const
    {
        return _FullName;
    }

    // Getter pour _Email
    string GetEmail() const
    {
        return _Email;
    }

    // Getter pour _PhoneNumber
    int GetPhoneNumber() const
    {
        return _PhoneNumber;
    }

    // Setter pour _FirstName
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    // Setter pour _LastName
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    // Setter pour _Email
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    void SendMail(string Sub, string body)
    {
        cout << "-----------------------------" << endl;
        cout << "\nThe following message sent successfully to email : " << _Email << endl;
        cout << "subject:" << Sub << endl;
        cout << "Body : " << body << endl;
    }

    void SendSms(string msg)
    {
        cout << "-----------------------------" << endl;
        cout << "\nThe following SMS sent successfully to phone: " << _PhoneNumber << endl;
        cout << "msg:" << msg << endl;
    }

    // Setter pour _PhoneNumber
    void SetPhoneNumber(int PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    // Afficher toutes les informations de la personne
    void DisplayInfo() const
    {
        cout << "ID: " << _ID << endl;
        cout << "FirstName: " << _FirstName << endl;
        cout << "LastName: " << _LastName << endl;
        cout << "Full Name: " << _FullName << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone Number: " << _PhoneNumber << endl;
    }
};

class clsEmployee : public clsPerson
{
private:
    string _Title;
    string _Departement;
    float _Salary;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Email, int PhoneNumber, string Title, string Department, float Salary) : clsPerson(ID, FirstName, LastName, Email, PhoneNumber)
    {

        _Title = Title;
        _Departement = Department;
        _Salary = Salary;
    }
    void setTitle(string Title)
    {
        _Title = Title;
    }

    string getTitle()
    {
        return _Title;
    }

    void setSalary(float Salary)
    {
        _Salary = Salary;
    }
    float getSalary()
    {
        return _Salary;
    }

    void setDepartment(string Deparetment)
    {
        _Departement = Deparetment;
    }

    string getDepartement()
    {
        return _Departement;
    }


    void DisplayInfo(){

        cout << "Employe info details:" << endl;
        cout << "-------------------------"<< endl;
        cout << "ID: " << GetID()<< endl;
        cout << "FirstName: " << GetFirstName()<< endl;
        cout << "LastName: " << GetLastName() << endl;
        cout << "Full Name: " << GetFullName()<< endl;
        cout << "Email: " << GetEmail()<< endl;
        cout << "Phone Number: " << GetPhoneNumber() << endl;
        cout << "Title :" << _Title << endl;
        cout << "Department: " << _Departement << endl;
        cout << "Salary : " << _Salary << endl;

         cout << "-------------------------"<< endl;
    }
};

class clsPrograming : public clsEmployee{
    private:
    string _MainProgrammingLanguage;

    public:
    clsPrograming(int ID, string FirstName, string LastName, string Email, int PhoneNumber, string Title, string Department, float Salary , string MainPrograming):clsEmployee(ID, FirstName,LastName,Email,PhoneNumber ,Title,Department,Salary)
    {
       _MainProgrammingLanguage = MainPrograming;
    }
    void setMainProgrammingLanguage(string MainPrograming){
        _MainProgrammingLanguage = MainPrograming;
    }

    string getMainProgrammingLanguage(){
        return _MainProgrammingLanguage;
    }


     void DisplayInfo(){

        cout << "Employe info details:" << endl;
        cout << "-------------------------"<< endl;
        cout << "ID: " << GetID()<< endl;
        cout << "FirstName: " << GetFirstName()<< endl;
        cout << "LastName: " << GetLastName() << endl;
        cout << "Full Name: " << GetFullName()<< endl;
        cout << "Email: " << GetEmail()<< endl;
        cout << "Phone Number: " << GetPhoneNumber() << endl;
        cout << "Title :" <<  getTitle() << endl;
        cout << "Department: " << getDepartement() << endl;
        cout << "Salary : " << getSalary() << endl;
        cout << "MainProgrammingLanguage: " << getMainProgrammingLanguage() << endl;

         cout << "-------------------------"<< endl;
    }

    
};

int main()
{
    // Créer un objet "person1" en utilisant le constructeur avec 5 arguments
    // clsPerson person1(10, "cheikh", "sidi", "cheikh@gmail.com", 33456677);

    clsPrograming programing1(16, "cheikh", "med", "cheikh@gmail.com", 3387845 ,"cio","programing",5000, "language c++");
    programing1.DisplayInfo();

    //     // Affichage des informations de "person1"
    //     cout
    //     << "Informations de la première personne :\n";
    // person1.DisplayInfo();
    // person1.SendMail("hi", "how are you");
    // person1.SendSms("cv coment ");

    return 0;
}
