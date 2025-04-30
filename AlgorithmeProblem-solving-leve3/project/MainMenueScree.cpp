// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <iomanip>
// using namespace std;

// struct sClient
// {
//     string AccountNumber;
//     string PinCode;
//     string Name;
//     string Phone;
//     double AccountBalance;
// };

// string ReadAccountNumber()
// {
//     string AccountNumber;
//     cout << "Enter Account Number? ";
//     getline(cin >> ws, AccountNumber);
//     return AccountNumber;
// }

// void ShowMainMenuScreen()
// {
//     system("clear");
//     cout << "===========================================\n";
//     cout << "\t\tMain Menu Screen\n";
//     cout << "===========================================\n";
//     cout << "\t[1] Show Client List.\n";
//     cout << "\t[2] Add New Client.\n";
//     cout << "\t[3] Delete Client.\n";
//     cout << "\t[4] Update Client Info.\n";
//     cout << "\t[5] Find Client.\n";
//     cout << "\t[6] Ttransactions.\n";
//     cout << "\t[7] Exit.\n";
//     cout << "===========================================\n";
// }

// void TransactionsMenuScreen()
// {
//     system("clear");
//     cout << "===========================================\n";
//     cout << "\t\tTransactions Menu Screen\n";
//     cout << "===========================================\n";
//     cout << "\t[1] Deposit.\n";
//     cout << "\t[2] Withdraw.\n";
//     cout << "\t[3] Total Balances.\n";
//     cout << "\t[4] Main Menu.\n";
// }

// void PrintClientRecord(sClient Client)
// {
//     cout << "| " << setw(15) << left << Client.AccountNumber;
//     cout << "| " << setw(10) << left << Client.PinCode;
//     cout << "| " << setw(40) << left << Client.Name;
//     cout << "| " << setw(12) << left << Client.Phone;
//     cout << "| " << setw(12) << left << Client.AccountBalance;
// }

// void getClientByAccountNumber(vector<sClient> Clients, string AccountNumber = "")
// {
//     if (Clients.empty())
//     {
//         cout << "No clients in the system!\n";
//         return;
//     }

//     AccountNumber = ReadAccountNumber();

//     for (const sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == AccountNumber)
//         {
//             PrintClientRecord(Client);
//             return;
//         }
//     }

//     cout << "Client Not Found!\n";
// }

// sClient ReadClient()
// {
//     sClient Client;
//     cout << "Enter Account Number? ";
//     getline(cin >> ws, Client.AccountNumber);
//     cout << "Enter PinCode? ";
//     getline(cin, Client.PinCode);
//     cout << "Enter Name? ";
//     getline(cin, Client.Name);
//     cout << "Enter Phone? ";
//     getline(cin, Client.Phone);
//     cout << "Enter AccountBalance? ";
//     cin >> Client.AccountBalance;
//     return Client;
// }

// void UpdateClientByAccountNumber(vector<sClient> &Clients, string AccountNumber)
// {
//     if (Clients.empty())
//     {
//         cout << "No clients in the system!\n";
//         return;
//     }

//     AccountNumber = ReadAccountNumber();

//     for (sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == AccountNumber)
//         {
//             Client = ReadClient();
//             cout << "Client Updated Successfully!\n";
//             return;
//         }
//     }

//     cout << "Client Not Found!\n";
// }

// void AddNewClient(vector<sClient> &Clients)
// {
//     sClient Client;
//     Client = ReadClient();
//     Clients.push_back(Client);
// }

// void AddMoreClients(vector<sClient> &Clients)
// {
//     char AddMore = 'Y';
//     do
//     {
//         system("clear");
//         cout << "Adding New Client:\n\n";
//         AddNewClient(Clients);
//         cout << "\nClient Added Successfully!\n";
//         cout << "\nDo you want to add more clients? (y/n) ";
//         cin >> AddMore;
//         cin.ignore(); // Clear the input buffer
//     } while (toupper(AddMore) == 'Y');
// }

