/*
 * Complete the function below.
 */

#include <queue>
#include <vector>
using namespace std;

int find_two_closest_and_sum(vector < int > int_list, int target_num) {
    // vector<int> nums(int_list.begin(), int_list.end());
    // sort(nums.begin(), nums.end());
    auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    };
    // pair num, differentce to target
    priority_queue<pair<int, int>, decltype(cmp)> top2(cmp);

    for (auto n : int_list) {
        int diff = abs(n-target);
        if (top2.size() < 2) {
            top2.push(pair<int, int> {n, diff});
        } else {
            if (diff < top2.top().second) {
                top2.pop();
                top2.push(pair<int, int> {n, diff});
            }
        }
    }
    int a = top2.top();
    top2.pop();
    int b = top2.top();
    return a+b;
}


