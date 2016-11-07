//
// Created by Zhebin Shen on 11/6/16.
//

#include <vector>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    string binary_string(unsigned int num) {
        string bstr;
        do {
            if ((num & 0x1) == 1) {
                bstr = "1" + bstr;
            } else {
                bstr = "0" + bstr;
            }
            num >>= 1;
        } while (num != 0);
        return bstr;
    }
};


int main() {
    Solution s;
    cout << s.binary_string(0) << endl;
    cout << s.binary_string(1) << endl;
    cout << s.binary_string(2) << endl;
    cout << s.binary_string(5) << endl;
    cout << s.binary_string(18) << endl;
    cout << s.binary_string(55) << endl;
    cout << s.binary_string(100) << endl;

}