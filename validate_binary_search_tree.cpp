#include <cstddef>

//
// Created by Zhebin Shen on 1/30/16.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int *cur = NULL;
        return isValidBST_recr(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST_recr(TreeNode* root, long lb, long hb) {
        if (root) {
            return (root->val < hb && root->val > lb) &&
                   isValidBST_recr(root->left, lb, root->val) &&
                   isValidBST_recr(root->right, root->val, hb);
        } else {
            return true;
        }
    }
};

int main() {
    Solution s;
    TreeNode rt(1);
    TreeNode left_rt(1);
    rt.right = &left_rt;
    s.isValidBST(&rt);
}