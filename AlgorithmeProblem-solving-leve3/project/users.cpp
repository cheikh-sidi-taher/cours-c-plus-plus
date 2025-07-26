#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
#include "users.h"
#include "clients.h"

using namespace std;

const string UsersFileName = "users.txt";

string  ReadUserName(){
    string UserName;
    cout << "Enter your username: ";
    cin >> UserName;
    return UserName;
}
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
// --- Fonction pour exporter la liste des utilisateurs en HTML ---
void ExportUsersToHTML(const vector<stUser>& users, const string& htmlFileName)
{
    ofstream file(htmlFileName);
    if (!file.is_open())
    {
        cout << "Failed to open file for writing: " << htmlFileName << endl;
        return;
    }

    file << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n";
    file << "<title>Users List</title>\n";
    file << "<style>\n";
    file << "table { border-collapse: collapse; width: 100%; }\n";
    file << "th, td { border: 1px solid black; padding: 8px; text-align: left; }\n";
    file << "th { background-color: #0d160dff; color: white; }\n";
    file << "</style>\n</head>\n<body>\n";
    file << "<h2>Users List (" << users.size() << " users)</h2>\n";
    file << "<table>\n";
    file << "<tr><th>User Name</th><th>Password</th><th>Permissions</th></tr>\n";

    for (const auto& user : users)
    {
        file << "<tr>";
        file << "<td>" << user.UserName << "</td>";
        file << "<td>" << user.Password << "</td>";
        string permText = (user.Permission == -1) ? "Full Access" : "Limited Access";
        file << "<td>" << permText << "</td>";
        file << "</tr>\n";
    }

    file << "</table>\n</body>\n</html>";
    file.close();

}
string GenerateUserRowsHTML(const vector<stUser>& users)
{
    stringstream ss;
    for (const auto& user : users)
    {
        ss << "<tr>";
        ss << "<td>" << user.UserName << "</td>";
        ss << "<td>" << user.Password << "</td>";
        string permText = (user.Permission == -1) ? "Full Access" : "Limited Access";
        ss << "<td>" << permText << "</td>";
        ss << "</tr>\n";
    }
    return ss.str();
}
// --- Fonction pour exporter la liste des utilisateurs en PDF ---
void ExportUsersToPDF()
{
    vector<stUser> users = LoadUsersFromFile(UsersFileName);
    if (users.empty())
    {
        cout << "No users to export!\n";
        return;
    }

    // Lire le template HTML
    ifstream templateFile("template.html");
    if (!templateFile.is_open())
    {
        cout << "Error: Cannot open template.html\n";
        return;
    }

    stringstream buffer;
    buffer << templateFile.rdbuf();
    string htmlContent = buffer.str();
    templateFile.close();

    // Remplacer les placeholders
    string userRows = GenerateUserRowsHTML(users);
    size_t pos;

    pos = htmlContent.find("{{USERS_ROWS}}");
    if (pos != string::npos)
        htmlContent.replace(pos, 14, userRows);

    pos = htmlContent.find("{{USERS_COUNT}}");
    if (pos != string::npos)
        htmlContent.replace(pos, 15, to_string(users.size()));

    // Sauvegarder le HTML temporaire
    string htmlFile = "temp_users.html";
    ofstream outFile(htmlFile);
    outFile << htmlContent;
    outFile.close();

    // Générer le PDF
    string command = "wkhtmltopdf " + htmlFile + " users.pdf";
    int result = system(command.c_str());

    // Nettoyage
    remove(htmlFile.c_str());

    if (result == 0)
        cout << "PDF file generated successfully: users.pdf\n";
    else
        cout << "Failed to generate PDF. Make sure wkhtmltopdf is installed.\n";
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


void PrintUserDetails(stUser User){
    cout << "\n\t\t\t\t\tUser Details" << endl;
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    PrintUsertRecord(User);
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void FindUserByUserName(string UserName)
{
    TitleSreens("Find User");
    UserName = ReadUserName();
    do{
        vector<stUser> Users = LoadUsersFromFile(UsersFileName);
        for (stUser User : Users)
        {
            if (User.UserName == UserName)
            {
                PrintUserDetails(User);
                return;
            }
        }
        cout << "User not found! Please try again.\n";
        UserName = ReadUserName();
    }while(true);
  
}



void SaveUsersToFile(string FileName, vector<stUser> Users){
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (const stUser& u : Users)
        {
            MyFile << ConvertRecordToLine(u, "#//#") << endl;
        }
        MyFile.close();

    }
}
void UpdateUserByUserName(string UserName){
    TitleSreens("Update User");
    UserName = ReadUserName();
    do{
        vector<stUser> Users = LoadUsersFromFile(UsersFileName);
        for (stUser &User : Users)
        {
            if (User.UserName == UserName)
            {
            PrintUserDetails(User);
            cout << "\n\nEnter new details for this user:\n";
            stUser NewUser = ReadNewUser();
            User = NewUser;

            SaveUsersToFile(UsersFileName, Users);
            cout << "User updated successfully!\n";
            return;
            }
        }
        cout << "User not found! Please try again.\n";
        UserName = ReadUserName();
        BackToMainMenu();
        
    }while(true);
}


void DeleteUserByUserName(string UserName){
    TitleSreens("Delete User");
    UserName = ReadUserName();
    do{
        vector<stUser> Users = LoadUsersFromFile(UsersFileName);
        for (stUser &User : Users)
        {
            if (User.UserName == UserName)
            {
                PrintUserDetails(User);
                cout << "\n\nAre you sure you want to delete this user ? (y/n)\n";
            }
        }
        cout << "User not found! Please try again.\n";
        UserName = ReadUserName();
    }while(true);
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
    cout << "\t\tManage Users Menu Screen\n";
    cout << "===========================================\n";

    cout << "\t[1] Get All Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Update User.\n";
    cout << "\t[4] Delete User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Export Users List to PDF.\n"; // Nouvelle option
    cout << "\t[7] Exit.\n";

    cout << "===========================================\n";
}

void choiceCaseManagerMenuScreen(vector<stUser> &Users)
{
    short choice;
    string UserName;
    do
    {
        ShowManaerUserMenuScreen();
        cout << "Choose what do you want to do? [1 to 7]? ";
        cin >> choice;
        cin.ignore();

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
                UpdateUserByUserName(UserName);
                BackToMainMenu();
                break;
            case 4:
                system("clear");
                DeleteUserByUserName(UserName);
                BackToMainMenu();
                break;
            case 5:
                system("clear");
                FindUserByUserName(UserName);
                BackToMainMenu();
                break;
            case 6:
                system("clear");
                ExportUsersToPDF();
                BackToMainMenu();
                break;
            case 7:
                system("clear");
                cout << "Exiting User Manager...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
        }
    } while (choice != 7);
}


void loginMenuScreen()
{
    vector<sClient> Clients;
    stUser User;

    do
    {
        cout << "===========================================\n";
        cout << "\t\tLogin Menu Screen\n";
        cout << "===========================================\n";
        cout << "Please enter User Name:\n";
        cin >> User.UserName;
        cout << "Please enter Password:\n";
        cin >> User.Password;

        if (CheckLogin(User.UserName, User.Password))
        {
            ChoiceCaseMenuScreen(Clients);
            break; // Quitte la boucle après connexion réussie
        }
        else
        {
            cout << "Invalid User Name or Password! Please try again.\n";
        }

    } while (true);
}



