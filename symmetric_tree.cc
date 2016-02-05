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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        } else {
            return isSymmetric_recr(root->left, root->right);
        }
    }

    bool isSymmetric_recr(TreeNode *rt1, TreeNode *rt2) {
        if (rt1 != NULL & rt2 != NULL) {
            if (rt1->val == rt2->val) {
                return isSymmetric_recr(rt1->left, rt2->right) && isSymmetric_recr(rt1->right, rt2->left);
            } else {
                return false;
            }
        } else if (!rt1 && !rt2) {
            return true;
        } else {
            return false;
        }
    }

    bool isSymmetric_iter(TreeNode* root) {
        
    }
};
