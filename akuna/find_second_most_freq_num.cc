//
// Created by Zhebin Shen on 11/6/16.
//


#include <vector>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    int find_second_most_freqent_number(vector<int> nums) {
        map<int, int> word_count;
        for (auto n : nums) {
            word_count[n] += 1;
        }

        vector<pair<int, int>> ps(word_count.begin(), word_count.end());
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second > p2.second;
        };
        sort(ps.begin(), ps.end(), cmp);
        assert(ps.size() >= 2);
        return ps[1].first;
    }
};


int main() {

    Solution s;

    assert(s.find_second_most_freqent_number(vector<int> {1, 1, 1, 1, 2}) == 2);

    assert(s.find_second_most_freqent_number(vector<int> {1, 1, 1, 1, 2, 2}) == 2);
    assert(s.find_second_most_freqent_number(vector<int> {1, 1, 1, 1, 2, 2, 2}) == 2);
    assert(s.find_second_most_freqent_number(vector<int> {0, 1, 2, 2, 2, 2, 1, 0, 5, 1}) == 1);

    assert(s.find_second_most_freqent_number(vector<int> {1, 1, 1, 1, 2, 1, 2, 2, 2}) == 2);


    return 0;
}
