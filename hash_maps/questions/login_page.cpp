#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> users;

    // Pre-registered users (Signup Database Simulation)
    users["manoj@gmail.com"] = "pass123";
    users["rahul@gmail.com"] = "rahul@456";
    users["admin@gmail.com"] = "admin@999";

    string inputEmail, inputPass;
    int attempts = 3;

    cout << "==============================\n";
    cout << "       WELCOME TO LOGIN       \n";
    cout << "==============================\n";

    while (attempts--) {  // loop runs 3 times max

        cout << "\nEnter Email: ";
        cin >> inputEmail;

        //  First check if email exists
        if (users.find(inputEmail) == users.end()) {
            cout << " Email not registered!\n";
        } 
        else {
            cout << "Enter Password: ";
            cin >> inputPass;
            //  Now check password
            if (users[inputEmail] == inputPass) {
                cout << "\nLOGIN SUCCESSFUL! Welcome " << inputEmail << "\n";
                return 0;  // exit program on success
            } else {
                cout << " Incorrect password!\n";
            }
        }

        // Attempts left message
        if (attempts > 0)
            cout << " Attempts Left: " << attempts << "\n";
        else
            cout << "\n Too many failed attempts! Account Locked.\n";
    }

    return 0;
}
