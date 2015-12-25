#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> par_stack;

        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            switch (*iter) {
                case '(':
                    par_stack.push('(');
                    continue;
                    break;
                case '[':
                    par_stack.push('[');
                    continue;
                    break;
                case '{':
                    par_stack.push('{');
                    continue;
                    break;
                default: 
                    break;
            }

            if (!par_stack.empty()) {
                switch (*iter) {
                    case ')':
                        if (par_stack.top() == '(') {
                            par_stack.pop();
                        } else {
                            return false;
                        }
                        break;
                    case ']':
                        if (par_stack.top() == '[') {
                            par_stack.pop();
                        } else {
                            return false;
                        } 
                        break;
                    case '}':
                        if (par_stack.top() == '{') {
                            par_stack.pop();
                        } else {
                            return false;
                        } 
                        break;
                    default:
                        return false;
                        break; 
                }
            } else {
                return false;
            }
        }
        bool result = false;
        if (par_stack.empty()) {
            result = true;
        }
        return result;
    }
};

int main(void)
{
    Solution s1;
    cout << s1.isValid("()") << endl;;
    return 0;
}
