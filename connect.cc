/**
 * problem Populating Next Right Pointers in Each Node 
 * link: http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <cmath>
#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode **curlevel = NULL;
        TreeLinkNode **nextlevel = NULL;
        int clevel = 0;
        int clevelcount = 0;

        if (root != NULL) {
            curlevel = new TreeLinkNode*;
            *curlevel = root;
        }
        while(curlevel != NULL) {
            clevelcount = pow(2, clevel);
            nextlevel = new TreeLinkNode *[clevelcount * 2];
            for(int i = 0; i < clevelcount; i++) {
                if(i < clevelcount - 1) {
                    curlevel[i]->next = curlevel[i + 1];
                } 
                nextlevel[2 * i] = curlevel[i]->left;
                nextlevel[2 * i + 1] = curlevel[i]->right;
            }
            // next level
            clevel++;
            delete[] curlevel;
            if(nextlevel[0] == NULL) {
                delete[] nextlevel;
                curlevel = NULL;
            } else {
                curlevel = nextlevel;
            }
        }
    }
};

int main(void)
{
    Solution s1;
    struct TreeLinkNode root(1);
    root.left = new TreeLinkNode(2);
    root.right = new TreeLinkNode(3);
    root.left->left = new TreeLinkNode(4);
    root.left->right = new TreeLinkNode(5);
    root.right->left = new TreeLinkNode(6);
    root.right->right = new TreeLinkNode(7);
    s1.connect(&root);
    cout << root.next << endl;
    cout << root.right->val << endl;
    cout << root.left->next->val << endl;
    
    cout << root.left->left->next->val << endl;
    return 0;
}
