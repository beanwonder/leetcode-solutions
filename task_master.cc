#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int tasks(int n, vector<int>& a, vector<int>& b) {
        unordered_set<int> ts;
        unordered_set<int> nots;
        unordered_map<int, int> rules;
        for (int i=0; i < (int)a.size(); ++i) {
               // traverse a and b
           // b_i must be performed before a_i
           // add rules
            rules[a[i]] = b[i];
        }

        for (int i=0; i < (int)a.size(); ++i) {
            if (nots.find(a[i]) == nots.end()) {
                unordered_set<int> deps;
                int it = a[i];
                while (true) {
                    if (ts.find(it) != ts.end()) {
                        // stop and find tasks that can perform, all tasks can be perform
                        ts.insert(deps.begin(), deps.end());
                        break;
                    } else if (rules.find(it) == rules.end()) {
                        ts.insert(deps.begin(), deps.end());
                        ts.insert(it);
                        break;
                    } else if (nots.find(it) == nots.end()) {
                        if (deps.find(it) != deps.end()) {
                            // find in the deps find a new cycle
                            nots.insert(deps.begin(), deps.end());
                            break;
                        } else {
                            deps.insert(it);
                            it = rules[it];
                        }
                    } else {
                        // otherwise find in a previous cycle
                        break;
                    }
                }
            }
            // otherwise
            // a[i] is in a cycle
            // then b[i] must be in the cycle too
        }

        return ts.size();
    }
};


int main() {

    // graph and cycle
    // about grahp
    Solution s;
    vector<int> a{1,2,3,4,5,6};
    vector<int> b{2,3,1,1,2,3};
    cout << s.tasks(6, a, b) << endl;
    return 0;
}
