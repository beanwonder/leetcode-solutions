#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int cnt = 0;
        int slw = 0;
        int fst = 0;
        while (fst < len) {
            if (nums[fst] == val) {
                fst++;
                cnt += 1;
            } else {
                nums[slw++] = nums[fst++];
            }
        }
        return len - cnt;
    }
    int removeElement_out_of_order(vector<int>& nums, int val) {
        // exchange order
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int cnt = 0;
        while (left <= right) {
            if (nums[left] != val) {
                left += 1;;
            } else {
                // when nums[left] == val
                if (nums[right] != val) {
                    nums[left] = nums[right];
                    cnt++; // the count the left one
                    right--;
                } else {
                    // when nums[right] == val
                    cnt++;
                    right--;
                }
            }
            
        }
        return len - cnt;
    }
};
