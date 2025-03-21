#include <iostream>
#include <string>
using namespace std;



string ReadString() {
    string str;
    cout << "Please Enter Your String?\n";
    getline(cin, str);
    return str;
}


int CountSmallLetterString(string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (islower(str[i])) {
            count++;
        }
    }
    return count;
}


int  CountCapitalLetterString(string str) {
   int counter = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
            counter++;
        }
    }
    return counter;
}


int CountStringLength(string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        count++;
    }
    return count;
}








int main() {

    string str = ReadString();
    int count = CountStringLength(str);
    cout << "\nString Length is : " << count << endl;
    count = CountSmallLetterString(str);
    cout << "\nString Small Letters count is : " << count << endl;
    count = CountCapitalLetterString(str);
    cout << "\nString Capital Letters count is : " << count << endl;
    system("pause>0");
}