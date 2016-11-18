//
// Created by Zhebin Shen on 11/6/16.
//


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(int n) {
        if (n == 0) {
            return vector<vector<int>> {{}};
        } else {
            auto sets = subsests(n-1);

        }
    }

    vector<int> subset_sum_removal(vector<int> nums) {
        // nums are sorted
        int len = nums.size();


    }

    vector<int> subset_sum_removal(vector<int> nums) {
        sort(nums.begin(), nums.end());


    }
};


int main() {

    Solution s;
    return 0;
}