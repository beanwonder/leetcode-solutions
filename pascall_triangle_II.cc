#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> cur_layer(1, 1);
        int cnt = 0;
        while (cnt < rowIndex) {
            cnt += 1;
            std::vector<int> last_layer(cur_layer);
            for (int i = 0; i < cnt+1; i++) {
                if (i == cnt) {
                    cur_layer.push_back(1);
                } else if (i != 0){
                    cur_layer[i] = last_layer[i-1] + last_layer[i];
                } // i = 0 do nothing already exits
            }
        }
        return cur_layer;
    }
};
