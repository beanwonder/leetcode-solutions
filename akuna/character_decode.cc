//
// Created by Zhebin Shen on 11/6/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string decode(string key, string input) {
        vector<bool> key_vec(key.size(), false);
        for (int i=0; i < key.size(); ++i) {
            if ((key[i] - '0') % 3 != 0) {
                key_vec[i] = true;
            }
        }

        string res;
        for (auto ch: input) {
            if (key_vec[ch-'a']) {
                res += ch;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.decode("00001002336469700000000369", "hello") << endl;
    cout << s.decode("00001002336469700000000369", "amhbcdeplklsczo") << endl;

}