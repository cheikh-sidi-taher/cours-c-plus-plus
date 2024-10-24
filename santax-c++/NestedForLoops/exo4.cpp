#include <iostream>
using namespace std;


void printTable() {
    cout << "\t\t\tMultiplication Table From 1 to 10\n \n";
    cout <<"\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n";
    cout <<"------------------------------------------------------------------------------------\n";
}

void printLine() {
    printTable();

     for (int i = 1; i <= 10; i++) {
    
        cout << i  << "\t";
        for (int j = 1; j <= 10; j++) {
            cout << "|";
            cout << i * j << "\t";
        }
        cout << "\n";
    }
}

int main() {

    printLine();

return 0;
   
}