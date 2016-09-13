#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> closest_right_pair(s.size(), 0);
        stack<int> ss;
        for (int i = 0; i < closest_right_pair.size(); ++i) {
            if (s[i] == '(') {
                ss.push(i);
                closest_right_pair[i] = i;
            } else {
                // s[i] == ')'
                if (!ss.empty()) {
                    closest_right_pair[i] = ss.top();
                    ss.pop();
                } else {
                    // -1 not exists
                    closest_right_pair[i] = -1;
                }
            }
        }
        
        // longest parenthese ending with i th element
        // BC memo[0] = 0
        vector<int> memo(s.size(), 0);
        int max = 0;
        for (int i = 1; i < memo.size(); ++i) {
            if (closest_right_pair[i] == -1 || s[i] == '(') {
                memo[i] = 0;
            } else {
                // s[i] == ')'
                memo[i] = i - closest_right_pair[i] + 1 + memo[closest_right_pair[i] - 1];
                if (memo[i] > max) {
                    max = memo[i];
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(string("(((()")) << endl;
}
