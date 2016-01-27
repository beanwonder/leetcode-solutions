#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 0) return 0;

        int maxPdPrev = nums[0];
        int minPdPrev = nums[0];
        int maxPd = nums[0];

        // calculate maxPd for each subarray ending with i
        for (int i = 1; i < sz; i++) {
            if (nums[i] >= 0) {
                // not affect order
                maxPdPrev = max(maxPdPrev * nums[i], nums[i]);
                minPdPrev = min(minPdPrev * nums[i], nums[i]);
            } else {
                int maxPdPrevTmp = maxPdPrev;
                maxPdPrev = max(minPdPrev * nums[i], nums[i]);
                minPdPrev = min(maxPdPrevTmp * nums[i], nums[i]);
            }
            if (maxPd < maxPdPrev) {
                maxPd = maxPdPrev;
            }
        }
        return maxPdPrev;
    }

};
