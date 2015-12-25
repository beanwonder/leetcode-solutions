#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int sz = digits.size();
        int pos = sz - 1;
        while (carry && pos >= 0) {
            if (digits[pos] == 9) {
                digits[pos] = 0;
            } else {
                digits[pos] += 1;
                carry = false;
            }
            pos -= 1;
        }
        if (carry) {
            // pos at begin()
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
