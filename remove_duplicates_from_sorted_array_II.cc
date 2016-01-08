#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer
        int len = nums.size();
        if (len < 2) return len;
        // cnt current keeped cnt, 
        // cur: moving pointer, cur_cnt,
        // moving cur's element count
        int ele_cnt = 1, cur = 1, cur_cnt = 1;

        while (cur < len) {
            if (nums[cur-1] == nums[cur]) {
                cur_cnt++;
            } else {
                cur_cnt = 1;
            }

            if (cur_cnt <= 2) {
                nums[ele_cnt++] = nums[cur++];
            } else {
                // > 2 skip
                cur++;
            }
        }

        return ele_cnt;
    }
};
