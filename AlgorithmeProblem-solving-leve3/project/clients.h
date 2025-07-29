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

vector<sClient> LoadCleintsFromFile(string FileName);
void SaveClientsToFile(string FileName, vector<sClient> Clients);
string ConvertClientRecordToLine(sClient Client, string Seperator);

void ShowClientMenuScreen();
void choiceCaseClientMenuScreen(vector<sClient> &Clients);
string isClientExist(vector<sClient> &Clients, string AccountNumber);
sClient ReadNewClient();
void AddNewClient();
void addClients();
void PrintClientRecord(sClient Client);
void PrintClientDetails(sClient Client);
void SowAllClientsList(vector<sClient> vClients);
void getAllClients();
void DeleteClientByAccountNumber(string AccountNumber);
void UpdateClientByAccountNumber(string AccountNumber);
void FindClientByAccountNumber(string AccountNumber);

void TransactionMenuScreen();
void choiceTransactionMenuScreen(vector<sClient> &Clients);




#endif
