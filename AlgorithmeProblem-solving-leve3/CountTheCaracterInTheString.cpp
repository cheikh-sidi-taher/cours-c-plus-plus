#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}
short CountLetter(string S1, char Letter)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++;
    }
    return Counter;
}


int main() {
    string str = ReadString();
    char ch = ReadChar();
    int count = CountLetter(str, ch);
    cout << "\nString Length is : " << count << endl;
    system("pause>0");
}