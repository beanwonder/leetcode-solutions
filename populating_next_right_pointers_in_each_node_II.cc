//
// Created by Zhebin Shen on 11/14/16.
//


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <cstdlib>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur_level = root;
        while (cur_level) {
            TreeLinkNode* cur = cur_level;
            cur_level = NULL;
            while (cur) {
                while (cur && !cur->left && !cur->right) {
                    cur = cur->next;
                }
                TreeLinkNode* it = NULL;
                if (cur) {
                    if (cur->left && cur->right) {
                        cur->left->next = cur->right;
                        it = cur->right;
                        if (!cur_level) {
                            cur_level = cur->left;
                        }
                    } else if (cur->left) {
                        it = cur->left;
                        if (!cur_level) {
                            cur_level = cur->left;
                        }
                    } else if (cur->right) {
                        it = cur->right;
                        if (!cur_level) {
                            cur_level = cur->right;
                        }
                    } else {
                        // should not happening
                    }

                    cur = cur->next;
                    while (cur && !cur->left && !cur->right) {
                        cur = cur->next;
                    }
                    if (cur) {
                        if (cur->left) {
                            it->next = cur->left;
                        } else if (cur->right) {
                            it->next = cur->right;
                        }
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode rt(0);
    s.connect(&rt);
    return 0;
}