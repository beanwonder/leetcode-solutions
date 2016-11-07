//
// Created by Zhebin Shen on 11/6/16.
//


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    bool match(char p, char ch) {
        if ((ch >= 'a' && ch <= 'z' && p == 'L')
            || (ch >= 'A' && ch <= 'Z' && p == 'U')
            || (ch >= '0' && ch <= '9' && p == 'D')) {
            return true;
        }
        return false;
    }

    string find_longest_repeating_pattern(string pattern, string s) {

        vector<int> match_pos;
        int s_len = s.size();
        int p_len = pattern.size();

        // first basic string search of the pattern
        for (int i = 0; i <= s_len - p_len; ++i) {
            bool match_pattern = true;
            for (int cur = 0; cur < p_len; ++cur) {
                if (!match(pattern[cur], s[i + cur])) {
                    match_pattern = false;
                    break;
                }
            }
            if (match_pattern) {
                match_pos.push_back(i);
            }
        }


        if (match_pos.empty()) return "pattern not found";
        // each match pos at least one repeat
        vector<int> memo(match_pos.size(), p_len);
        // BC
        int max = p_len;
        int start = match_pos.back();
        // merge positions
        for (int i = match_pos.size() - 1; i >= 0; --i) {
            if (i < match_pos.size() - 1) {
                if (match_pos[i] + p_len == match_pos[i + 1]) {
                    memo[i] = memo[i + 1] + p_len;
                }
            }
            if (memo[i] >= max) {
                max = memo[i];
                start = match_pos[i];
            }
        }

        return s.substr(start, max);

    }
};


int main() {

    Solution s;
    cout << s.find_longest_repeating_pattern("DLU", "abcd_a1zAdaAb") << endl;
    cout << s.find_longest_repeating_pattern("D", "aaaa") << endl;
    cout << s.find_longest_repeating_pattern("LUD", "aA1") << endl;
    cout << s.find_longest_repeating_pattern("D", "a11a") << endl;
    cout << s.find_longest_repeating_pattern("U", "aAAaa") << endl;
    cout << s.find_longest_repeating_pattern("LUD", "zZ1_example_aA1bB2c") << endl;

    return 0;
}