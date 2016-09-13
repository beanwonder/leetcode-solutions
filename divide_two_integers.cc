#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            // divide by zero error
            return INT_MAX;
        }
        long dividend_ext = dividend >= 0 ? dividend : - ((long) dividend);
        long divisor_ext = divisor >= 0 ? divisor : - ((long) divisor);
        bool sign_ext = (divisor ^ dividend) >= 0;

        // binary search 
        long quo_ext = div_loop(dividend_ext, divisor_ext);
        if (!sign_ext) {
            // negate
            quo_ext = -quo_ext;
        }
       
        if (quo_ext > INT_MAX || quo_ext < INT_MIN) {
            return INT_MAX;
        }
        return (int) quo_ext;
    }

    long sumdiv(long dividend, long divisor, long q) {
        if (dividend < divisor) {
           return q; 
        } else {
            long part = divisor;
            long part_q = 1;
            while ((part << 1) < dividend) {
                part <<= 1;
                part_q <<= 1;
            }
            return sumdiv(dividend-part, divisor, part_q+q);
        }
    }

    long div_loop(long dividend, long divisor) {
        long q = 0;
        while (divisor <= dividend) {
            long part_q = 1;
            long subs = divisor;
            while ((subs << 1) <= dividend) {
               subs <<= 1;
               part_q <<= 1;
            }
            q += part_q;
            dividend -= subs;
        }
        return q;
    }

};
