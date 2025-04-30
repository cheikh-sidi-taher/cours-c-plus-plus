#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
// const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

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



sClient ReadClient(const vector<sClient>& clients)
{
    sClient Client;
    bool AccountExists;
    
    do {
        AccountExists = false;
        
        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

        // Vérifier si le compte existe déjà
        for (const auto& c : clients)
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

void addMoreClients(vector<sClient> &Clients){
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
    AccountNumber = ReadAccountNumber();
    for (sClient &Client : Clients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
           char DeleteMore = 'Y';
           do{
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
           }while(toupper(DeleteMore) == 'Y');
           }
            cout << "\nClient Not Found!\n";
        }

       
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
    AccountNumber = ReadAccountNumber();
    for (const sClient &Client : Clients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            PrintClientDetails(Client);
            return;
        }
    }
    cout << "Client Not Found!\n";
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


double TotalClientBalance(vector<sClient> &Clients){
    double total = 0;
    for(sClient &Client : Clients){
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

float ReadAmountBlance(){
    float amount;
    cout << "Plase enter amount: ";
    cin >> amount;
    return amount;
}

float DepositClientBalance(vector<sClient> &Clients){
    float amount = ReadAmountBlance();
    for(sClient &Client : Clients){
        if(Client.AccountBalance >= amount){
            Client.AccountBalance += amount;
            cout << "Deposit successful. New balance: " << Client.AccountBalance << endl;
            return Client.AccountBalance;
        }
    }
}

float withdrawalBalance(vector<sClient> &Clients){
    float amount = ReadAmountBlance();
    for(sClient &Client : Clients){
        if(Client.AccountBalance > amount){
            
          char withdrawalMore = 'Y';
          do{
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
          }while(toupper(withdrawalMore) == 'Y');
        }
        else{
            cout << "Withdrawal failed. Insufficient balance." << endl;
            return Client.AccountBalance;
        }
    }
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


void withdrawalClientDetails(vector<sClient> &Clients){
    TitleSreens("Withdrawal");
    for (sClient &Client : Clients)
    {
       if(ClientExistsAccountNumber(Clients, Client.AccountNumber)){
        PrintClientDetails(Client);
        withdrawalBalance(Clients);
        return;
       }

      else{
        cout << "Client Not Found!\n";
        for (sClient &Client : Clients)
        {
            if(ClientExistsAccountNumber(Clients, Client.AccountNumber)){
                PrintClientDetails(Client);
                withdrawalBalance(Clients);
                return;
            }
        }
      }
}
}
void DepositClientDetails(vector<sClient> &Clients){
    TitleSreens("Deposit");
    for (sClient &Client : Clients)
    {
       if(ClientExistsAccountNumber(Clients, Client.AccountNumber)){
        PrintClientDetails(Client);
        DepositClientBalance(Clients);
        return;
       }

      else{
        cout << "Client Not Found!\n";
        for (sClient &Client : Clients)
        {
            if(ClientExistsAccountNumber(Clients, Client.AccountNumber)){
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
    cout << "===========================================\n";
}


void choiceTransactionMenuScreen(vector<sClient> &Clients){
    string AccountNumber;
    int Choice;

    do{
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
    }while(Choice != 4);
}

void ChoiceCaseMenuScreen(vector<sClient> &Clients)
{
    int Choice;
    string AccountNumber;

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
            cout << "Program Ended. Goodbye!\n";
            break;

        default:
            cout << "Invalid Choice! Please try again.\n";
            BackToMainMenu();
            break;
        }
    } while (Choice != 7);
}
int main()
{

    vector<sClient> Clients;

    ChoiceCaseMenuScreen(Clients);

    return 0;
}