#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 1 by sort (quick sort)
        // because of only 0 1 2, 1 is the pivotal
        int sz = nums.size();
        int left = 0;
        int right = sz - 1;

        int pivot = 1;
        exchange(nums, pivot, left, right);

        if (left == right) {
            if (nums[right] > pivot) {
                right = right - 1;
            }
            left = 0;
        } else if (left > right) {
            right = left;
            left = 0;
        }

        pivot = 0;
        exchange(nums, pivot, left, right);
    }

    void exchange(vector<int>& nums, int pivt, int& left, int& right) {
        // left and right must be return to outside
        // <= pivt | > than pivt
        while (left < right) {
            if (nums[left] > pivt && nums[right] <= pivt) {
                // exchange
                nums[left] ^= nums[right];
                nums[right] ^= nums[left];
                nums[left] ^= nums[right];
                left += 1;
                right -= 1;
            }
            if (nums[left] <= pivt) {
                left += 1;
            }
            if (nums[right] > pivt) {
                right -= 1;
            }
        }
    }

    void sortColors_counting_sort(vector<int>& nums) {
            // count sort;
        int colors[3] = {0, 0, 0};
        for (int obj : nums) {
            colors[obj]++;
        }
        
        int cnt = 0;
        for (int idx=0; idx < 3; idx++) {
            for (int i=0; i<colors[idx]; i++) {
                nums[cnt++] = idx;
            }
        }
    }
};
