#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> slots(n, false);
        vector<string> sol(n, string(n, '.'));
        solveNQueens_backtracing(res, sol, slots, 0, n);
        return res;
    }

    void solveNQueens_backtracing(vector<vector<string>> &res, vector<string> &sol,
                                  vector<bool> &slots, int layer, int &n) {
        // layer start from 0
        if (layer < n) {
            for (int i = 0; i < n; i++) {
                if (isValid(sol, slots, layer, i, n)) {
                    // string line = string(i, '.') + "Q" + string(n-1-i, '.');
                    sol[layer][i] = 'Q';
                    slots[i] = true;
                    solveNQueens_backtracing(res, sol, slots, layer+1, n);
                    sol[layer][i] = '.';
                    slots[i] = false;
                }
            }
        } else {
            // terminate when layer == n
            res.push_back(sol);
        }
    }

    bool isValid(vector<string> &sol, vector<bool>& slots, int layer, int i, int &n) {
        bool ret = false;
        if (!slots[i]) {
            ret = true;
            for (int cnt=1; cnt <= layer; ++cnt) {
                if (i-cnt > -1 && i+cnt < n) {
                    if (sol[layer-cnt][i-cnt] == 'Q' || sol[layer-cnt][i+cnt] == 'Q') {
                        ret = false;
                        break;
                    }
                } else if (i-cnt > -1) {
                    if (sol[layer-cnt][i-cnt] == 'Q') {
                        ret = false;
                        break;
                    }
                } else if (i-cnt < n) {
                    if (sol[layer-cnt][i+cnt] == 'Q') {
                        ret = false;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    s.solveNQueens(2);
    auto a = s.solveNQueens(9);
    return 0;
}
