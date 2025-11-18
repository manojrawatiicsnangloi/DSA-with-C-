#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <string, string> data;
    data["abc@gmail.com"] = "Abc@123";
    data["xyz@gmail.com"] = "Xyz@123";
    data["mmm@gmail.com"] = "Mmm@123";
    
    //
    int i = 1;
    while (i <= 3){
        cout << "Attempt No " << i << "\n";
        i++;
        cout << "Enter your email";
        string email;
        cin >> email;
        cout << "Enter your Password";
        string password;
        cin >> password;

      
            if (data[email] == password){
                cout << "Login Successfully";
                break;
        }
        else{
            cout << "Invalid Info";
        }

    }
    return 0;
}





















// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main() {
//     unordered_map<string, string> users;

//     // Pre-registered users (Signup Database Simulation)
//     users["manoj@gmail.com"] = "pass123";
//     users["rahul@gmail.com"] = "rahul@456";
//     users["admin@gmail.com"] = "admin@999";

//     string inputEmail, inputPass;
//     int attempts = 3;

//     cout << "==============================\n";
//     cout << "       WELCOME TO LOGIN       \n";
//     cout << "==============================\n";

//     while (attempts--) {  // loop runs 3 times max

//         cout << "\nEnter Email: ";
//         cin >> inputEmail;

//         //  First check if email exists
//         if (users.find(inputEmail) == users.end()) {
//             cout << " Email not registered!\n";
//         } 
//         else {
//             cout << "Enter Password: ";
//             cin >> inputPass;
//             //  Now check password
//             if (users[inputEmail] == inputPass) {
//                 cout << "\nLOGIN SUCCESSFUL! Welcome " << inputEmail << "\n";
//                 return 0;  // exit program on success
//             } else {
//                 cout << " Incorrect password!\n";
//             }
//         }

//         // Attempts left message
//         if (attempts > 0)
//             cout << " Attempts Left: " << attempts << "\n";
//         else
//             cout << "\n Too many failed attempts! Account Locked.\n";
//     }

//     return 0;
// }
