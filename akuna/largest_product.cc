//
// Created by Zhebin Shen on 11/6/16.
//

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int largest_product(vector<int> nums) {
        // array of positive number
        // vector<int> memo(nums.size(), nums.size()-1);
        int max_p = 0;
        int next = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i < nums.size() - 1) {
                if (nums[i] >= nums[next]) {
                    next = i;
                }
            }

            if (next != i) {
                int p = nums[i] * nums[next];
                if (p > max_p) {
                    max_p = p;
                }
            }
        }
        return max_p;
    }

};


int main() {
    Solution s;
    cout << s.largest_product(vector<int> {4, 2, 3, 7}) << endl;
    cout << s.largest_product(vector<int> {2, 8, 9, 9}) << endl;
    cout << s.largest_product(vector<int> {3, 5, 4}) << endl;
    cout << s.largest_product(vector<int> {5, 4, 1, 2}) << endl;
    cout << s.largest_product(vector<int> {1, 1, 2, 1}) << endl;
    cout << s.largest_product(vector<int> {9, 3, 10, 5, 9, 8}) << endl;
    return 0;
}