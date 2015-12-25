#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> memo(size);
        // dp OPT(i) max subarray sum ending with nums[i]
        // OPT(i) = max (nums[i], nums[i] + OPT(i-1))
        // base case
        memo[0] = nums[0];
        int max = memo[0];
        for (int i = 1; i < size; i++) {
            memo[i] = memo[i-1] < 0 ? nums[i]: nums[i] + memo[i-1];
            if (memo[i] > max) {
                max = memo[i];
            }
        }
        return max;
    }
};
