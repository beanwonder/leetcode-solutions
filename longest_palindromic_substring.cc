#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //int start_pos = 0;
        int max_len;
        string max_string;
        size_t str_len = s.size();
        // palindrome center
        if (str_len > 1) {
            // check centered with s[i]
            int max_len1 = 1;
            int start_pos1 = 0;
            for (int i = 0; i < (int)str_len; ++i) {
                int offset = 1;
                int count = 0;
                //int sub_pali_len = 0; // one char considered a paliindrome 
                while ((i + offset < (int)str_len && i - offset >= 0) && (s[i+offset] == s[i-offset])) {
                    offset++;
                    count++;
                }
                if ((count*2+1) > max_len1) {
                    start_pos1 = i - count;
                    max_len1 = count * 2 + 1;
                }
            }

            int start_pos2 = 0;
            int max_len2 = 0;
            // check centered with s[i] and s[i+1]
            for (int i = 0; i < (int)str_len; ++i) {
                int offset = 0;
                while ((i - offset >= 0 && i + 1 + offset < (int)str_len) && s[i-offset] == s[i+1+offset]) {
                    offset++;
                }
                if ((2*offset > max_len2)) {
                    start_pos2 = i - (offset - 1);
                    max_len2 = 2 * offset;
                }
            }
            if (max_len1 > max_len2) {
                max_string = s.substr(start_pos1, max_len1);
            } else if (max_len1 < max_len2) {
                max_string = s.substr(start_pos2, max_len2);
            }  
        } else {
           max_len = str_len; 
           max_string = s;
        }
        return max_string;
    }

};
