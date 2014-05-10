class Solution {
public:
    int singleNumber(int A[], int n) {
        int i = 0;
        for (i = 0; i < n - 1; i++) {
            A[i + 1] ^= A[i];
        }
        return A[i];
    }
};
