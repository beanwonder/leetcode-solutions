#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        std::vector<vector<int> > triangle;
        if (numRows == 0) return triangle;
        // make seed row
        triangle.push_back(vector<int> (1, 1));
        int cnt = 1;
        // std::vector<int> *last_layer = NULL;
        // std::vector<int> *cur_layer = NULL;
        while (cnt < numRows) {
            //cnt++;
            //std::vector<int> &last_layer = triangle.back();
            cnt++;
            //triangle.push_back(vector<int> (cnt));
            //cout << triangle.size() << '\n';
            std::vector<int> cur_layer(cnt);
            for (int i = 0; i < cnt; i++) {
                if (i == 0 || i == cnt-1) {
                    cur_layer[i] = 1;
                } else {
                    //cout << (*cur_layer).size() << '\n';
                    //cout << (*last_layer).size() << '\n';
                    cur_layer[i] = triangle.back()[i-1] + triangle.back()[i];
                }
            }
            triangle.push_back(cur_layer);
            //cnt++;
        }
        triangle;
        return triangle;
    }

};

int main(void)
{
    Solution s;
    //s.generate(10);
    //vector<vector<int>> auto a = s.generate(10);
    return 0;
}
