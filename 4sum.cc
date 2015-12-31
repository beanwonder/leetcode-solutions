#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<vector<int>> res;
        const int ss = (const int) nums.size();
        if (ss < 4) return res;

        // unique res
        // never do optimization too early
        sort(nums.begin(), nums.end());
        for (int i = 0; i < ss; i++) {
            if (i != 0 && nums[i-1] == nums[i]) {
                continue;
            }
            for (int j = i+1; j < ss; j++) {
                if (j != i+1 && nums[j-1] == nums[j]) {
                    continue;
                }
                int left = j + 1;
                int right = ss - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        std::vector<int> quadruplet = {nums[i], nums[j], nums[left], nums[right]};
                        res.emplace_back(quadruplet);
                        left += 1;
                        right -= 1;
                    } else if (sum < target) {
                        left += 1;
                    } else {
                        // sum < target
                        right -= 1;
                    }
                    while ((left > j+1) && (left < right) && nums[left-1] == nums[left]) {
                        left += 1;
                    }
                    while ((right < ss-1) && (left < right) && nums[right] == nums[right+1]) {
                        right -= 1;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, -2, -5, -4, -3, 3, 3, 5};
    auto res = s.fourSum(A, -11);

    return 0;
}
