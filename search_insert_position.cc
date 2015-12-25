#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        int array_size = nums.size();
        while (pos < array_size && target > nums[pos]) {
            pos += 1;
        }
        return pos;
    }
};
