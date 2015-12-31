class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // cant pass 0 - INT_MAX
        int res = 0 - 1; // 0xFFFFFFFF
        for (int i = m; i <= n; i++) {
            res &= i;
        }
        return res;
    }
    int rangeBitwiseAnd_quick(int m, int n) {
        // find a mask
        // return mask & m
        if (m == n) return m;
        int orx = m ^ n;
        int mask = 1 << 31;
        while (mask != -1) {
            if ((mask & orx) != 0) {
                break;
            } else {
                mask >>= 1;
            }
        }
        return m & (mask << 1);
    }
};
