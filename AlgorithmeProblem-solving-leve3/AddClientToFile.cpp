#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits> 
using namespace std;
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "users.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance; 
};
sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);
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

string ConvertRecordToLine(sClient Client, string Seperator =
                                               "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
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
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName,
                      ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system("clear");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nDo you want to add more clients? (y/n) ";
                  cin >>
                  AddMore;
    } while (toupper(AddMore) == 'Y');
}
int main()
{
    AddClients();
    system("read -p 'Appuyez sur Entrée pour continuer...'"); 
    return 0;
}