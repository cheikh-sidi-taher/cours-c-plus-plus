#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clients.h"
#include "users.h"
#include <iomanip>

using namespace std;
const string UsersFileName = "users.txt";
// void ShowManaerUserMenuScreen()
// {
//     cout << "===========================================\n";
//     cout << "\t\tManger Users Menu Screen\n";
//     cout << "===========================================\n";

//     cout << "\t[1] getAll User.\n";
//     cout << "\t[2] Add New User.\n";
//     cout << "\t[3] Update User.\n";
//     cout << "\t[4] Delete User.\n";
//     cout << "\t[4] Find User.\n";
//     cout << "\t[5] Exit.\n";

//     cout << "===========================================\n";
// }

// struct stUser
// {
//     string UserName;
//     string Password;
//     int Permission;
// };


// vector<stUser> LoadUsersFromFile(string FileName)
// {
//     vector<stUser> Users;
//     fstream MyFile;
//     MyFile.open(FileName, ios::in);
//     if (MyFile.is_open())
//     {
//         string Line;
//         while (getline(MyFile, Line))
//         {
//             stUser User;
//             vector<string> parts;
//             string delimiter = "#//#";
//             size_t pos = 0;

//             // Découper la ligne en parties
//             while ((pos = Line.find(delimiter)) != string::npos)
//             {
//                 parts.push_back(Line.substr(0, pos));
//                 Line.erase(0, pos + delimiter.length());
//             }
//             parts.push_back(Line); // Dernier élément

//             // Assigner les parties si au moins 3 éléments
//             if (parts.size() >= 3)
//             {
//                 User.UserName = parts[0];
//                 User.Password = parts[1];
//                 User.Permission = stoi(parts[2]); // convertit string -> int
//                 Users.push_back(User);
//             }
//         }
//         MyFile.close();
//     }
//     return Users;
// }

// bool isUserExist(string UserName)
// {
//     vector<stUser> Users = LoadUsersFromFile(UsersFileName);
//     for (stUser User : Users)
//     {
//         if (User.UserName == UserName)
//             return true;
//     }
//     return false;
// }

// stUser ReadNewUser()
// {
//     stUser User;
//     char FullAccessAnswer;

//     // Vérifie l'existence du nom d'utilisateur
//     do
//     {
//         cout << "Enter User Name:\n";
//         cin >> User.UserName;

//         if (isUserExist(User.UserName))
//         {
//             cout << "User Name already exists! Please try again.\n";
//         }

//     } while (isUserExist(User.UserName));

//     // Saisie du mot de passe
//     cout << "Enter Password:\n";
//     cin >> User.Password;

//     // Attribution des permissions
//     cout << "Do you want to give full access? (y/n): ";
//     cin >> FullAccessAnswer;

//     if (tolower(FullAccessAnswer) == 'y')
//         User.Permission = -1;
//     else
//         User.Permission = 1;

//     return User;
// }
    





// string ConvertRecordToLine(stUser User, string Seperator)
// {
//     return User.UserName + Seperator + User.Password + Seperator + to_string(User.Permission);
// }

// void AddDataLineToFile(string FileName, string stDataLine)
// {
//     fstream MyFile;
//     MyFile.open(FileName, ios::out | ios::app);
//     if (MyFile.is_open())
//     {
//         MyFile << stDataLine << endl;
//         MyFile.close();
//     }
// }

// void AddNewUser()
// {
//     stUser User = ReadNewUser();
//     AddDataLineToFile(UsersFileName, ConvertRecordToLine(User, "#//#"));
// }

// void AddUsers()
// {
//     char ch;
//     do
//     {
//         AddNewUser();
//         cout << "Do you want to add another user ? (y/n)\n";
//         cin >> ch;
//     } while (ch == 'y' || ch == 'Y');
// }



