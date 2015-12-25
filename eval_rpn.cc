#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        int top = -1;
        int *numstack = NULL;
        string element;
        
        numstack = new int[tokens.size()];
        for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i) {
            element = *i;
            if (element == "+") {
                --top;
                numstack[top] = numstack[top] + numstack[top + 1];
            } else if (element == "-") {
                --top;
                numstack[top] = numstack[top] - numstack[top + 1];
            } else if (element == "*") {
                --top;
                numstack[top] = numstack[top] * numstack[top + 1];
            } else if (element == "/") {
                --top;
                numstack[top] = numstack[top] / numstack[top + 1];
            } else {
                ++top;
                numstack[top] = atoi(element.c_str());
            }
        }        
        if (top == 0) {
            result = numstack[top];
        }
        return result;
    }
};

int main(void)
{
    Solution s1;
    std::vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    cout << s1.evalRPN(tokens) << endl;
    return 0;
}
