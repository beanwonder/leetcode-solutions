#include <vector>
#include <bitset>


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = board.size();
        for (int i = 0; i < n; i++) {
            bitset<10> dup_checker;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!dup_checker[board[i][j] - '0']) {
                    dup_checker.set(board[i][j] - '0');
                } else {
                    return false;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            bitset<10> dup_checker;
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!dup_checker[board[i][j] - '0']) {
                    dup_checker.set(board[i][j] - '0');
                } else {
                    return false;
                }
            }
        }

        for (int idx = 0; idx < n; idx++) {
            int start_i = (idx / 3) * 3;
            int start_j = (idx % 3) * 3;
            bitset<10> dup_checker;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[start_i+i][start_j+j] == '.') {
                        continue;
                    }
                    if (!dup_checker[board[start_i+i][start_j+j] - '0']) {
                        dup_checker.set(board[start_i+i][start_j+j] - '0');
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
