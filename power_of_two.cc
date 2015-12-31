class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }  else if (n == 1) {
            return true;
        } else {
            return (n % 2) == 1 ? false : isPowerOfTwo(n/2);
        }
    }

    bool isPowerOfTwo2(int n) {
        // bit manupulaiton version
        int res = false;
        while (n != 0) {
            bool lowest = ((1 & n) == 1);
            n = n >> 1;
            if (lowest && n == 0) {
                res = true;
            } else if (lowest) {
                // lowest == 1 and some other bit = 1i
                break;
            }  
        }
        return res;
    }
};
