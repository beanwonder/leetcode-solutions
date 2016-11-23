class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // using treeSet for search in log(k) keep a k window 
        if (nums.size() == 0 || k < 0 || t < 0) return false;
        int l = 0;
        int r = 0;
        set<long> values;
        while (r < nums.size()) {
            // r is currently being compared value
            // first search num[r]
            long rrange = (long) nums[r] + t;
            long lrange = (long) nums[r] - t;

            // rrange >= lrange
            // right >= nums[r] + t
            auto right = values.upper_bound(rrange);
            // left >= nums[r] - t
            auto left = values.lower_bound(lrange);
            if (left != right) {
                return true;
            }
            
            // add new elemetns and delete old one
            values.insert(nums[r]);
            
            if (r - l < k) {
                r += 1;
            } else {
                // in the values and nums[r] is being compared
                values.erase(nums[r-k]);
                r += 1;
                l += 1;
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate_bucket(vector<int>& nums, int k, int t) {
        // O(n) solution
        if (nums.size() == 0 || k <= 0 || t < 0) return false;
        // bucket number to number
        unordered_map<long, long> bucket_map;
        for (int i = 0; i < nums.size(); ++i) {
            long bid = ((long) nums[i] - INT_MIN) / ((long) t + 1);
            // if in the same bucket then return true, so each bucket 
            // only contain 1 number during exec
            if (bucket_map.find(bid) != bucket_map.end() 
                || (bucket_map.find(bid-1) != bucket_map.end() && nums[i]-bucket_map[bid-1] <= (long)t)
                || (bucket_map.find(bid+1) != bucket_map.end() && bucket_map[bid+1]-nums[i] <= (long)t)) {
                    return true;
            }
            // insert
            bucket_map[bid] = nums[i];
            // delete
            if (bucket_map.size() > k) {
                bucket_map.erase(((long)nums[i-k] - INT_MIN) / ((long) t + 1));
            }
        } 
        return false;
    }
};
    
};
