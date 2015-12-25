#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> records;
        traversal_aux(root, records);
        return records;
    }

    void traversal_aux(TreeNode *&root, std::vector<int> &records) {
        if (root != NULL) {
            records.push_back(root->val);
            traversal_aux(root->left, records);
            traversal_aux(root->right, records);
        }
    }
};