// string ConvertRecordToLine(sClient Client, string Seperator =
//                                                "#//#")
// {
//     string stClientRecord = "";
//     stClientRecord += Client.AccountNumber + Seperator;
//     stClientRecord += Client.PinCode + Seperator;
//     stClientRecord += Client.Name + Seperator;
//     stClientRecord += Client.Phone + Seperator;
//     stClientRecord += to_string(Client.AccountBalance);
//     return stClientRecord;
// }
// void AddDataLineToFile(string FileName, string stDataLine)
// {
//     fstream MyFile;
//     MyFile.open(FileName, ios::out | ios::app);
//     if (MyFile.is_open())
//     {
//         MyFile << stDataLine << endl;
//         MyFile.close();
//     }
// }

void ChoiceCaseMenuScreen(vector<sClient> &Clients);
void TitleSreens(string title)
{

    cout << "===========================================\n";
    cout << "\t\t" << title << "\n";
    cout << "===========================================\n";
}

sClient ReadClient(const vector<sClient> &clients)
{
    sClient Client;
    bool AccountExists;

    do
    {
        AccountExists = false;

        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

        // Vérifier si le compte existe déjà
        for (const auto &c : clients)
        {
            if (c.AccountNumber == Client.AccountNumber)
            {
                AccountExists = true;
                cout << "Account Number already exists. Please enter a different Account Number.\n";
                break;
            }
        }
    } while (AccountExists);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ReadAccountNumber()
{
    string AccountNumber;
    cout << "Enter Account Number? ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}

void AddNewClient(vector<sClient> &Clients)
{
    sClient Client;
    Client = ReadClient(Clients);
    Clients.push_back(Client);
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void addMoreClients(vector<sClient> &Clients)
{
    char AddMore = 'Y';
    do
    {
        system("clear");
        cout << "Adding New Client:\n\n";
        AddNewClient(Clients);
        cout << "\nClient Added Successfully!\n";
        cout << "\nDo you want to add more clients? (y/n) ";
        cin >> AddMore;
        cin.ignore(); // Clear the input buffer
    } while (toupper(AddMore) == 'Y');
}

void PrintClientDetails(sClient Client)
{
    cout << "\n\nThe following are the details of the client:\n";
    cout << "-----------------------------------------------\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance << endl;
    cout << "-----------------------------------------------\n";
}

void SowAllClientsList(vector<sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s))" << endl;
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void getAllClients(vector<sClient> &Clients)
{

    if (Clients.empty())
    {
        cout << "No clients in the system!\n";
    }
    else
    {
        SowAllClientsList(Clients);
    }
}

void BackToMainMenu()
{
    cout << "\nPress any key to go back to Main Menu...";
    cin.ignore();
    cin.get();
}

void deleterdClientByAccountNumbe(vector<sClient> &Clients, string AccountNumber)
{
    TitleSreens("Delete Client");
    do
    {

        AccountNumber = ReadAccountNumber();
        for (sClient &Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                char DeleteMore = 'Y';
                do
                {
                    system("clear");
                    PrintClientDetails(Client);
                    cout << "\nDo you want to delete this client? (y/n) ";
                    cin >> DeleteMore;
                    cin.ignore();

                    if (toupper(DeleteMore) == 'Y')
                    {
                        Clients.erase(Clients.begin() + Clients.size() - 1);
                        cout << "\nClient Deleted Successfully!\n";
                        return;
                    }
                } while (toupper(DeleteMore) == 'Y');
            }
        }
        cout << "\nClient Not Found!\n";
    } while (true);
}

void UpdateClientByAccountNumber(vector<sClient> &Clients, string AccountNumber)
{
    TitleSreens("Update Client");
    AccountNumber = ReadAccountNumber();

    for (sClient &Client : Clients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            Client = ReadClient(Clients);
            cout << "\nClient Updated Successfully!\n";
            return;
        }
        cout << "\nClient Not Found!\n";
    }
}

void FindClientByAccountNumber(vector<sClient> &Clients, string AccountNumber)
{
    TitleSreens("Find Client");
    do
    {
        AccountNumber = ReadAccountNumber();
        for (sClient &Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                PrintClientDetails(Client);
                return;
            }
        }
        cout << "\nClient Not Found!\n";
    } while (true);
}

void TransactionMenuScreen()
{
    cout << "===========================================\n";
    cout << "\t\tTransaction Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdrawal.\n";
    cout << "\t[3] Total.\n";
    cout << "\t[4] Back to Main Menu.\n";
    cout << "===========================================\n";
}



