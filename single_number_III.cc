#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> res;
        int orx_res = 0;
        if (size < 2) return res;
        for (int i = 0; i < size; i++) {
           orx_res ^= nums[i]; 
        }

        int flag = 1;
        while ((flag & orx_res) == 0) {
            flag <<= 1;
        }

        int x1 = 0;
        for (int i = 0; i < size; i++) {
            if ((flag & nums[i]) != 0) {
                x1 ^= nums[i];
            }
        }
        res.push_back(x1);
        res.push_back(orx_res^x1);
        return res;
    }
};
