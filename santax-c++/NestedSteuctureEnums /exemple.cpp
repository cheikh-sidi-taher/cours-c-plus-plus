#include  <iostream>
using namespace std;

enum enColor {Red , Green , Blue , Yellow};
enum enGender {Male , Female};
enum enMaritalStatus {Married , Single};


struct stAddress {
    string streetName;
    string buildingNumber;
    string poBox;
    string zipCode;
};


struct  stContactInfo
{
    string phoneNumber;
    string email;
    stAddress address;
};


struct stPerson
{
    string firstName;
    string lastName;
    int age;
    enColor eyeColor;
    enGender gender;
    enMaritalStatus maritalStatus;
    stContactInfo contactInfo;
};

int main(){
       stPerson myPerson;
       myPerson.firstName = "Cheikh";
       myPerson.lastName = "Sidi";
       myPerson.age = 44;
       myPerson.eyeColor = enColor::Red;
       myPerson.gender = enGender::Male;
       myPerson.maritalStatus = enMaritalStatus::Married;
       myPerson.contactInfo.phoneNumber = "123456789";
       myPerson.contactInfo.email = "yQ9bP@example.com";
       myPerson.contactInfo.address.streetName = "Rue";
       myPerson.contactInfo.address.buildingNumber = "12";
       myPerson.contactInfo.address.poBox = "12345";
       myPerson.contactInfo.address.zipCode = "12345";



       cout << "myPerson.firstName = " << myPerson.firstName << endl;
       cout << "myPerson.lastName = " << myPerson.lastName << endl;
       cout << "myPerson.age = " << myPerson.age << endl;
       cout << "myPerson.eyeColor = " << myPerson.eyeColor << endl;
       cout << "myPerson.gender = " << myPerson.gender << endl;
       cout << "myPerson.maritalStatus = " << myPerson.maritalStatus << endl;
       cout << "myPerson.contactInfo.phoneNumber = " << myPerson.contactInfo.phoneNumber << endl;
       cout << "myPerson.contactInfo.email = " << myPerson.contactInfo.email << endl;
       cout << "myPerson.contactInfo.address.streetName = " << myPerson.contactInfo.address.streetName << endl;
       cout << "myPerson.contactInfo.address.buildingNumber = " << myPerson.contactInfo.address.buildingNumber << endl;
       cout << "myPerson.contactInfo.address.poBox = " << myPerson.contactInfo.address.poBox << endl;
       cout << "myPerson.contactInfo.address.zipCode = " << myPerson.contactInfo.address.zipCode << endl;

       return 0;

}