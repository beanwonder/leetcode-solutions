#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> aStack;
        for (int i=0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
                aStack.push(s[i]);
            } else if (s[i] == ')') {
                if (!aStack.empty() && aStack.top() == '(') {
                    aStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!aStack.empty() && aStack.top() == '[') {
                    aStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (!aStack.empty() && aStack.top() == '{') {
                    aStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '>') {
                if (!aStack.empty() && aStack.top() == '<') {
                    aStack.pop();
                } else {
                    return false;
                }
            }
        }

        return aStack.empty();
    }
};

int main(void)
{
    Solution s1;
    cout << s1.isValid("(())<><{}>()(<>{{}}})") << endl;;
    return 0;
}
