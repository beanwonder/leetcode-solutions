#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_naive(string s) {
        int cur_pos = 0, cur_count = 0,
            longest_pos = 0, longest_count = 0;

        if (s.size() > 0) {
            cur_pos = 0;
            cur_count = 1;
            longest_pos = cur_pos;
            longest_count = cur_count;
        }

        while (cur_pos + cur_count < (int)s.size()) {
            // check occurence of next char in the previous string
            // s.substr(cur_pos, cur_count).find_first_of(s[cur_pos + cur_count], 0) 
            size_t ch_offset_at_substr = s.substr(cur_pos, cur_count).find_first_of(s[cur_pos + cur_count], 0);
            if (ch_offset_at_substr == string::npos) {
                ++cur_count;
            } else {
                // the find string in previous pos offset + 1 is the next search pos
                cur_pos = cur_pos + ch_offset_at_substr + 1;
                cur_count = 1;
            }

            if (cur_count > longest_count) {
                longest_pos = cur_pos;
                longest_count = cur_count;
            }
        }

        return longest_count;
    }
   
    int lengthOfLongestSubstring(string s) {
        int last_pos[256];
        int max = 0;
        if (s.size() > 0) {
            std::vector<int> max_length(s.size(), 1);
            for (int i = 0; i < 256; i++) {
                last_pos[i] = -1;
            } 
            last_pos[s[0]] = 0;
            for (size_t i = 1; i < s.size(); i++) {
                if (last_pos[s[i]] == -1) {
                    max_length[i] += max_length[i-1];
                } else {
                    if (last_pos[s[i]] < i - max_length[i-1]) {
                        max_length[i] = max_length[i-1] + 1;
                    } else {
                        max_length[i] = i - last_pos[s[i]];
                    }
                }
                last_pos[s[i]] = i;
            }
            for (auto l : max_length) {
                max = l > max ? l : max;
            }
        }
        return max;
    }
};

int main(void)
{
    Solution solun;
    string s1 = "abcabcabc";

    return 0;
}
