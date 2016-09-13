#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // DP solution
        vector<vector<bool>> match(s.size()+1, vector<bool> (p.size()+1, false));
        // BC: [0, 1:p.len] false
        // BC: [1:s.len ,0] false
        // [0, 0] true

        match[0][0] = true;
        for (int i = 2; i < (int) p.size() + 1; i += 2) {
            // int i_ch = i - 1;
            if (p[i-1] == '*' && match[0][i-2]) {
                match[0][i] = true;
            }
        }

        for (int i = 1; i < (int) s.size() + 1; i++) {
            for (int j = 1; j < (int) p.size() + 1; j++) {
                int i_ch = i - 1;
                int j_ch = j - 1;
                if (match[i][j-1] && p[j_ch] == '*' && charMatch(s[i_ch], p[j_ch-1])) {
                   match[i][j] = true; 
                } else if (j >= 2 && match[i-1][j] && p[j_ch] == '*' && charMatch(s[i_ch], p[j_ch-1])) {
                    match[i][j] = true;
                } else if (match[i-1][j-1] && (charMatch(s[i_ch], p[j_ch]) || (p[j_ch] == '*' && charMatch(s[i_ch], p[j_ch-1])))) {
                    match[i][j] = true;
                } else if (j >= 2 && p[j_ch] == '*' && match[i][j-2]) {
                    // * match zero previous char
                    match[i][j] = true;
                }
            }
        }
        // last one in matrix
        return match[s.size()][p.size()];
    }

    bool charMatch(char s, char p) {
        return p == '.' || s == p;
    }
};

int main(void) {

    Solution s;

    s.isMatch("a", "b*");


    assert(s.isMatch("abcdefg", "abcdefg"));
    assert(s.isMatch("a", "a"));
    assert(s.isMatch("a", "."));
    assert(s.isMatch("z", "."));
    assert((s.isMatch("a", "a3*")));
    assert(s.isMatch("", "b*"));
    assert(s.isMatch("a", "b") == false);
    assert(s.isMatch("a", "b*") == false);
    assert(s.isMatch("abcdeeeefg", "ab*c*d*eeeefg"));


    assert(s.isMatch("aa","a") == false);
    assert(s.isMatch("aa","aa"));
    assert(s.isMatch("aaa","aa") == false);
    assert(s.isMatch("aa", "a*"));
    assert(s.isMatch("aa", ".*"));
    assert(s.isMatch("ab", ".*"));
    assert(s.isMatch("aab", "c*a*b"));

    assert(s.isMatch("a", "aa*"));
    return 0;
}
