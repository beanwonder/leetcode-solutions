#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total_length = m + n;
        int median_num = (total_length + 1) / 2;
        int a_pos = 0;
        int b_pos = 0;
        int *half_ptr = NULL;

        for (int i = 0; i < median_num; i++) {
            if (a_pos < m && b_pos < n) {
                if (A[a_pos] <= B[b_pos]) {
                    half_ptr = A + a_pos;
                    a_pos++;
                } else {
                    half_ptr = B + b_pos;
                    b_pos++;
                }
            } else if (a_pos == m) {
                // a_pos reached end
                b_pos += median_num - i - 1;
                half_ptr = B + b_pos;
                b_pos++;
                break;
            } else {
                // b_pos reached end
                a_pos += median_num - i - 1;
                half_ptr = A + a_pos;
                a_pos++;
                break;
            }
        }

        double median;
        if ((total_length % 2) == 1) {
            // odd totallength
            median = *half_ptr;
        } else {
            // even length
            if (a_pos < m && b_pos < n) {
                if (A[a_pos] <= B[b_pos]) {
                    median = *half_ptr + A[a_pos];
                } else {
                    median = *half_ptr + B[b_pos];
                }
            } else if (a_pos == m) {
                median = *half_ptr + B[b_pos];
            } else {
                median = *half_ptr + A[a_pos];
            }
            median /= 2;
        }

        return median;
    }
};

int main(void)
{
    Solution s1;
    int A[] = {1};
    int B[] = {3, 4, 5};

    cout << s1.findMedianSortedArrays(A, 1, B, 3) << endl;
    return 0;
}
