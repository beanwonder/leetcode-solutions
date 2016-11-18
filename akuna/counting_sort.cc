//
// Created by Zhebin Shen on 11/6/16.
//

#include <iostream>
#include <vector>
using namespace std;

int* count_sort(int *A, size_t n) {
    long max = INT_MIN;
    long min = INT_MAX;

    for (int i=0; i < n; ++i) {
        if (max < A[i]) {
            max = A[i];
        }
        if (min > A[i]) {
            min = A[i];
        }
    }

    long m = max - min + 1;
    vector<bool> tmp(m, false);
    for (size_t i=0; i < n; ++i) {
        tmp[A[i]-min] = true;
    }
    int *res = new int[n];
    long i = 0;
    long ii = 0;
    while (i < m) {
        if (tmp[i]) {
            res[ii++] = min + i;
        }
        i++;
    }
    return res;
};

int main() {
    int a[] = {INT_MIN, INT_MAX};
    auto res = count_sort(a, 2);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}