#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestsum;
        int ss = nums.size();

        sort(nums.begin(), nums.end());
        closestsum = nums[0] + nums[1] + nums[2];
        for (int idx = 0; idx < ss; idx++) {
            int i = idx + 1, j = ss - 1;
            while (i < j) {
                int sum = nums[idx] + nums[i] + nums[j];
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    if (target - sum < abs(target - closestsum)) {
                        closestsum = sum;
                    }
                    i += 1;
                } else {
                    // sum > target
                    if (sum - target < abs(target - closestsum)) {
                       closestsum = sum; 
                    }
                    j -= 1;
                }
            }
        }
        return closestsum;
    }
};
