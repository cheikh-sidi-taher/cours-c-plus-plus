#include <iostream>
using namespace std;


int ReadNumbers(){
    int N;
    cout << "Please enter a number: " << endl;
    cin >> N;
    return N;
    }

void PrintNumbers(int N){


    for (int i = 1; i <= N; i++)
    {
        cout << i << endl;
    }
    }
// void PrintNumbers(int N)
//     {
//      int i = 1;
//      while (i <= N)
//      {
//         cout << i << endl;
//         i++;
//      }
//     }


// void PrintNumbers(int N)
//     {
//      int i = 1;
//      do
//      {
//         cout << i << endl;
//         i++;
//      } while (i <= N);
//     }

int main(){
    
    PrintNumbers(ReadNumbers());
    return 0;
}