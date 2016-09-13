#include <string>
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
    string res;
    int cnt = 0;
public:
    string getPermutation(int n, int k) {
        string str = "";
        for (int i=1; i <= n; i++) {
            str += to_string(i);
        }
        permutation_recr(k, str, 0, n-1);
        return res;

    }

    void permutation_recr(int& k, string& str, int l, int r) {
        if (cnt < k) {
            if (l == r) {
                cnt += 1;
                if (cnt == k) {
                    res = str;
                }
            } else {
                int i = l;
                int p = factorial(r-l);
                while (cnt + p < k){
                    cnt += p;
                    i += 1;
                }
                // string sstr = str;
                swap(str[l], str[i]);
                sort(str.begin()+l+1, str.end());
                permutation_recr(k, str, l+1, r);
            }
        }
    }

    int factorial(int x) {
        int r = 1;
        while (x > 0) {
            r *= x;
            x--;
        }
        return r;
    }
};

int main (void) {
    Solution s;
    cout << s.getPermutation(9, 22234);
    //cout << s.getPermutation(2, 1) << " " << s.getPermutation(2, 2);
}