//
// Created by Zhebin Shen on 2/14/16.
//
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
    int rows;
    int cols;
public:
    bool exist(vector<vector<char>>& board, string word) {
        // assume the board is valid
        if (word.empty()) return false;

        rows = board.size();
        cols = board[0].size();

        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                vector<vector<bool>> visited(rows, vector<bool> (cols, false));
                if (exists_dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exists_dfs(vector<vector<char>>& board, string& word,
                    int i, int j, int depth, vector<vector<bool>>& visited) {
        if (word[depth] != board[i][j]) {
            return false;
        } else {

            visited[i][j] = true;
            if (depth == word.size()-1) {
                return true;
            }

            // go deep into 4 dirctions

            if (i - 1 > -1 && !visited[i-1][j]) {
                if (exists_dfs(board, word, i - 1, j, depth + 1, visited)) {
                    return true;
                }
            }

            if (i + 1 < rows && !visited[i+1][j]) {
                if (exists_dfs(board, word, i + 1, j, depth + 1, visited)) {
                    return true;
                }
            }

            if (j - 1 > -1 && !visited[i][j-1]) {
                if (exists_dfs(board, word, i, j - 1, depth + 1, visited)) {
                    return true;
                }
            }

            if (j + 1 < cols && !visited[i][j+1]) {
                if (exists_dfs(board, word, i, j + 1, depth + 1, visited)) {
                    return true;
                }
            }

            visited[i][j] = false;
            return false;
        }
    }
};

int main(void) {
    Solution s;
    vector<vector<char>> board {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target = "ABCCED";
    auto a = s.exist(board, target);
    return 0;
}