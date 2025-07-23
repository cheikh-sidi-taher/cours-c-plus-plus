#ifndef CLIENTS_H
#define CLIENTS_H

#include <string>
#include <vector>
#include "users.h"

using namespace std;



struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// Fonctions principales
void loginMenuScreen(); // Lancement de l'application après login

// Fonctions utilitaires
void BackToMainMenu();
void TitleSreens(string title);

// Menu principal
void ShowMenuScreen();
void ChoiceCaseMenuScreen(vector<sClient> &Clients);

// Fonctions Client
sClient ReadClient(const vector<sClient> &clients);
string ReadAccountNumber();
void AddNewClient(vector<sClient> &Clients);
void addMoreClients(vector<sClient> &Clients);
void PrintClientRecord(sClient Client);
void PrintClientDetails(sClient Client);
void SowAllClientsList(vector<sClient> vClients);
void getAllClients(vector<sClient> &Clients);
void deleterdClientByAccountNumbe(vector<sClient> &Clients, string AccountNumber);
void UpdateClientByAccountNumber(vector<sClient> &Clients, string AccountNumber);
void FindClientByAccountNumber(vector<sClient> &Clients, string AccountNumber);

// Transaction
void TransactionMenuScreen();
void choiceTransactionMenuScreen(vector<sClient> &Clients);
float ReadAmountBlance();
float DepositClientBalance(vector<sClient> &Clients);
float withdrawalBalance(vector<sClient> &Clients);
bool ClientExistsAccountNumber(vector<sClient> Clients, string AccountNumber);
void withdrawalClientDetails(vector<sClient> &Clients);
void DepositClientDetails(vector<sClient> &Clients);
double TotalClientBalance(vector<sClient> &Clients);
void PrintAllTotalBalances(vector<sClient> vClients);
void loginMenuScreen();

#endif
