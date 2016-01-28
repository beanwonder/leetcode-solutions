#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int idxa = a.size() - 1;
        int idxb = b.size() - 1;

        while (carry || idxa > -1 || idxb > -1) { 
            int digit;
            int aa;
            int bb;
            if (idxa > -1 && idxb > -1) {
                aa = a[idxa--] - '0';
                bb = b[idxb--] - '0';
            } else if (idxa > -1) {
                aa = a[idxa--] - '0';
                bb = 0;
            } else if (idxb > -1) {
                aa = 0;
                bb = b[idxb--] - '0';
            } else {
                //"only carry"
                aa = 0;
                bb = 0;
            }
            digit = (aa + bb + carry) % 2;
            carry = (aa + bb + carry) / 2;
            res.insert(0, 1, '0'+digit);
        }
        return res;
    }
};
