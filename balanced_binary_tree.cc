#include <iostream>
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
    inline bool abs_less_than_one(int x) {
        if (x < 0) {
            x =  -x;
        }
        return x <= 1;
    }
    bool isBalanced_recr(TreeNode* root, int *h) {
        int lh = 0, rh = 0;
        bool lt = true, rt = true;
        if (root != NULL) {
           lt = isBalanced_recr(root->left, &lh);
           rt = isBalanced_recr(root->right, &rh);
           *h = (lh > rh ? lh : rh) + 1;
        } else {
            // root = NULL
            *h = 0;
        } 
        return lt && rt && abs_less_than_one(lh - rh);
    }

    bool isBalanced(TreeNode* root) {
        int lh = 0, rh = 0;
        bool lt = true, rt = true;
        if (root != NULL) {
            lt = isBalanced_recr(root->left, &lh);
            rt = isBalanced_recr(root->right, &rh);
        }
        return lt && rt && abs_less_than_one(lh - rh);
    }
};
