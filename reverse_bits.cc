#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev_n = 0;
        int sz = sizeof(uint32_t) * 8;
        
        for (int i = 0; i < sz; i++) {
            if ((1 << (sz - 1 - i) & n) != 0) {
                rev_n |= (1 << i);
            }
        }
        return rev_n;
    }
};
