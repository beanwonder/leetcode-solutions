#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> records;
        std::stack<TreeNode* > iter_stack;
        TreeNode *iter = root;
        TreeNode *tmp_ptr = NULL;
        
        while (iter) {
            if (iter->left) {
                iter_stack.push(iter);
                tmp_ptr = iter;
                iter = iter->left;
                tmp_ptr->left = NULL;
            } else if (iter->right) {
                iter_stack.push(iter);
                tmp_ptr = iter;
                iter = iter->right;
                tmp_ptr->right = NULL;
            } else {
                records.push_back(iter->val);
                if (!iter_stack.empty()) {
                    iter = iter_stack.top();
                    iter_stack.pop();
                } else {
                    break;
                }
            }
        }

        return records;
    }
};

int main(void)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution s1;
    std::vector<int > records;
    records = s1.postorderTraversal(root);

    for (vector<int >::const_iterator i = records.begin(); i != records.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;

    return 0;
}
