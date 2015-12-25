#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> generateParenthesis(int n) {
        std::vector<string> parenthesis;
        if (n == 0) {
           return parenthesis; 
        } else {
            parenthesis.push_back("()");
            n = n - 1;

            while (n > 0) {
                std::vector<string> prts;
                for (auto p : parenthesis) {
                    prts.push_back("(" + p +")");
                    prts.push_back(p + "()");
                }
                parenthesis = prts;
                n = n - 1;
            }
            return parenthesis;
        }
    }
};
