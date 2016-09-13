#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        // target positive
        vector<int> cand;
        // combinationSum_dfs(candidates, cand, 0, 0, target);
        combinationSum_dfs(candidates, cand, 0, candidates.size(), 0, target);
        return res;
    }
    
    void combinationSum_dfs(vector<int>& candidates, vector<int> cand,
                            int i, int k, int sum, int& target) {
        if (sum == target) {
            res.push_back(cand);
        } else if (i < candidates.size() && sum < target) {
            int t = 0;
            if (k == 0) {
                t = 1;
            }
            for ( ;sum+candidates[i] * t <= target; t++) {
                if (t > 0) {
                    cand.push_back(candidates[i]);
                    combinationSum_dfs(candidates, cand, i+1, k, sum+candidates[i]*t, target);
                    // cand.pop_back();
                } else {
                    combinationSum_dfs(candidates, cand, i+1, k-1, sum, target);
                }
            }
        }
    }

    void combinationSum_dp() {

    }
};
