#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "users.h"
#include "clients.h"

using namespace std;

const string UsersFileName = "users.txt";


vector<stUser> LoadUsersFromFile(string FileName)
{
    vector<stUser> Users;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            stUser User;
            vector<string> parts;
            string delimiter = "#//#";
            size_t pos = 0;

            // Découper la ligne en parties
            while ((pos = Line.find(delimiter)) != string::npos)
            {
                parts.push_back(Line.substr(0, pos));
                Line.erase(0, pos + delimiter.length());
            }
            parts.push_back(Line); // Dernier élément

            // Assigner les parties si au moins 3 éléments
            if (parts.size() >= 3)
            {
                User.UserName = parts[0];
                User.Password = parts[1];
                User.Permission = stoi(parts[2]); // convertit string -> int
                Users.push_back(User);
            }
        }
        MyFile.close();
    }
    return Users;
}

bool isUserExist(string UserName)
{
    vector<stUser> Users = LoadUsersFromFile(UsersFileName);
    for (stUser User : Users)
    {
        if (User.UserName == UserName)
            return true;
    }
    return false;
}

stUser ReadNewUser()
{
    stUser User;
    char FullAccessAnswer;

    // Vérifie l'existence du nom d'utilisateur
    do
    {
        cout << "Enter User Name:\n";
        cin >> User.UserName;

        if (isUserExist(User.UserName))
        {
            cout << "User Name already exists! Please try again.\n";
        }

    } while (isUserExist(User.UserName));

    // Saisie du mot de passe
    cout << "Enter Password:\n";
    cin >> User.Password;

    // Attribution des permissions
    cout << "Do you want to give full access? (y/n): ";
    cin >> FullAccessAnswer;

    if (tolower(FullAccessAnswer) == 'y')
        User.Permission = -1;
    else
        User.Permission = 1;

    return User;
}
    

string ConvertRecordToLine(stUser User, string Seperator)
{
    return User.UserName + Seperator + User.Password + Seperator + to_string(User.Permission);
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

void AddNewUser()
{
    stUser User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertRecordToLine(User, "#//#"));
}

void AddUsers()
{
    char ch;
    do
    {
        AddNewUser();
        cout << "Do you want to add another user ? (y/n)\n";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void PrintUsertRecord(stUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(40) << left << User.Permission;
}
void SowAllUsersList(vector<stUser> vUsers)
{
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << " Users(s))" << endl;
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    for (stUser User : vUsers)
    {
        PrintUsertRecord(User);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}


void getAllUsers()
{
    vector<stUser> Users = LoadUsersFromFile(UsersFileName);

    if (Users.empty())
    {
        cout << "No users in the system!\n";
    }
    else
    {
        SowAllUsersList(Users);
    }
}


bool CheckLogin(const string &UserName, const string &Password)
{
    vector<stUser> Users = LoadUsersFromFile(UsersFileName);
    for (stUser User : Users)
    {
        if (User.UserName == UserName && User.Password == Password)
        {
            return true;
        }
    }
    return false;
}




void ShowManaerUserMenuScreen()
{
    cout << "===========================================\n";
    cout << "\t\tManger Users Menu Screen\n";
    cout << "===========================================\n";

    cout << "\t[1] getAll User.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Update User.\n";
    cout << "\t[4] Delete User.\n";
    cout << "\t[4] Find User.\n";
    cout << "\t[5] Exit.\n";

    cout << "===========================================\n";
}

void choiceCaseManagerMenuScreen(vector<stUser> &Users)
{
    short choice;
    do
    {
        ShowManaerUserMenuScreen();
        cout << "Choose what do you want to do? [1 to 5]? ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice)
        {
        case 1:
            system("clear");
            getAllUsers();
            BackToMainMenu();
            break;

        case 2:
            system("clear");
            AddUsers();
            BackToMainMenu();
            break;

        case 3:
            system("clear");
           cout << "delete User\n";
            BackToMainMenu();
            break;

        case 4:
            system("clear");
            cout << "update User\n";
            BackToMainMenu();
            break;

        case 5:
            system("clear");
            cout << "find User\n";
            BackToMainMenu();
            break;
        }
    } while (choice != 5);
}
