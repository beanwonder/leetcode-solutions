#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        int N = nums.size();
        permute_recr(perms, nums, N);
        return perms;
    }
    
    void permute_recr(vector<vector<int>>& perms, vector<int>& nums, int N) {
        // permute [0 .. N-1] in nums
        if (N <= 1) {
            perms.push_back(nums);
        } else {
            for (int i=0; i < N; i++) {
                swap(nums, i, N-1);
                permute_recr(perms, nums, N-1);
                swap(nums, i, N-1);
            }
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        // only tmp swap works
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
