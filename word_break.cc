//
// Created by Zhebin Shen on 11/17/16.
//
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.find(s) != wordDict.end()) return true;
        for (auto w : wordDict) {
            if (s.size() >= w.size() && s.find(w) == 0) {
                if (wordBreak(s.substr(w.size()), wordDict)) return true;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    unordered_set<string> dict = {"bc","ca"};
    string ss("cbca");
    cout << s.wordBreak(ss, dict) << endl;
    return 0;
}