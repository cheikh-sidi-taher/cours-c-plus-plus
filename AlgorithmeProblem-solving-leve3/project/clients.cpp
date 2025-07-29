#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clients.h"
#include "users.h"
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

string ReadAccountNumber()
{
    string AccountNumber;
    cout << "Enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

vector<sClient> LoadCleintsFromFile(string FileName)
{
    vector<sClient> Clients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            sClient Client;
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

            if (parts.size() >= 4)
            {
                Client.AccountNumber = parts[0];
                Client.PinCode = parts[1];
                Client.Name = parts[2];
                Client.Phone = parts[3];
                Client.AccountBalance = stod(parts[4]);
                Clients.push_back(Client);
            }
        }
        MyFile.close();
    }
    return Clients;
}

void ChoiceCaseMenuScreen(vector<sClient> &Clients);
void TitleSreens(string title)
{

    cout << "===========================================\n";
    cout << "\t\t" << title << "\n";
    cout << "===========================================\n";
}

void ShowClientMenuScreen()
{
    cout << "===========================================\n";
    cout << "\t\t Clients Menu Screen\n";
    cout << "===========================================\n";

    cout << "\t[1] Get All Clients.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transaction. \n";
    cout << "\t[7] Manger Users.\n";
    cout << "\t[8] Logoutt.\n";

    cout << "===========================================\n";
}

bool isClientExist(string AccounNumber)
{
    vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
    for (sClient Client : Clients)
    {
        if (Client.AccountNumber == AccounNumber)
        {
            return true;
        }
    }
    return false;
}


 

sClient ReadNewClient()
{ 
    sClient Client;
    string AccountNumber;

    do {
        cout << "Enter Account Number? ";
        getline(cin >> ws, AccountNumber);

        if (isClientExist(AccountNumber)) {
            cout << "Client Already Exists, try again.\n\n";
        }
    } while (isClientExist(AccountNumber));

    Client.AccountNumber = AccountNumber;
    cout << "\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin >> ws, Client.Name);

    cout << "Enter Phone? ";
    getline(cin >> ws, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}


string ConvertRecordToLine(sClient Client, string Seperator)
{
    return Client.AccountNumber + Seperator + Client.PinCode + Seperator + Client.Name + Seperator + Client.Phone + Seperator + to_string(Client.AccountBalance);
}

void AddNewClient()
{
    sClient Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client, "#//#"));
}

void AddClients()
{
    char ch;
    do
    {
        AddNewClient();
        cout << "Do you want to add another Client ? (y/n)\n";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}
void SowAllClientsList(vector<sClient> vClients)
{
    cout << "\n\t\t\t\t\tClients List (" << vClients.size() << " Client(s))" << endl;
    cout << "____________________________________________________________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "PinCode";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n____________________________________________________________________________________________\n"
         << endl;

    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << "\n____________________________________________________________________________________________\n"
             << endl;
    }
}

void getAllClients()
{
    vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);

    if (Clients.empty())
    {
        cout << "No Clients in the system!\n";
    }
    else
    {
        SowAllClientsList(Clients);
    }
}

void PrintClientDetails(sClient Client)
{
    cout << "\n\t\t\t\t\tClient Details" << endl;
    cout << "____________________________________________________________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "PinCode";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n____________________________________________________________________________________________\n"
         << endl;
    PrintClientRecord(Client); // correction ici
    cout << "\n____________________________________________________________________________________________\n"
         << endl;
}

void FindClientByAccountNumber(string AccountNumber)
{
    TitleSreens("Find Client");
    AccountNumber = ReadAccountNumber();
    do
    {
        vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
        for (sClient Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                PrintClientDetails(Client);
                return;
            }
        }
        cout << "Client not found! Please try again.\n";
        AccountNumber = ReadAccountNumber();
    } while (true);
}

void SaveClientsToFile(string FileName, vector<sClient> Clients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (const sClient &u : Clients)
        {
            MyFile << ConvertRecordToLine(u, "#//#") << endl;
        }
        MyFile.close();
    }
}
void UpdateClientByAccountNumber(string AccountNumber)
{
    TitleSreens("Update Client");
    do
    {
        AccountNumber = ReadAccountNumber();
        vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
        for (sClient &Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                PrintClientDetails(Client);
                cout << "\n\nEnter new details for this Client:\n";
                sClient NewClient;
                cout << "Enter PinCode? "<< endl;
                cin >> NewClient.PinCode;
                cout << "Enter your Name? "<< endl;
                cin >> NewClient.Name;
                cout << "Enter your Phone? "<< endl;
                cin >> NewClient.Phone;
                cout << "Enter your Balance? "<< endl;
                cin >> NewClient.AccountBalance;
                Client = NewClient;

                SaveClientsToFile(ClientsFileName, Clients);
                cout << "Client updated successfully!\n";
                return;
            }
        }
        cout << "Client not found! Please try again.\n";
    } while (true);
}