// void PrintAllClientsData(vector<sClient> vClients)
// {
//     cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s))" << endl;
//     cout << "_________________________________________\n"
//          << endl;
//     cout << "| " << left << setw(15) << "Accout Number";
//     cout << "| " << left << setw(10) << "Pin Code";
//     cout << "| " << left << setw(40) << "Client Name";
//     cout << "| " << left << setw(12) << "Phone";
//     cout << "| " << left << setw(12) << "Balance";
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;
//     for (sClient Client : vClients)
//     {
//         PrintClientRecord(Client);
//         cout << endl;
//     }
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;
// }

// void TotalBalances(vector<sClient> vClients)
// {
//     int TotalBalances = 0;
//     for (sClient Client : vClients)
//     {
//         TotalBalances += Client.AccountBalance;
//     }
//     cout << "Total Balances: " << TotalBalances << endl;
// }

// void PrintAllTotalBalances(vector<sClient> vClients)
// {
//     sClient Client;
//     cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s))" << endl;
//     cout << "_________________________________________\n"
//          << endl;
//     cout << "| " << left << setw(15) << "Accout Number";
//     cout << "| " << left << setw(40) << "Client Name";
//     cout << "| " << left << setw(12) << "Balance";
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;
//     for (sClient Client : vClients)
//     {
//         cout << "| " << left << setw(15) << Client.AccountNumber;
//         cout << "| " << left << setw(40) << Client.Name;
//         cout << "| " << left << setw(12) << Client.AccountBalance;
//         cout << endl;
//     }
//     cout << "\n_______________________________________________________";
//     cout << "_________________________________________\n"
//          << endl;

//     TotalBalances(vClients);
// }

// void ShowTitleScreen()
// {
//     cout << "-----------------------------------------------\n";
//     cout << "\t\tDeposit\n";
//     cout << "-----------------------------------------------\n";
// }

// void PrintClientDetails(sClient Client)
// {
//     cout << "\n\nThe following are the details of the client:\n";
//     cout << "-----------------------------------------------\n";
//     cout << "\nAccout Number: " << Client.AccountNumber;
//     cout << "\nPin Code : " << Client.PinCode;
//     cout << "\nName : " << Client.Name;
//     cout << "\nPhone : " << Client.Phone;
//     cout << "\nAccount Balance : " << Client.AccountBalance << endl;
//     cout << "-----------------------------------------------\n";
// }

// void BackToMainMenu()
// {
//     cout << "\nPress any key to go back to Main Menu...";
//     cin.ignore();
//     cin.get();
// }
// void DepositClientBalance(vector<sClient> &Clients)
// {
//     string accountNumber = ReadAccountNumber();

//     for (sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == accountNumber)
//         {
//             cout << "Enter amount to deposit: ";
//             float amount;
//             cin >> amount;

//             if (amount > 0)
//             {
//                 Client.AccountBalance += amount;
//                 cout << "Deposit successful. New balance: " << Client.AccountBalance << endl;
//                 BackToMainMenu();
//                 return;
//             }
//             else
//             {
//                 cout << "Invalid amount. Amount must be positive." << endl;
//                 return;
//             }
//         }
//     }
// }

// void withdrawalBalance(vector<sClient> &Clients)
// {
//     string accountNumber = ReadAccountNumber();

//     for (sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == accountNumber)
//         {
//             cout << "Enter withdrawal amount: ";
//             float amount;
//             cin >> amount;

//             if (Client.AccountBalance >= amount)
//             {
//                 Client.AccountBalance -= amount;
//                 cout << "Withdrawal successful. New balance: " << Client.AccountBalance << endl;
//                 BackToMainMenu();
//                 return;
//             }
//             else
//             {
//                 cout << "Amount exceeds account balance , your cannot withdraw up to " << Client.AccountBalance << endl;
//                 if (Client.AccountNumber == accountNumber)
//                 {
//                     cout << "Enter withdrawal amount: ";
//                     float amount;
//                     cin >> amount;

//                     if (Client.AccountBalance >= amount)
//                     {
//                         Client.AccountBalance -= amount;
//                         cout << "Withdrawal successful. New balance: " << Client.AccountBalance << endl;
//                         BackToMainMenu();
//                         return;
//                     }
//                 }
//             }
//         }
//     }
// }

// void WithdrawClientDetails(vector<sClient> &Clients)
// {
//     cout << "-----------------------------------------------\n";
//     cout << "\\tWithdraw\nt";
//     cout << "-----------------------------------------------\n";
//     string AccountNumber;
//     AccountNumber = ReadAccountNumber();
//     for (const sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == AccountNumber)
//         {

