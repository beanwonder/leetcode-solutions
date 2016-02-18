#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        
        int i = 0;
        int j = size;
        while (j > i+1) {
            int mid = (i + j) / 2;
            // elements are unique
            if (nums[mid] <= nums[i]) {
                j = mid;
            } else if (nums[mid] > nums[i]) {
                i = mid;
            }
        }
        
        int start_pos = j % size;
        i = 0;
        j = size - 1;
        while (i <= j) {
            int mid = (((i + j) / 2) + start_pos) % size;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                j = (i + j) / 2 - 1;
            } else {
                i = (i + j) / 2 + 1;
            }
        }
        return -1;
    }
};
