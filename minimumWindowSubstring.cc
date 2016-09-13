#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;


class Solution {
public:


    string minWindow(string s, string t) {
        // used to check if it is a valid window
        int m[256] = {0};

        // init map
        for (auto c : t) {
            m[c] += 1;
        }

        int counter = t.size();
        int l = 0;
        int r = 0;
        int min_start = -1;
        int min_len = -1;

        while (r < s.size()) {
            if (m[s[r]] > 0) {
                counter -= 1;
            }
            m[s[r]] -= 1;
            r += 1;

            while (counter == 0) {
                // l .. r be a valid window
                if (min_len == -1 || r - l < min_len) {
                    min_start = l;
                    min_len = r - l;
                }
                // and shrink
                m[s[l]] += 1;
                if (m[s[l]] > 0) {
                    counter += 1;
                }
                l += 1;
            }
        }

        if (min_start == -1) {
            return "";
        }
        return s.substr(min_start, min_len);
    }



    string minWindow_slow(string s, string t) {
        unordered_map<char, int> letter_count;
        unordered_map<char, int> letter_count_tmp;
        // initialize map
        for (auto c : t) {
            letter_count_tmp[c] = 0;
            if (letter_count.find(c) != letter_count.end()) {
               letter_count[c] += 1; 
            } else {
                letter_count[c] = 1;
            }
        }

        // two pointer
        string::size_type l = 0;
        string::size_type r = 0;
        string min_window = "";
        
        while (r < s.size()) {
            // begin with uncovered state
            if (letter_count.find(s[r]) != letter_count.end()) {
                letter_count_tmp[s[r]] += 1;

                // shrink window
                while (check_coverage(letter_count_tmp, letter_count)) {
                    while (letter_count.find(s[l]) == letter_count.end()) {
                        l += 1;
                    }
                    string cur_window = s.substr(l, r - l + 1);
                    if (min_window == "" || cur_window.size() < min_window.size()) {
                        min_window = cur_window;
                    }

                    // shrink this letter will casue shrink a letter in t
                    letter_count_tmp[s[l]] -= 1;
                    l += 1;
                }
            }
            r += 1;
        }
        return min_window;
    }

private:
    bool check_coverage(const unordered_map<char, int>& sample, 
                        const unordered_map<char, int>& standard) const {
        for (auto p : standard) {
            if (sample.at(p.first) < p.second) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution s;

    s.minWindow("ab", "abc");
    assert(s.minWindow("a", "a") == "a");
    assert(s.minWindow("a", "b") == "");
    string str = s.minWindow("ADOBECODEBANC", "ABC");
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(s.minWindow("abcdefg", "bd") == "bcd");

    return 0;
}