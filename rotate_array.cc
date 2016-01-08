#include <vector>
using namespace std;

class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        // n square
        int len = nums.size();
        if (len != 0) {
            int kk = k % len;
            int count = len - kk;
            for (int i = 0; i < count; i++) {
                for (int idx = 1; idx < len; idx++) {
                    // exchange idx-1 with idx
                    nums[idx-1] ^= nums[idx];
                    nums[idx] ^= nums[idx-1];
                    nums[idx-1] ^= nums[idx];
                }
            }
        }
    }

    void rotate2(vector<int>& nums, int k) {
        int len = nums.size();
        if (len != 0) {
            std::vector<int> nums_copy(nums);
            int kk = k % len;
            int start = len - kk;
            for (int i = 0; i < len; i++) {
                nums[i] = nums_copy[(start+i) % len];
            }
        }
    }

    void rotate3(vector<int>& nums, int k) {
        // inplace and o(1) space
        // by reverse 3 times
    }
};
