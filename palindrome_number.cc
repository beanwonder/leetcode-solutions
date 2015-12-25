#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome_1(int x) {
        string s = to_string(x);
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                break;
            }
        }
        return i >= j;
    }

    bool isPalindrome(int x) {
        // reverse number and compare
        bool result = false;
        int tmp_x = x;
        if (tmp_x >= 0) {
            // reverse x
            //unsigned int reversed_x = 0;
            while (tmp_x > 0) {
                reversed_x = reversed_x * 10 + (tmp_x % 10);
                tmp_x /= 10;
            }
            printf("%u\n", reversed_x);
            if ((unsigned int)x == reversed_x) {
                result = true;
            }
            
        }
        return result;
    }
};

int main(void)
{
    Solution s1;
    s1.isPalindrome(12);
    return 0;
}
