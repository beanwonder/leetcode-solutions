#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // matrix T
        // n * n matrix
        // not in place
        int n = matrix.size();
        vector<vector<int>> matrix_copy;
        for (int i=0; i < n; ++i) {
            matrix_copy.emplace_back(n);
            for (int j=0; j < n; ++j) {
                matrix_copy[i][j] = matrix[n-j-1][i];
            }
        }
        matrix = matrix_copy;
    }

    void rotate_in_place(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n/2; i++) {
            // iterate over one cycle
            for (int j = i; j < n-i-1; j++) {
                int tmp1 = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                int tmp2 = maxtrix[][n-i];
            
        }
    }

};
