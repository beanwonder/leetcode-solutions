#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int mostRecent = len-1;
        // base case
        bool res = false;
        for (int i=len-1; i > -1; --i) {
            if (i+nums[i] < mostRecent) {
                res = false;
            } else {
                res = true;
                mostRecent = i;
            }
        }        
        return res;
    }
};
