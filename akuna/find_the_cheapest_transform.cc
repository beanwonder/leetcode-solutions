//
// Created by Zhebin Shen on 11/6/16.
//



#include <vector>
#include <iostream>
#include <cassert>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:

    // level start from 0
    /*
    void find_cheapest_cost(char current, char target, int level, int cost, int& min_cost) {
        // cut the leaf
        if (cost < min_cost) {
            if (current == target) {
                min_cost = cost;
            } else if (level <= 3) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    find_cheapest_cost(ch, target, level + 1, cost + cost_function(ch, current), min_cost);
                }
            }
        }
    }
     */

    int cost_function(char src, char dest) {
        return table[src-'a'][dest-'a'];
    }

    // what is in and what is out attention
    int dij_min_path(char in, char out) {
        // min heap
        auto cmp = [](pair<char, int> p1, pair<char, int> p2) {return p1.second > p2.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> min_costs(cmp);
        // search
        set<char> visited;
        min_costs.push(pair<char, char> {in, cost_function(in, in)});
        while (visited.size() < 26) {
            pair<char, int> node = min_costs.top();
            min_costs.pop();
            if (node.first == out) {
                // min cost from in to out
                return node.second;
            } else {
                if (visited.find(node.first) == visited.end()) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        min_costs.push(pair<char, int> {ch, node.second + cost_function(node.first, ch)});
                    }
                    visited.insert(node.first);
                }
            }

        }
        return INT_MIN;
    }




    vector<vector<int>> table;

    int find_cheapest_transformation(string input, string output) {

        table = vector<vector<int>> (26, vector<int>(26, 1));
        for (int i = 0; i < 26; ++i) {
            table[i][i] = 0;
        }
        // table['a'-'a']['s'-'a'] = 3;
        table['a'-'a']['s'-'a'] = 2;


        int len = input.size();
        int cost = 0;
        for (int i=0; i < len; ++i) {
            cost += dij_min_path(input[i], output[i]);
        }
        return cost;
    }
};


int main() {
    Solution s;
    cout << s.find_cheapest_transformation("a", "a") << endl;
    cout << s.find_cheapest_transformation("aa", "aa") << endl;
    cout << s.find_cheapest_transformation("az", "az") << endl;
    cout << s.find_cheapest_transformation("abcdeft", "sssssss") << endl;
    return 0;
}