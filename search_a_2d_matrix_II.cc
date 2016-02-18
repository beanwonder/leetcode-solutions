#include <vector>
using namespace std;

class Solution {

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search nlogn
        int rows = matrix.size();
        int upper = 0;
        int lower = rows;
        // int cols = matrix[0].size();
        for (int i=0; i < rows; ++i) {
            if (matrix[i].front() > target) {
                upper = i;
                break;
            }
        }
        for (int i=rows-1; i > -1; --i) {
            if (matrix[i].back() < target) {
                lower = i;
                break;
            }
        }

        for (int idx=lower+1; idx < upper; idx++) {
            if (binary_search(matrix[idx], target)) {
                return true;
            }
        }
        return false;
    }

    bool binary_search(vector<int>& array, int target) {
        int sz = array.size();
        int i = 0;
        int j = sz - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (array[mid] == target) {
                return true;
            } else if (array[mid] < target) {
                i = mid + 1;
            } else {
                // > target
                j = mid - 1;
            }
        }
        return false;
    }
};

int main () {
    Solution s;
    vector<vector<int>> m = {{-5}};
    s.searchMatrix(m, -2);
}
