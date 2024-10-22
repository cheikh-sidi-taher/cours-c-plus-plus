#include <iostream>
#include <string>

using namespace std;

enum enGender {
    male,
    female
};

enum enMaritalStatus {
    married,
    single
};

struct strPersonInfo {
    string name;
    int age;
    string city;
    string country;
    float monthSalary; // corrected typo from mothSalary
    float yearSalary;
    enGender gender;
    enMaritalStatus maritalStatus;
};

void readPersonInfo(strPersonInfo &info) {
    cout << "Enter your name: ";
    cin >> info.name;
    
    cout << "Enter your age: ";
    cin >> info.age;
    
    cout << "Enter your city: ";
    cin >> info.city;
    
    cout << "Enter your country: ";
    cin >> info.country;
    
    cout << "Enter your monthly salary: ";
    cin >> info.monthSalary;

    info.yearSalary = info.monthSalary * 12;

    cout << "Enter your gender (M for male, F for female): ";
    char genderInput;
    cin >> genderInput;
    
    if (genderInput == 'M' || genderInput == 'm') {
        info.gender = male;
    } else if (genderInput == 'F' || genderInput == 'f') {
        info.gender = female;
    } else {
        cout << "Invalid input. Defaulting to Male." << endl;
        info.gender = male; 
    }

    cout << "Enter your marital status (0 for married, 1 for single): ";
    int maritalInput;
    cin >> maritalInput;
    info.maritalStatus = enMaritalStatus(maritalInput);
}

void printPersonInfo(const strPersonInfo &info) {
    cout << "\n************************\n";
    cout << "Name: " << info.name << endl;
    cout << "Age: " << info.age << endl;
    cout << "City: " << info.city << endl;
    cout << "Country: " << info.country << endl;
    cout << "Monthly Salary: " << info.monthSalary << endl;
    cout << "Yearly Salary: " << info.yearSalary << endl;
    cout << "Gender: " << (info.gender == male ? "Male" : "Female") << endl;
    cout << "Marital Status: " << (info.maritalStatus == married ? "Married" : "Single") << endl;
    cout << "************************\n";
}

int main() {
    strPersonInfo person;
    readPersonInfo(person);
    printPersonInfo(person);

    
    strPersonInfo person2;
    readPersonInfo(person2);
    printPersonInfo(person2);
    return 0;
}
