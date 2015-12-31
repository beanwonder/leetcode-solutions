#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // hash table o(n) but o(n) space
        // sum 
        //
        int last_item = nums.size();
        int sum = (0 + last_item) * (last_item + 1) / 2;
        for (auto item : nums) {
            sum -= item;
        }
        return sum;
    }
    // or bit operation 
    // tmp = 0 -> tmp ^= i ^ nums[i] -> tmp ^= i;
};
