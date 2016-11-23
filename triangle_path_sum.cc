#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int triangle_path_sum(vector<vector<int>>& grid) {
        int m = grid.size();
        // no path sum
        if (m == 0) return 0;
        // last row
        int n = grid.back().size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        // BC 
        memo[0][0] = grid[0][0];
        // from top to buttom
        for (int i=1; i < m; ++i) {
            for (int j=0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    memo[i][j] = memo[i-1][j] + grid[i][j];
                } else {
                    memo[i][j] = max(memo[i-1][j-1], memo[i-1][j]) + grid[i][j];
                }
            }
        }

        // find the max in last row in memo
        int maxSum = memo.back()[0];
        for (auto n : memo.back()) {
            if (n > maxSum) {
                maxSum = n;
            }
        }
        return maxSum;
    }
};



int main() {
    Solution s;
    vector<vector<int>> grid {{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};
    cout << s.triangle_path_sum(grid) << endl;
    return 0;
}
