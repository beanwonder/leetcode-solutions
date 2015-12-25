#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int sz = s.size();
        string acc;
        int incrs = numRows + numRows - 2;
        for (int i = 0; i < numRows; i++) {
            if (i != 0 && i != numRows - 1) {
                // not head or tail in zig zag, takes 2 elements in a group
                int pos1 = i;
                //int pos2 = pos1 - i + incrs - i;
                while (pos1 < sz) {
                    int pos2 = pos1 - i + incrs - i;
                    acc += s[pos1];
                    if (pos2 < sz) {
                        acc += s[pos2];
                    }
                    pos1 += incrs;
                }
            } else {
                // head or tail postion
                int pos = i;
                while (pos < sz) {
                    acc += s[pos];
                    pos += incrs;
                }
            }
        }
        return acc;
    }
};
