#include <string>
using namespace std;

class Solution {
public:
    inline bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    inline bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char lch = s[l];
            char rch = s[r];
            if (!isLetter(lch) && !isNumber(lch)) {
                l += 1;
                continue;
            }
            if (!isLetter(rch) && !isNumber(rch)) {
               r -= 1; 
               continue;
            }

            int difference = lch - rch;
            if (isNumber(lch) && isNumber(rch)) {
                if (lch == rch) {
                    l += 1;
                    r -= 1;
                } else {
                    return false;
                }
            } else if (!isNumber(lch) && !isNumber(rch)){
                if (difference == 0 || difference == 32 || difference == -32) {
                    l += 1;
                    r -= 1;
                } else {
                    return false;
                }
            } else {
                return false;
            }
            
        }
        return true;
    }
};
