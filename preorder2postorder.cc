#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> bst_preorder2postorder(vector<int> preorder) {
        vector<int> postorder;
        if (preorder.empty()) return postorder;
        bst_preorder2postorder_recr(preorder, postorder, 0, preorder.size()-1);
        return postorder;
    }

    void bst_preorder2postorder_recr(vector<int>& preorder,
                                     vector<int>& postorder, int i, int j) {
        int rt = preorder[i];
        int k;
        for (k = i+1; k <= j; ++k) {
            if (preorder[k] > rt) {
                break;
            }
        }
        if (k > i+1) {
            bst_preorder2postorder_recr(preorder, postorder, i+1, k-1);
        }
        if (k <= j) {
            bst_preorder2postorder_recr(preorder, postorder, k, j);
        }
        postorder.push_back(rt);
    }
};


int main() {
    Solution s;
    string w;
    int64
    while (cin >> w) {
        cout << w;
    }
    cout << '\n';
    auto a = s.bst_preorder2postorder(vector<int> {5, 3, 1, 4, 7, 6, 8});
    return 0;
}