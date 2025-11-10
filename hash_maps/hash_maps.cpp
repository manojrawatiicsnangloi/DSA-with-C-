#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <string, string> data = {{"name" , "Manoj"}, {"email" , "manoj@gmail.com"}};
    for (auto &i : data){
          cout << i.first << " : " << i.second << endl;
    }
    return 0;
}