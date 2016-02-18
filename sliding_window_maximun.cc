#include <vector>
#include <deque>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto my_comp = [](pair<int, int> p1, pair<int, int> p2){return p1.second < p2.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(my_comp)> pq(my_comp);
        vector<int> res;
        
        // should be end wih i window
        for (int i=0; i < nums.size(); ++i) {
            pq.push(pair<int, int>(i, nums[i]));
            if (i-k+1 >= 0) {
                while (pq.top().first < i-k+1) {
                    // delete all out of range values
                    pq.pop();
                }
                res.push_back(pq.top().second);
            }
        }
        return res;
    }   

    vector<int> maxSlidingWindow_deque(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // delete all out of range value first
            while (!dq.empty() && dq.front().first < i-k+1) {
                dq.pop_front();
            }
            // delete all smaller value from back
            while (!dq.empty() && dq.back().second < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(pair<int, int>(i, nums[i]));
            
            if (i-k+1 >= 0) {
                res.push_back(dq.front().second);
            }
        }
        return res;
    }
};
