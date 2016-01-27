#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::map<char, string> num2str = {{'0', ""}, {'1', ""},
                                            {'2', "abc"}, {'3', "def"},
                                            {'4', "ghi"}, {'5', "jkl"},
                                            {'6', "mno"}, {'7', "pqrs"}, 
                                            {'8', "tuv"}, {'9', "wxyz"}};
        int sz = digits.size();
        int queue_sz = 0;
        std::vector<string> ret;

        std::queue<string> resQueue;
        for (int i = 0; i < sz; i++) {
            string strs = num2str[digits[i]];
            if (queue_sz == 0) {
                if (strs.size() > 0) {
                    for (char ch : strs) {
                        resQueue.push(string(1, ch));
                    }
                    queue_sz += strs.size();
                } else {
                    return ret;
                }
            } else {
                if (strs.size() > 0) {
                    int cnt = 0;
                    while (cnt < queue_sz) {
                        string str = resQueue.front();
                        for (char ch : strs) {
                            resQueue.push(str + ch);
                        }
                        resQueue.pop();
                        cnt += 1;
                    }
                    queue_sz *= strs.size();
                }  else {
                    return ret;
                }
            }
        }

    
        while (!resQueue.empty()) {
            ret.push_back(resQueue.front());
            resQueue.pop();
        }

        return ret;
    }
    // TODO backtracing implementation
    
};