double TotalClientBalance(vector<sClient> &Clients)
{
    double total = 0;
    for (sClient &Client : Clients)
    {
        total += Client.AccountBalance;
    }
    return total;
}

void PrintAllTotalBalances(vector<sClient> vClients)
{
    sClient Client;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s))" << endl;
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    for (sClient Client : vClients)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber;
        cout << "| " << left << setw(40) << Client.Name;
        cout << "| " << left << setw(12) << Client.AccountBalance;
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "Total Balances: " << TotalClientBalance(vClients) << endl;
}

float ReadAmountBlance()
{
    float amount;
    cout << "Plase enter amount: ";
    cin >> amount;
    return amount;
}

float DepositClientBalance(vector<sClient> &Clients)
{
    float amount = ReadAmountBlance();
    for (sClient &Client : Clients)
    {
        if (Client.AccountBalance >= amount)
        {
            Client.AccountBalance += amount;
            cout << "Deposit successful. New balance: " << Client.AccountBalance << endl;
            return Client.AccountBalance;
        }

        
    }

    return 0.0f;
}

float withdrawalBalance(vector<sClient> &Clients)
{
    float amount = ReadAmountBlance();
    for (sClient &Client : Clients)
    {
        if (Client.AccountBalance > amount)
        {

            char withdrawalMore = 'Y';
            do
            {
                system("clear");
                PrintClientDetails(Client);
                cout << "\nDo you want to withdrawal this client? (y/n) ";
                cin >> withdrawalMore;
                cin.ignore();

                if (toupper(withdrawalMore) == 'Y')
                {
                    Client.AccountBalance -= amount;
                    cout << "Withdrawal successful. New balance: " << Client.AccountBalance << endl;
                    return Client.AccountBalance;
                }
            } while (toupper(withdrawalMore) == 'Y');
        }
        else
        {
            cout << "Withdrawal failed. Insufficient balance." << endl;
            return Client.AccountBalance;
        }
    }

    return 0.0f;
}

bool ClientExistsAccountNumber(vector<sClient> Clients, string AccountNumber)
{

    AccountNumber = ReadAccountNumber();
    for (const sClient &Client : Clients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            return true;
        }
    }
    return false;
}

void withdrawalClientDetails(vector<sClient> &Clients)
{
    TitleSreens("Withdrawal");
    for (sClient &Client : Clients)
    {
        if (ClientExistsAccountNumber(Clients, Client.AccountNumber))
        {
            PrintClientDetails(Client);
            withdrawalBalance(Clients);
            return;
        }

        else
        {
            cout << "Client Not Found!\n";
            for (sClient &Client : Clients)
            {
                if (ClientExistsAccountNumber(Clients, Client.AccountNumber))
                {
                    PrintClientDetails(Client);
                    withdrawalBalance(Clients);
                    return;
                }
            }
        }
    }
}
void DepositClientDetails(vector<sClient> &Clients)
{
    TitleSreens("Deposit");
    for (sClient &Client : Clients)
    {
        if (ClientExistsAccountNumber(Clients, Client.AccountNumber))
        {
            PrintClientDetails(Client);
            DepositClientBalance(Clients);
            return;
        }

        else
        {
            cout << "Client Not Found!\n";
            for (sClient &Client : Clients)
            {
                if (ClientExistsAccountNumber(Clients, Client.AccountNumber))
                {
                    PrintClientDetails(Client);
                    DepositClientBalance(Clients);
                    return;
                }
            }
        }
    }
}

void ShowMenuScreen()
{
    cout << "===========================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transaction. \n";
    cout << "\t[7] Manger Users.\n";
    cout << "\t[8] Logoutt.\n";
    cout << "===========================================\n";
}

