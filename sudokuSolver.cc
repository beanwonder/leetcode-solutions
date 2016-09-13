#define N 9
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<bitset<N>> lines(N, bitset<N>());
        vector<bitset<N>> cols(N, bitset<N>());
        vector<bitset<N>> blocks(N, bitset<N>());
        
        // initialize assume input is legal
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != '.') {
                    int pos = board[i][j] - '1';
                    lines[i].set(pos);
                    cols[j].set(pos);
                    blocks[(i / 3) * 3 + (j / 3)].set(pos);
                }
            }
        }
        
        // fill
        fill_sudoku_recr(0, board, lines, cols, blocks);
    }

private:
    bool fill_sudoku_recr(int id, vector<vector<char>>& board,
                          vector<bitset<N>>& lines, vector<bitset<N>>& cols,
                          vector<bitset<N>>& blocks) {
        if (id == N * N) {
            return true;
        } else {
            int pos_x = id / N;
            int pos_y = id % N;
            int bid = (pos_x / 3) * 3 + (pos_y / 3);
            
            if (board[pos_x][pos_y] == '.') {
                bitset<N> t = lines[pos_x] | cols[pos_y] | blocks[bid];
            
                for (int i = 0; i < N; ++i) {
                    if (!t.test(i)) {
                        board[pos_x][pos_y] = '1' + i;
                        lines[pos_x].set(i);
                        cols[pos_y].set(i);
                        blocks[bid].set(i);
                        if (fill_sudoku_recr(id+1, board, lines, cols, blocks)) {
                            return true;
                        } else {
                        // revert
                            board[pos_x][pos_y] = '.';
                            lines[pos_x].set(i, false);
                            cols[pos_y].set(i, false);
                            blocks[bid].set(i, false);
                        }
                    }
                }
                return false;
            } else {
                return fill_sudoku_recr(id+1, board, lines, cols, blocks);
            }
        }
    }
    
};
