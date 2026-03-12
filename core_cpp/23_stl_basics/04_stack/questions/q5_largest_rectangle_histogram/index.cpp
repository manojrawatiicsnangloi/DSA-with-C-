// q6_min_stack.cpp
// q9_stock_span_problem.cpp
// q10_largest_rectangle_histogram.cpp

// Then optionally:

// q7_sort_stack.cpp
// q8_reverse_stack.cpp

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> stockSpanc(std::vector<int> prices){
    int n = prices.size();
    std::vector<int> span(n);
    std::stack<int> st; // store index
     for(int i = 0; i < n; i++) {
        while(!st.empty() && prices[st.top()] <= prices[i]) {
             st.pop();
        }
        if (st.empty()){
            span[i] = i + 1;
        }
        else {
            span[i] = i - st.top();
        }

        st.push(i);
     }
     return span;
}


int main(){
    std::vector<int> prices = {100,80,60,70,60,75,85};
    std::vector<int> result = stockSpanc(prices);

    for (int i : result){
        std:: cout << i << " ";
    }
    return 0;
}