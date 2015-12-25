#include <vector>
using namespace std; 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int count = 0;
        for (auto num : nums) {
            if (count > 0) {
                if (majority != num) {
                    count--;
                } else {
                    count++;
                }
            } else {
                // count = 0
                majority = num;
                count = 1;
            }
        }
        return majority;
    }
};
