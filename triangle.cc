#include <vector>
using namespace std;

class Solution {
private:
    int min_sum;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // DP method
        // def minSum(l, i) minSum in layer l item i to bottom
        // minSum(l, i) = min(minSum(l+1, i), minSum(l+1, i+1)) + triangle[l][i]
        // base case triangle last layer equals to last layer
        vector<int> memo = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                memo[j] = min(memo[j], memo[j+1]) + triangle[i][j];
            }
        }
        return memo[0];
    }
    
    void minmumTotal_dfs(vector<vector<int>>& triangle, int layer, int p, int path_sum) {
        path_sum += triangle[layer][p];
        if (layer == triangle.size() - 1) {
            // bottom, base case
            if (path_sum < min_sum) {
                min_sum = path_sum;
            }
        } else {
            minmumTotal_dfs(triangle, layer+1, p, path_sum);
            minmumTotal_dfs(triangle, layer+1, p+1, path_sum);
        }   
    }
};
