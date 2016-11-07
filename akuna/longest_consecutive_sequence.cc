//
// Created by Zhebin Shen on 11/6/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> lcs(vector<int> seq) {

        vector<int> lcseq;
        if (seq.size() < 1) return lcseq;
        vector<int> memo(seq.size(), 1);

        int max_len = 1;
        int last = 0;
        for (int i = 1; i < seq.size(); ++i) {
            if (seq[i] - seq[i - 1] == 1) {
                memo[i] = memo[i - 1] + 1;
            }
            if (memo[i] > max_len) {
                max_len = memo[i];
                last = i;
            }
        }

        for (int i = last - (max_len - 1); i <= last; ++i) {
            lcseq.push_back(seq[i]);
        }

        return lcseq;
    }
};


int main() {

    Solution s;

    auto a = s.lcs(vector<int> {1});
    auto b = s.lcs(vector<int> {1, 2});
    auto c = s.lcs(vector<int> {1, 1, 1});
    auto d = s.lcs(vector<int> {8, -1, 6, 7, 2, 18, -12});
    auto e = s.lcs(vector<int> {1, 2, 3, 1, 2, 3, 4, 5, 6});
    auto f = s.lcs(vector<int> {});

    return 0;
}