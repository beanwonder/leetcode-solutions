#include <vector>
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        string::size_type w_len = words.back().size();
        string::size_type num_words = words.size();
        string::size_type total_len = w_len * num_words;
        unordered_map<string, string::size_type > words_count = unordered_map<string, string::size_type> ();
        std::vector<int> res;

        for (auto w : words) {
            if (words_count.find(w) != words_count.end()) {
                words_count[w] += 1;
            } else {
                words_count[w] = 1;
            }
        }

        for (string::size_type start = 0; start <= (int) (s.size() - total_len); start++) {
            string::size_type end = start;
            unordered_map<string, string::size_type > words_tmp = unordered_map<string, string::size_type > (words_count);
            while (!words_tmp.empty()) {
                string w = s.substr(end, w_len);
                unordered_map<string, string::size_type >::iterator it = words_tmp.find(w);
                if (it != words_tmp.end()) {
                    end += w_len;
                    if ((*it).second == 1) {
                       words_tmp.erase(it); 
                    } else {
                        (*it).second -= 1;
                    }
                } else {
                    break;
                }
            }

            if (words_tmp.empty()) {
                res.push_back((int) start);
            }
        }

        return res;
    }
};


int main() {

    

    return 0;
}
