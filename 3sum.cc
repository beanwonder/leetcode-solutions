#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int target = 0;
        std::vector<vector<int> > triples;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            int num1 = nums[i];
            if (num1 > 0) {
                break;
            }
            if ((i != 0) && (num1 == nums[i-1])) {
                continue;
            }
            for (int j = i+1; j < sz; j++) {
                int num2 = nums[j];
                if (num1 + num2 > 0) {
                    break;
                }
                if ((j != i+1) && num2 == nums[j-1]) {
                    continue;
                }
                for (int k = j+1; k < sz; k++) {
                    int num3 = nums[k];
                    if (num1 + num2 + num3 > 0) {
                        break;
                    }
                    if ((k != j+1) && num3 == nums[k-1]) {
                        continue;
                    }
                    if (num1 + num2 + num3 == target) {
                        std::vector<int> triple(3);
                        triple[0] = num1;
                        triple[1] = num2;
                        triple[2] = num3;
                        triples.push_back(triple);
                    }
                }
            }
        }
        return triples;
    }

    vector<vector<int>> threeSum_two_pointer(vector<int>& nums) {
        int target = 0;
        std::vector<vector<int>> res;
        const int ss = nums.size();
        if (ss < 3) return res;

        sort(nums.begin(), nums.end());
        // two pointer
        for (int i = 0; i < ss; i++) {
            if ((i > 0) && (nums[i-1] == nums[i])) {
                continue;
            }
            int l = i + 1;
            int r = ss - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) {
                    std::vector<int> triple = {nums[i], nums[l], nums[r]};
                    res.emplace_back(triple);
                    l += 1;
                    r -= 1;
                } else if (sum < target) {
                    l += 1;
                } else {
                    // sum < target
                    r -= 1;
                }
                while ((l > i+1) && (l < r) && (nums[l-1] == nums[l])) {
                    l += 1;
                }
                while ((r < ss-1) && (l < r) && (nums[r] == nums[r+1])) {
                    r -= 1;
                }
            }
        }
        return res;
    }
};
