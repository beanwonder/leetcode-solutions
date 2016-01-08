#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // bit manuputlation use a bit set and add one each time
        std::vector<vector<int> > subsets;
        int n = nums.size();
        unsigned int cnt_down = (1 << n) - 1;

        std::sort(nums.begin(), nums.end());
        // always exits the empty set
        subsets.emplace_back();

        while (cnt_down != 0) {
            std::vector<int> subset;
            for (int i = 0; i < 32; i++) {
                if (((1 << i) & cnt_down) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            cnt_down -= 1;
            subsets.push_back(subset);
        }
        return subsets;
    }

    vector<vector<int>> subsets_dfs(vector<int>& nums) {
        // by dfs search 
        
    }

};
