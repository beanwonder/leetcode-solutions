#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int knights_adventure() {
        int m;
        int n;
        int src;
        int dst;
        int x, y;

        cin >> m >> n;
        vector<vector<char>> board(m, vector<char>(n, 0));

        cin >> x >> y;
        src = x * n + y;
        cin >> x >> y;
        dst = x * n + y;

        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; ++i) {
            // int x, y;
            cin >> x >> y;
            board[x][y] = '#';
        }

        // BFS search
        queue<int> moves;
        moves.push(src);
        int steps = 0;

        // since there must exists a path
        while (!moves.empty()) {
            int len = moves.size();
            for (int k = 0; k < len; ++k) {
                int point = moves.front();
                moves.pop();
                if (point == dst) {
                    return steps;
                }

                int i = point / n;
                int j = point % n;
                // 8 directions
                if (i-2 >= 0) {
                    if (j-1 >= 0 && board[i-2][j-1] != '#') {
                        moves.push((i-2) * n + j-1);
                        board[i-2][j-1] = '#';
                    }
                    if (j+1 < n && board[i-2][j+1] != '#') {
                        moves.push((i-2) * n + j+1);
                        board[i-2][j+1] = '#';
                    }
                }
                if (i+2 < m) {
                    if (j-1 >= 0 && board[i+2][j-1] != '#') {
                        moves.push((i+2) * n + j-1);
                        board[i+2][j-1] = '#';
                    }
                    if (j+1 < n && board[i+2][j+1] != '#') {
                        moves.push((i+2) * n + j+1);
                        board[i+2][j+1] = '#';
                    }
                }
                if (i-1 > 0) {
                    if (j-2 >= 0 && board[i-1][j-2] != '#') {
                        moves.push((i-1) * n + j-2);
                        board[i-1][j-2] = '#';
                    }
                    if (j+2 < n && board[i-1][j+2] != '#') {
                        moves.push((i-1) * n + j+2);
                        board[i-1][j+2] = '#';
                    }
                }
                if (i+1 < m) {
                    if (j-2 >= 0 && board[i+1][j-2] != '#') {
                        moves.push((i+1) * n + j-2);
                        board[i+1][j-2] = '#';

                    }
                    if (j+2 < n && board[i+1][j+2] != '#') {
                        moves.push((i+1) * n + j+2);
                        board[i+1][j+2] = '#';

                    }
                }
            }
            steps += 1;
        }
        return 0;
    }

};

int main() {
    Solution s;
    cout << s.knights_adventure() << endl;
    return 0;
}