#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map <string, string> data = {{ "name", "abc"}, {"email", "abc@gmail.com"}};
    // cout << data["name"];
    // cout << data["email"];
    // data["city"] = "Delhi";

    // for (auto &i : data){
    //     cout << i.first << " : " << i.second << "\n";
    // }
        int sum = 0;
        for (char ch : "name") {
            cout << ch;
            int a = ch;
            cout << a << "\n";
            sum += ch;
        }
        // cout << sum;
}



// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int main(){
//     unordered_map <string, string> data = {{"name" , "Manoj"}, {"email" , "manoj@gmail.com"}};
//     for (auto &i : data){
//           cout << i.first << " : " << i.second << endl;
//     }
//     return 0;
// }