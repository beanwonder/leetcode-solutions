#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        if (matrix[0].empty()) return;
        int r_num = matrix.size();
        int c_num = matrix[0].size();
        std::vector<bool> rows(r_num, false);
        std::vector<bool> columns(c_num, false);

        for (int i = 0; i < r_num; i++) {
            for (int j = 0; j < c_num; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for (int i = 0; i < r_num; i++) {
            if (rows[i]) {
                for (int j = 0; j < c_num; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < c_num; j++) {
            if (columns[j]) {
                for (int i = 0; i < r_num; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
