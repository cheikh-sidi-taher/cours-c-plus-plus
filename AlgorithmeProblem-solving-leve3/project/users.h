#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
using namespace std;

struct stUser {
    string UserName;
    string Password;
    int Permission;
};

vector<stUser> LoadUsersFromFile(string FileName);
bool isUserExist(string UserName);
stUser ReadNewUser();
string ConvertRecordToLine(stUser User, string Seperator);
void AddDataLineToFile(string FileName, string stDataLine);
void AddNewUser();
void AddUsers();
void PrintUsertRecord(stUser User);
void SowAllUsersList(vector<stUser> vUsers);
void getAllUsers();
bool CheckLogin(const string &UserName, const string &Password);
void ShowManaerUserMenuScreen();
void PrintUserDetails(stUser User);
void FindUserByUserName(string UserName);
void SaveUsersToFile(string FileName, vector<stUser> Users);
void UpdateUserByUserName(string UserName); 
void DeleteUserByUserName(string UserName);

void choiceCaseManagerMenuScreen(vector<stUser> &Users);


void loginMenuScreen();
void BackToMainMenu();
// Nouveau prototype pour exporter PDF
void ExportUsersToPDF();
#endif
