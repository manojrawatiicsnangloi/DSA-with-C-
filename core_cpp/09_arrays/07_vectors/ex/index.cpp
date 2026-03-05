#include <iostream>
#include <vector>

int main(){
    std::vector<std::vector<int>> m = {
        {1, 2, 3},
        {11, 12, 13},
        {15, 22, 33}
    };

    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[i].size(); j++){
            std::cout << m[i][j] << " ";       
        }
        std::cout<< "\n";
    }

    return 0;
}