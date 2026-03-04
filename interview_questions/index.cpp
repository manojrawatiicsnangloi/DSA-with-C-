#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solution(int n, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // write your solution here
        vector<int> res;
        return res;
    }
};


/**
R E A D M E
DO NOT CHANGE the code below, we use it to grade your submission. If changed your submission will be failed automatically.
**/
int main()
{
    string line;
    getline(cin, line);
    istringstream is(line);
    string n;
    is >> n;
  
    string line2;
    getline(cin, line2);
    vector<vector<int>> mtx;
    stringstream ss1(line2.substr(2, line2.size() - 4));
    string segment;
    while (getline(ss1, segment, ']')) {
        stringstream row_ss(segment.substr(segment[0] == ',' ? 2 : 0));
        string number;
        vector<int> row;
        while (getline(row_ss, number, ',')) {
            row.push_back(stoi(number));
        }
        mtx.push_back(row);
    }

    
    string line3;
    getline(cin, line3);
     
    vector<vector<int>> mtx2;
    stringstream ss2(line3.substr(2, line3.size() - 4));
    string segment2;
    while (getline(ss2, segment2, ']')) {
        stringstream row_ss(segment2.substr(segment[0] == ',' ? 2 : 0));
        string number;
        vector<int> row;
        while (getline(row_ss, number, ',')) {
            row.push_back(stoi(number));
        }
        mtx2.push_back(row);
    }

    Solution solution;
    vector<int> output = solution.solution(stoi(n), mtx, mtx2);

    std::cout << "[";
    for(size_t i = 0; i < output.size(); ++i)
    {
        std::cout << output[i] ;
        if (i != output.size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << endl;
    return 0;
}
