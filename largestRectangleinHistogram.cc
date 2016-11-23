#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> countr(heights.size(), 0);
        vector<int> countl(heights.size(), 0);
        // scan ->
        for (int i = 1; i < heights.size(); ++i) {
            if (heights[i-1] >= heights[i]) {
                countr[i] = countr[i-1] + 1;
            }
        }
        // scan <-
        for (int i = heights.size()-2; i >= 0; --i) {
            if (heights[i+1] >= heights[i]) {
                countl[i] = countl[i+1] + 1;
            }
        }
        // max
        int max = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int rectangle = (countr[i]+countl[i]+1) * heights[i];
            if (rectangle > max) max = rectangle;
        }
        return max;
    }
};
