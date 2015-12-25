#include <vector>
using namespace std;

class Solution {
public:
    // proof by contradiction
    // one pass scan from both end left and right
    // move the smaller one to inner
    // Here is the proof. Proved by contradiction:

    // Suppose the returned result is not the optimal solution. Then there must exist an optimal solution, say a container with aol and aor (left and right respectively), such that it has a greater volume than the one we got. Since our algorithm stops only if the two pointers meet. So, we must have visited one of them but not the other. WLOG, let's say we visited aol but not aor. When a pointer stops at a_ol, it won't move until

    // The other pointer also points to aol. In this case, iteration ends. But the other pointer must have visited aor on its way from right end to aol. Contradiction to our assumption that we didn't visit aor.

    // The other pointer arrives at a value, say arr, that is greater than aol before it reaches aor. In this case, we does move aol. But notice that the volume of aol and arr is already greater than aol and aor (as it is wider and heigher), which means that aol and aor is not the optimal solution -- Contradiction!

    // Both cases arrive at a contradiction.
    //
    //
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left != right) {
            int h_l = height[left];
            int h_r = height[right];
            int tmp_area = (h_l <= h_r ? h_l: h_r) * (right - left);
            max_area = max_area >= tmp_area ? max_area: tmp_area;
            if (h_l <= h_r) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
    // or dp solution
};
