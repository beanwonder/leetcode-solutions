#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int insert_cost = 1;
        const int delete_cost = 1;
        const int replace_cost = 1;
        vector<vector<int>> memo(word1.size()+1, vector<int>(word2.size()+1, 0));
        // BC
        for (int i = 1; i < word1.size()+1; ++i) {
            memo[i][0] = i * delete_cost;
        }
        
        for (int j = 1; j < word2.size()+1; ++j) {
            memo[0][j] = j * insert_cost;
        }
        
        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                int tmp1 = memo[i-1][j] + delete_cost;
                int tmp2 = memo[i][j-1] + insert_cost;
                int tmp3 = memo[i-1][j-1] + replace_cost * u(word1[i-1], word2[j-1]);
                memo[i][j] = min(min(tmp1, tmp2), tmp3);
            }
        }
        
        return memo.back().back();
    }
    
    int u(char c1, char c2) {
        if (c1 == c2) {
            return 0;
        }
        return 1;
    }
};
