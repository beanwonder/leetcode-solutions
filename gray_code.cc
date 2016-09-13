#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int len = pow(2, n);
        vector<int> res(len, 0);
        for (int i=1; i < len; ++i) {
            // unsigned int num = i;
            bitset<sizeof(int)*8> binary_code(i);
            bitset<sizeof(int)*8> gray_code(0);
            gray_code[n-1] = binary_code[n-1];
            for (int ii=n-2; ii > -1; --ii) {
                if (binary_code[ii] == binary_code[ii+1]) {
                    gray_code[ii] = false;
                } else {
                    gray_code[ii] = true;
                }
            }            
            res[i] = (int) gray_code.to_ulong();
        }
        return res;
    }    
        vector<int> grayCode_good(int n) {
        int len = pow(2, n);
        vector<int> res(len, 0);
        for (int i=0; i < len; ++i) {
            // unsigned int num = i
            res[i] = (i ^ (i >> 1));
        }
        return res;
    }
};
