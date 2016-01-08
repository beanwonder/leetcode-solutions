#include <vector>
using namespace std;

class Solution {
public:
    void merge_copy(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums3;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    nums3.push_back(nums1[i++]);
                } else {
                    nums3.push_back(nums2[j++]);
                }
            } else if (i < m) {
                nums3.push_back(nums1[i++]);
            } else {
                // j < n
                nums3.push_back(nums2[j++]);
            }
        }
        nums1 = nums3;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (pos > -1) {
            if (i > -1 && j > -1) {
                if (nums1[i] > nums2[j]) {
                    nums1[pos--] = nums1[i--];
                } else {
                    nums1[pos--] = nums2[j--];
                }
            } else if (i > -1) {
                nums1[pos--] = nums1[i--];
            } else {
                // j > -1
                nums1[pos--] = nums2[j--];
            }
        }
    }

};

