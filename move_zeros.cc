#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes_not_in_place(vector<int>& nums) {
        int len = nums.size();
        std::vector<int> nums_copy(len, 0);
        int cnt = 0;

        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums_copy[cnt] = nums[i];
                cnt++;
            }
        }
        nums = nums_copy;
    }
    
    void moveZeroes(vector<int>& nums) {
        int slw = 0;
        int fst = 0;
        int len = nums.size();

        while (slw < len) {
            if (fst < len) {
                if (nums[fst] == 0) {
                    fst++;
                } else {
                    nums[slw++] = nums[fst++];
                }
            } else {
                nums[slw++] = 0;
            }
            
        }
    }
};
