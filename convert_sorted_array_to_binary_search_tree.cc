#include <cstddef>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        return sortedArrayToBST_recr(nums, 0, sz-1);
    }
    
    TreeNode* sortedArrayToBST_recr(vector<int>& nums, int i, int j) {
        TreeNode *rt = NULL;
        if (i == j) {
            rt = new TreeNode(nums[i]);
        } else if (i+1 == j) {
            rt = new TreeNode(nums[j]);
            rt->left = new TreeNode(nums[i]);
        } else if (i < j) {
            // j - i >= 2
            int mid = ((i + j) / 2) + ((j - i) % 2);
            rt = new TreeNode(nums[mid]);
            rt->left = sortedArrayToBST_recr(nums, i, mid-1);
            rt->right = sortedArrayToBST_recr(nums, mid+1, j);
        }
        return rt;
    }

    TreeNode* sortedArrayToBST_iter(vector<int>& nums) {
        int sz = nums.size();
        return sortedArrayToBST_recr(nums, 0, sz-1);
    }


};
