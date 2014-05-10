#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int size = numbers.size();
        vector<int> indexs(2);
        unordered_map<int, int> hash_map;

        for (int i = 0; i < size; i++) {
            unordered_map<int, int>::iterator val_iter;

            val_iter = hash_map.find(target - numbers[i]);
            if (val_iter != hash_map.end()) {
                // find target - number[i]
                indexs[0] = val_iter->second;
                indexs[1] = i + 1;
                break;
            }
            val_iter = hash_map.find(numbers[i]);
            if (val_iter == hash_map.end()) {
                // didn't find numbers[i] in previous numbers
                // add this key-val pair
                hash_map[numbers[i]] = i + 1;
            }

        }
        return indexs;
    }
};
