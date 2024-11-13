
#include <iostream>
#include <string>
using namespace std;
string ReadText()
{
    string Text;
    cout << "Please enter Text?\n";
    getline(cin, Text);
    return Text;
}


string Encrypte(string Text)
{
    string EncryptedText;
    for (int i = 0; i < Text.length(); i++)
    {
        EncryptedText += Text[i] + 2;
    }
    return EncryptedText;
}

string Decrypte(string Text)
{
    string DecryptedText;
    for (int i = 0; i < Text.length(); i++)
    {
        DecryptedText += Text[i] - 2;
    }
    return DecryptedText;
}

int main(){

    string Text = ReadText();
    string EncryptedText = Encrypte(Text);
    string DecryptedText = Decrypte(EncryptedText);
    cout << EncryptedText << endl;
    cout << DecryptedText << endl;
    return 0;
}
