#include <iostream>
#include <vector>
#include <unordered_map>
          
int main(){
    std::vector<int> arr = {4, 1, 2, 4, 3, 2, 1};
    std::unordered_map<int, int> fq;
    for (int i : arr){
        fq[i]++;
    }

    for (auto p : fq){
        std::cout << p.first << " : " << p.second << "\n";
    }

    return 0;
}