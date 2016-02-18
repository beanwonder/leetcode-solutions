#include <cstddef>
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
    int kthSmallest(TreeNode* root, int k) {
        int val;
        int n = 0;
        kthsmallest_dfs(root, n, k, val);
        return val;
    }
    
    void kthsmallest_dfs(TreeNode* root, int &n, int &k, int &val) {
        if (root && n < k) {
            kthsmallest_dfs(root->left,  n, k, val);
            n += 1;
            if (n == k) {
                val = root->val;
                return;
            }
            kthsmallest_dfs(root->right, n, k, val);
        }
    }
    
};
