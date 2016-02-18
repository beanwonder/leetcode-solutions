#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ithProfit = 0;
        int maxP = ithProfit;
        for (int i=prices.size()-2; i > -1; --i) {
            ithProfit = max(ithProfit + (prices[i+1]-prices[i]), 0);
            maxP = max(maxP, ithProfit);
        }
        return maxP;
    }
};