void choiceTransactionMenuScreen(vector<sClient> &Clients)
{
    string AccountNumber;
    int Choice;

    do
    {
        TransactionMenuScreen();
        cout << "Choose what do you want to do? [1 to 4]? ";
        cin >> Choice;
        cin.ignore(); // Clear the input buffer

        switch (Choice)
        {
        case 1:
            system("clear");
            DepositClientDetails(Clients);
            BackToMainMenu();
            break;

        case 2:
            system("clear");
            withdrawalClientDetails(Clients);
            BackToMainMenu();
            break;

        case 3:
            system("clear");
            PrintAllTotalBalances(Clients);
            BackToMainMenu();
            break;

        case 4:
            system("clear");
            ChoiceCaseMenuScreen(Clients);
            BackToMainMenu();
            break;
        }
    } while (Choice != 4);
}

// void PrintUsertRecord(stUser User)
// {
//     cout << "| " << setw(15) << left << User.UserName;
//     cout << "| " << setw(10) << left << User.Password;
//     cout << "| " << setw(40) << left << User.Permission;
// }
// void SowAllUsersList(vector<stUser> vUsers)
// {
//     cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << " Users(s))" << endl;
//     cout << "_________________________________________\n"
//          << endl;
//     cout << "| " << left << setw(15) << "User Name";
//     cout << "| " << left << setw(10) << "Password";
//     cout << "| " << left << setw(40) << "Permissions";
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;
//     for (stUser User : vUsers)
//     {
//         PrintUsertRecord(User);
//         cout << "\n_______________________________________________________";
//         cout << "_________________________________________\n"
//              << endl;
//     }
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;
// }


// void getAllUsers()
// {
//     vector<stUser> Users = LoadUsersFromFile(UsersFileName);

//     if (Users.empty())
//     {
//         cout << "No users in the system!\n";
//     }
//     else
//     {
//         SowAllUsersList(Users);
//     }
// }
// void choiceCaseManagerMenuScreen(vector<stUser> &Users)
// {
//     short choice;
//     do
//     {
//         ShowManaerUserMenuScreen();
//         cout << "Choose what do you want to do? [1 to 5]? ";
//         cin >> choice;
//         cin.ignore(); // Clear the input buffer

//         switch (choice)
//         {
//         case 1:
//             system("clear");
//             getAllUsers();
//             BackToMainMenu();
//             break;

//         case 2:
//             system("clear");
//             AddUsers();
//             BackToMainMenu();
//             break;

//         case 3:
//             system("clear");
//            cout << "delete User\n";
//             BackToMainMenu();
//             break;

//         case 4:
//             system("clear");
//             cout << "update User\n";
//             BackToMainMenu();
//             break;

//         case 5:
//             system("clear");
//             cout << "find User\n";
//             BackToMainMenu();
//             break;
//         }
//     } while (choice != 5);
// }

void ChoiceCaseMenuScreen(vector<sClient> &Clients)
{
    int Choice;
    string AccountNumber;
    vector<stUser> Users;
    do
    {
        ShowMenuScreen();
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> Choice;
        cin.ignore(); // Clear the input buffer

        switch (Choice)
        {
        case 1:
            system("clear");
            getAllClients(Clients);
            BackToMainMenu();
            break;

        case 2:
            system("clear");
            addMoreClients(Clients);
            BackToMainMenu();
            break;

        case 3:
            system("clear");
            deleterdClientByAccountNumbe(Clients, AccountNumber);
            BackToMainMenu();
            break;

        case 4:
            system("clear");
            UpdateClientByAccountNumber(Clients, AccountNumber);
            BackToMainMenu();
            break;

        case 5:
            system("clear");
            FindClientByAccountNumber(Clients, AccountNumber);
            BackToMainMenu();
            break;

        case 6:
            system("clear");
            choiceTransactionMenuScreen(Clients);
            BackToMainMenu();

            break;

        case 7:
            system("clear");
            choiceCaseManagerMenuScreen(Users);
            break;
        case 8:
            system("clear");
            cout << "Logout\n";
            break;

        default:
            cout << "Invalid Choice! Please try again.\n";
            BackToMainMenu();
            break;
        }
    } while (Choice != 7);
}




// fonction pour verifier le login
// bool CheckLogin(const string &UserName, const string &Password)
// {
//     vector<stUser> Users = LoadUsersFromFile(UsersFileName);
//     for (stUser User : Users)
//     {
//         if (User.UserName == UserName && User.Password == Password)
//         {
//             return true;
//         }
//     }
//     return false;
// }

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