//             PrintClientDetails(Client);
//             withdrawalBalance(Clients);

//             return;
//         }

//         cout << "Client Not Found!\n";
//         withdrawalBalance(Clients);
//     }
// }
// void DepositClientDetails(vector<sClient> &Clients)
// {
//     ShowTitleScreen();
//     string AccountNumber;
//     AccountNumber = ReadAccountNumber();
//     for (const sClient &Client : Clients)
//     {
//         if (Client.AccountNumber == AccountNumber)
//         {

//             PrintClientDetails(Client);
//             DepositClientBalance(Clients);

//             return;
//         }

//         cout << "Client Not Found!\n";
//         DepositClientBalance(Clients);
//     }
// }

// void getAllClient(vector<sClient> Clients)
// {
//     if (Clients.empty())
//     {
//         cout << "No clients in the system!\n";
//     }
//     else
//     {
//         PrintAllClientsData(Clients);
//     }
// }

// void deletedClientByAccountNumber(vector<sClient> &Clients)
// {
//     string AccountNumber;
//     AccountNumber = ReadAccountNumber();
//     for (auto it = Clients.begin(); it != Clients.end(); ++it)
//     {
//         if (it->AccountNumber == AccountNumber)
//         {
//             Clients.erase(it);
//             cout << "Client Deleted Successfully!\n";
//             return;
//         }
//     }
//     cout << "Client Not Found!\n";
// }

// void ChoiceTransactionsMenuScreen(vector<sClient> &Clients)
// {
//     int Choice;
//     string AccountNumber;

//     do
//     {
//         TransactionsMenuScreen();
//         cout << "Choose what do you want to do? [1 to 4]? ";
//         cin >> Choice;
//         cin.ignore(); // Clear the input buffer

//         switch (Choice)
//         {

//         case 1:
//             system("clear");
//             DepositClientDetails(Clients);
//             BackToMainMenu();
//             break;

//         case 2:
//             system("clear");
//             WithdrawClientDetails(Clients);
//             BackToMainMenu();
//             break;

//         case 3:
//             system("clear");
//             PrintAllTotalBalances(Clients);
//             BackToMainMenu();
//             break;

//         case 4:
//             system("clear");
//             ShowMainMenuScreen();
//             break;

//         case 5:
//             system("clear");
//             cout << "Program Ended. Goodbye!\n";
//             break;

//         default:
//             cout << "Invalid Choice! Please try again.\n";
//             break;
//         }
//     } while (Choice != 5);
// }

// void ChoiceCaseMenuScreen(vector<sClient> &Clients)
// {
//     int Choice;
//     string AccountNumber;

//     do
//     {
//         ShowMainMenuScreen();
//         cout << "Choose what do you want to do? [1 to 6]? ";
//         cin >> Choice;
//         cin.ignore(); // Clear the input buffer

//         switch (Choice)
//         {
//         case 1:
//             system("clear");
//             getAllClients(Clients, AccountNumber);
//             BackToMainMenu();
//             break;

//         case 2:
//             system("clear");
//             AddMoreClients(Clients);
//             BackToMainMenu();
//             break;

//         case 3:
//             system("clear");
//             deletedClientByAccountNumber(Clients);
//             BackToMainMenu();
//             break;

//         case 4:
//             system("clear");
//             UpdateClientByAccountNumber(Clients, AccountNumber);
//             BackToMainMenu();
//             break;

//         case 5:
//             system("clear");
//             getClientByAccountNumber(Clients);
//             BackToMainMenu();
//             break;

//         case 6:
//             system("clear");
//             ChoiceTransactionsMenuScreen(Clients);
//             BackToMainMenu();

//             break;

//         case 7:
//             system("clear");
//             cout << "Program Ended. Goodbye!\n";
//             break;

//         default:
//             cout << "Invalid Choice! Please try again.\n";
//             BackToMainMenu();
//             break;
//         }
//     } while (Choice != 7);
// }

// int main()
// {
//     vector<sClient> Clients;
//     ChoiceCaseMenuScreen(Clients);
//     return 0;
// }