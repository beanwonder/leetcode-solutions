#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
       int total = 0;
       vector<vector<bool>> solution(n, vector<bool> (n, false));
       totalNQueens_dfs(total, 0, n, solution);
       return total;
    }
    
    void totalNQueens_dfs(int& total, int layer, const int &n, vector<vector<bool>> &solution) {
        if (layer < n) {
            for (int i=0; i < n; ++i) {
                if (checkValid(layer, i, n, solution)) {
                    solution[layer][i] = true;
                    totalNQueens_dfs(total, layer+1, n, solution);
                    solution[layer][i] = false;
                }
            }
        } else {
            total += 1;
        }
    }
    
    bool checkValid(int layer, int i, const int &n, vector<vector<bool>> &solution) {
        for (int cnt=1; cnt < layer+1; ++cnt) {
            if (!solution[layer-cnt][i]) {
                if (i-cnt > -1 && i+cnt < n) {
                    if (solution[layer-cnt][i-cnt] || solution[layer-cnt][i+cnt]) {
                        return false;
                    }
                } else if (i-cnt > -1) {
                    if (solution[layer-cnt][i-cnt]) {
                        return false;
                    }
                } else if (i+cnt < n) {
                    if (solution[layer-cnt][i+cnt]) {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    s.totalNQueens(3);
    s.totalNQueens(10);
    return 0;
}
