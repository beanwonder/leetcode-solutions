#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // recursive way
        int left = 0;
        int right = height.size() - 1;
        return trap_recur(height, left, right);
    }

    int trap_recur(const std::vector<int>& height, int left, int right) {
        // calculate the water trapped between i and j
        // recursively tallest 2 bar and calculate
        // worst case n^2logn
        
        if ((right-left) <= 1) {
            return 0;
        } else { 
            auto cmp = [&height](int i, int j) {return height[i] < height[j];};
            priority_queue<int, vector<int>, decltype(cmp)> barRanks(cmp); 

            for (int i = left; i <= right; i++) {
                barRanks.push(i);
            }

            // at least 2 bar
            int pos1 = barRanks.top();
            barRanks.pop();
            int pos2 = barRanks.top();

            int ll = pos1 < pos2 ? pos1 : pos2;
            int rr = pos1 >= pos2 ? pos1 : pos2;

            int local_water = (rr - ll - 1) * height[pos2];
            for (int i = ll+1; i < rr; i++) {
                local_water -= height[i];
            }
            return local_water + trap_recur(height, left, ll) + trap_recur(height, rr, right);
        }
    }

    int trap_one_pass(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int curlow = 0;
        int blocks = 0;

        while (left <= right) {
            int min = height[left] <= height[right] ? height[left] : height[right];
            if (min > curlow) {
                area += (min - curlow) * (right - left + 1);// including the min
                curlow = min;
            } else {
                // min <= curlow
                if (height[left] <= height[right]) {
                    // left -> min
                    blocks += height[left++];
                } else {
                    blocks += height[right--];
                }
            }
        }
        return area - blocks;
    }
};

