//
// Created by Zhebin Shen on 11/6/16.
//



#include <vector>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int alternate_operations(int n) {
        int res = 1;
        int i = 2;
        while (i <= n) {
            if (i % 3 == 0) {
                res *= i;
            } else if (i % 3 == 1) {
                res -= i;
            } else if (i % 3 == 2) {
                res += i;
            }
            i += 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.alternate_operations(4) << endl;
    cout << s.alternate_operations(1) << endl;
    cout << s.alternate_operations(2) << endl;
    cout << s.alternate_operations(3) << endl;
    cout << s.alternate_operations(5) << endl;
}