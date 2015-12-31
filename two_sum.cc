#include <vector>
#include <unordered_map>
#include <algorithm>
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

    vector<int> twoSum_sorted(vector<int> &numbers, int target) {
        // if array is sorted, via greedy algorithm
        // similar: 11. Container With Most Water
        // but index sensitive could not be used in two sum problem
        std::vector<int> indexes(2);
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                indexes[0] = i + 1;
                indexes[1] = j + 1;
                break;
            } else if (sum < target) {
                i += 1;
            } else {
                // sum > target
                j -= 1;
            }
        }
        return indexes;
    }

};
