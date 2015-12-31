#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // one number 1, all other 3 times
        int result = 0;
        int counter[sizeof(int) * 8] = {0};
        int int_bits_num = sizeof(int) * 8;
        int sz = nums.size();
        for (int idx = 0; idx < sz; idx++) {
            for (int i = 0; i < int_bits_num; i++) {
                if ((nums[idx] & (1 << i)) != 0) {
                    counter[i]++;
                }
            }
        }
        for (int i = 0; i < int_bits_num; i++) {
            if ((counter[i] % 3) == 1) {
                result |= (1 << i);
            }
        }
        return result;
    }

    int singleNumber_2(vector<int>& nums) {
        // one number 1, all other 3 times
        int result = 0;
        // int counter[sizeof(int) * 8] = {0};
        const int int_bits_num = sizeof(int) * 8;
        int sz = nums.size();
        for (int i = 0; i < int_bits_num; i++) {
            int acc = 0;
            for (int idx = 0; idx < sz; idx++) {
                if ((nums[idx] & (1 << i)) != 0) {
                    acc++;
                }
            }
            if ((acc % 3) == 1) {
                result |= (1 << i);
            }
        }
        return result;
    }
    
    // a general method to find more than every k time except one l times
    // via bit manupulation
    int singleNumber_general(vector<int>& nums, int k, int l) {
        std::vector<int> x(k+1, 0);
        x[0] = ~0;
        for (auto num : nums) {
            for (int i = k; i > 0; i--) {
                x[i] = (x[i-1] & num) | (x[i] & ~num); // x[i] = (x[i-1] & num) | (x[i] & ~(x[i] & num))
            }
            x[0] = x[k] | (x[0] & ~num);
            x[k] = 0; // clear x[k]
        }
        return x[l];
    }
    int singleNumber4(vector<int>& nums) {
        return singleNumber_general(nums, 3, 1);
    }

    int singleNumber3(vector<int>& nums) {
        // improvement to first solution
        // ones twos threes
        // use ones twos threes
        int x0 = ~0, x1 = 0, x2 = 0;
        for (auto num : nums) {
            int x3 = x2 & num;
            x2 = (x1 & num) | (x2 & ~num);
            x1 = (x0 & num) | (x1 & ~num);
            x0 = x3 | (x0 & ~num);
        }
        return x1;
    }
};
