#include <iostream>
#include <string>
using namespace std;

string ReadPinCode() {
    string PinCode;
    cout << "Enter your pin code: ";
    cin >> PinCode;
    return PinCode;
}

bool Login() {
    string PinCode;

    do {
        PinCode = ReadPinCode();
        if (PinCode == "1234") {
            return true;
        } else {
            cout << "Wrong Pin Code, please try again" << endl;
        }
    } while (PinCode != "1234");

    return false; // Cette ligne ne sera jamais atteinte
}

int main() {
    if (Login()) {
        cout << "Login successful" << endl;
    } else {
        cout << "Login failed" << endl;
    }
    return 0;
}