void DeleteClientByAccountNumber(string AccountNumber)
{
    TitleSreens("Delete Client");
    vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);

    do
    {
        AccountNumber = ReadAccountNumber();
        for (int i = 0; i < Clients.size(); i++)
        {
            if (Clients[i].AccountNumber == AccountNumber)
            {
                Clients.erase(Clients.begin() + i);
                SaveClientsToFile(ClientsFileName, Clients);
                cout << "Client deleted successfully!\n";
                return;
            }
        }
        cout << "Client not found! Please try again.\n";
        AccountNumber = ReadAccountNumber();
    } while (true);
}


void BackToMainMenu()
{
    cout << "\nPress any key to go back to Main Menu...";
    cin.ignore();
    cin.get();
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



double TotalClientBalance()
{
    vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
    double total = 0;
    for (const sClient &Client : Clients)
    {
        total += Client.AccountBalance;
    }
    return total;
}



void PrintAllTotalBalances()
{
    vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\tClient List (" << Clients.size() << " Client(s))" << endl;
    cout << "_________________________________________________________________________________\n"
         << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(40) << "Client Name"
         << "| " << left << setw(12) << "Balance" << "|\n";
    cout << "_________________________________________________________________________________\n";

    for (sClient Client : Clients)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber;
        cout << "| " << left << setw(40) << Client.Name;
        cout << "| " << left << setw(12) << Client.AccountBalance << "|\n";
    }

    cout << "_________________________________________________________________________________\n";
    cout << "\nTotal Balances: " << TotalClientBalance() << endl;
}



float ReadAmountBlance()
{
    float amount;
    cout << "Plase enter amount: ";
    cin >> amount;
    return amount;
}

float DepositClientBalance(sClient &Client)
{
    float amount = ReadAmountBlance();
    Client.AccountBalance += amount;
    cout << "Deposit successful. New balance: " << Client.AccountBalance << endl;
    return Client.AccountBalance;
}

float withdrawalBalance(sClient &Client)
{
    float amount = ReadAmountBlance();
    if (Client.AccountBalance > amount)
    {
        Client.AccountBalance -= amount;
        cout << "Withdrawal successful. New balance: " << Client.AccountBalance << endl;
        return Client.AccountBalance;
    }
    else
    {
        cout << "Withdrawal failed. Insufficient balance." << endl;
        return Client.AccountBalance;
    }
}


void DepositClientDetails(string AccountNumber)
{
    TitleSreens("Deposit");

    while (true)
    {
        vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
        bool found = false;

        for (sClient &Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                PrintClientDetails(Client);
                DepositClientBalance(Client);
                SaveClientsToFile(ClientsFileName, Clients);
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "\nDeposit completed successfully.\n";
            return; // Quitte la fonction après le succès
        }

        AccountNumber = ReadAccountNumber();
        cout << "Client not found! Please try again.\n";
    }
}

void WithdrawalClientDetails(string AccountNumber)
{
    TitleSreens("Withdrawal");
    while (true)
    {
        vector<sClient> Clients = LoadCleintsFromFile(ClientsFileName);
        bool found = false;

        for (sClient &Client : Clients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                PrintClientDetails(Client);
                withdrawalBalance(Client);
                SaveClientsToFile(ClientsFileName, Clients);
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "\nWithdrawal completed successfully.\n";
            return;
        }

        AccountNumber = ReadAccountNumber();
        cout << "Client not found! Please try again.\n";
    }
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
            DepositClientDetails(AccountNumber);
            BackToMainMenu();
            break;

        case 2:
            system("clear");
            WithdrawalClientDetails(AccountNumber);
            break;

        case 3:
            system("clear");
            PrintAllTotalBalances();
            BackToMainMenu();
            break;

        case 4:
            system("clear");
            BackToMainMenu();
            break;
        }
    } while (Choice != 4);
}

void choiceCaseClientMenuScreen(vector<sClient> &Clients)
{
    short choice;
    string AccountNumber;
    vector <stUser> Users;
    do
    {
        ShowClientMenuScreen();
        cout << "Choose what do you want to do? [1 to 7]? ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            system("clear");
            getAllClients();
            BackToMainMenu();
            break;
        case 2:
            system("clear");
            AddClients();
            BackToMainMenu();
            break;
        case 3:
            system("clear");
            DeleteClientByAccountNumber(AccountNumber);
            BackToMainMenu();
            break;
        case 4:
            system("clear");
            UpdateClientByAccountNumber(AccountNumber);
            BackToMainMenu();
            break;
        case 5:
            system("clear");
            FindClientByAccountNumber(AccountNumber);
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
        default:
            cout << "Invalid choice, try again.\n";
            break;
        }
    } while (choice != 7);
}
