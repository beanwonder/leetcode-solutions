#include <stddef.h>
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
    void flatten(TreeNode* root) {
        if (root) { 
            flatten_recr(root);
        }
    }

    TreeNode* flatten_recr(TreeNode* root) {
        // alway return the leaf
        if (!(root->left) && !(root->right)) {
            // l == null and r == null
            // do nothing return the root
            return root;
        } else if (!(root->left)) {
            // l == null
            return flatten_recr(root->right);
        } else if (!(root->right)) {
            // r == null
            root->right = root->left;
            // 
            root->left = NULL;
            return flatten_recr(root->right);
        } else {
            TreeNode *l_leaf = flatten_recr(root->left);
            TreeNode *r_leaf = flatten_recr(root->right);
            l_leaf->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return r_leaf;
        }
    }
};
