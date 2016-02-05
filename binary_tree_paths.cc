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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        
        binaryTreePaths_recr(res, root, "");
        return res;
    }
    
    void binaryTreePaths_recr(vector<string>& res, TreeNode* root, string path) {
        path += to_string(root->val);
        if (!(root->left) && !(root->right)) {
            res.push_back(path);
        } else if (!(root->right)) {
            path += "->";
            binaryTreePaths_recr(res, root->left, path);
        } else if (!(root->left)) {
            path += "->";
            binaryTreePaths_recr(res, root->right, path);
        } else {
            // both not NULL
            path += "->";
            binaryTreePaths_recr(res, root->left, path);
            binaryTreePaths_recr(res, root->right, path);
        }
    }
};
