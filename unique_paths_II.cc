#include <vector>
using namespace std;

class Solution {
    // BFS DFS DP
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> memo(obstacleGrid);
        // base case
        int m = memo.size();
        int n = memo[0].size();
        int numPaths = 1;
        
        for (int i=0; i < n; ++i) {
            memo[0][i] = numPaths;
            if (obstacleGrid[0][i] == 1) {
                numPaths = 0;
            }
        }
        numPaths = 1;
        for (int j=0; j < m; ++j) {
            memo[j][0] = numPaths;
            if (obstacleGrid[j][0] == 1) {
                numPaths = 0;
            }
        }
        
        for (int i=1; i < m; ++i) {
            for (int j=1; j < n; ++j) {
                int up = 0;
                int left = 0;
                if (obstacleGrid[i-1][j] == 1) {
                    up = 0;
                } else {
                    up = memo[i-1][j];
                }
                if (obstacleGrid[i][j-1] == 1) {
                    left = 0;
                } else {
                    left = memo[i][j-1];
                }
                memo[i][j] = up + left;
            }
        }
        if (obstacleGrid[0][0] == 1) {
            memo[0][0] = 0;
        }
        if (obstacleGrid[m-1][n-1] == 1) {
            memo[m-1][n-1] = 0;
        }
        return memo[m-1][n-1];
    }
    int uniquePathsWithObstacles_dp_opt(vector<vector<int>>& obstacleGrid) {
        // with O(n) space;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> memo(n, 0);
        vector<int> current(n, 0);
        // BASE CASE 
        if (obstacleGrid[0][0] == 0) {
            memo[0] = 1;
        } else {
            memo[0] = 0;
        }

        for (int i = 0; i < m; i++) {
            current[0] = memo[0];
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    current[j] = current[j-1] + memo[j];
                } else {
                    // obstacle
                    current[j] = 0;
                }
            }
            memo = current;
        }
        return memo[n-1];
    }

    int uniquePathsWithObstacles_bfs(vector<vector<int>> obstacleGrid) {
        
    }
};
