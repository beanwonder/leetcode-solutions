#include <vector>
#include <queue>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_heap(nums, k);
    }

    int findKthLargest_heap(vector<int>& nums, int k) {
      int sz = nums.size();
      // min heap to keep most larget k elements in array
      priority_queue<int, vector<int>, greater<int>> topK;
      for (int i=0; i < sz; ++i) {
        if (i < k) {
          topK.push(nums[i]);
        } else {
          if (topK.top() < nums[i]) {
            topK.pop();
            topK.push(nums[i]);
          }
        }
      }
      return topK.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_quick_sort(nums, k, 0, nums.size()-1);
    }
    int findKthLargest_quick_sort(vector<int>& nums, int k, int i, int j) {
        // find the k th largest in between index i and index j
        // >= pivot | piovt | < pivot
        // randomly select a index

        int idx = i + (rand() % (j - i + 1));
        int swap(nums[idx], nums[j]);
        int pivot = nums[j];
        int l = i;
        int r = j - 1;
        while (l < r) {
            if (nums[l] <= pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
            } else if (nums[l] > pivot) {
                l += 1;
            } else if (nums[r] <= pivot) {
                r -= 1;
            }
        }
        // jump out when l == r
        int mid;
        // move mid to exact the place where nums[mid] < pivot
        if (nums[l] > pivot) {
            mid = l + 1;
        } else {
            mid = l;
        }
        swap(nums[mid], nums[j]);
        int left_nums = mid - i;
        // int right_nums = j - mid;
        // mid is the 
        if  (left_nums + 1 == k) {
            return nums[mid];
        } else if (left_nums + 1 > k) {
            return findKthLargest_quick_sort(nums, k, i, mid-1);
        } else {
            // right_size + 1 < k
            return findKthLargest_quick_sort(nums, k-(left_nums+1), mid+1, j);
        }
    }
};
