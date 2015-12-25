#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates_by_sort(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 0;
        if (sz < 2) return sz;
        int item = nums[0];
        for (int i = 1; i < sz; i++) {
            if (item == nums[i]) {
                cnt += 1;
                item = nums[i];
                nums[i] = INT_MAX;
            } else {
                item = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        return sz - cnt;
    }

    int removeDuplicates(vector<int>& nums) {
        // count how many nums are not dup now
        int sz = nums.size();
        if (sz < 2) return sz;

        int cnt = 1;
        int tmp = nums[0];
        for (int i = 1; i < sz; i++) {
            if (tmp != nums[i]) {
                tmp = nums[i];
                if (cnt != i) {
                    nums[cnt] = tmp;
                }
                cnt += 1;
            }
        }
        return cnt;
    }
};
