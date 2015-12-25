#include <vector>
using namespace std;

class Solution {
public:
    bool m_binary_search(std::vector<vector<int>>& m, int &c_num, int start, int end, int &target) {
        if (start > end) {
            return false;
        } else {
            int mid_pos = (end - start / 2) + start;
            int i = mid_pos / c_num;
            int j = mid_pos % c_num;
            if (m[i][j] == target) {
                return true;
            } else if (m[i][j] < target) {
                return m_binary_search(m, c_num, mid_pos+1, end, target);
            } else {
                // m[i][j] > target
                return m_binary_search(m, c_num, start, mid_pos-1, target);
            }
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        // m * n size
        int r_num = matrix.size();
        int c_num = matrix[0].size();
        int size = r_num * c_num;
        // index start from 0
        return m_binary_search(matrix, c_num, 0, size-1, target);
    }

    bool searchMatrix_iterate(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int r_num = matrix.size();
        int c_num = matrix[0].size();
        int size = r_num * c_num;
        int left = 0;
        int right = size - 1;

        do {
            int mid_pos = left + (right - left);
            int i = mid_pos / c_num;
            int j = mid_pos % c_num;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                left = mid_pos+1;
            } else {
                right = mid_pos-1;
            }
        } while (left <= right);
        return false;
    }
};
