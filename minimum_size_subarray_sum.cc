#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // min lenth of subarray sum > s starting from i th place
        // the array are * positive number *
        // why it is o(n) sliding windows
        // sliding window calculate minimum len subarray start from l
        int l = 0;
        int r = 0;
        int sum = 0;
        int sz = nums.size();
        int ret = sz + 1;
        
        while (r < sz) {
            sum += nums[r];
            r += 1;
            while (sum >= s) {
                ret = ret > r-l ? r-l : ret;
                sum -= nums[l];
                l += 1;
            }
        }
        if (ret == sz + 1) {
            ret = 0;
        }
        return ret;
    }

    int minSubArrayLen_binary_search(int s, vector<int>& nums) {
        // since all the all the numbers are positive
        // so subarray sum are incremental start from i
        // n square
        int sz = nums.size();
        std::vector<int> sums(sz);
        int ret = sz + 1;
        
        for (int start = 0; start < sz; start++) {
            sums[start] = nums[start];
            for (int i = start+1; i < sz; i++) {
                sums[i] = sums[i-1] + nums[i];
            }
            // search the min len array
            int begin = start;
            int end = sz - 1;
            while (begin < end) {
                // terminate when begin == end
                int mid = (begin + end) / 2;
                if (sums[mid] >= s) {
                    end = mid;
                } else {
                    // sum < s find the minimun len
                    begin = mid + 1;
                }
            }
            if (sums[end] >= s) {
                int length = end - start + 1;
                ret = ret > length ? length : ret;
            }
        }
        
        if (ret == (sz + 1)) {
            ret = 0;
        }
        return ret;
    }    
    int minSubArrayLen_binary_search_nlogn(int s, vector<int>& nums) {
        int sz = nums.size();
        std::vector<int> sums(sz);
        int ret = sz + 1;

        if (sz == 0) return 0;
        
        sums[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        
        int partial_sum = 0;
        for (int i = 0; i < sz; i++) {
            // binary search
            int begin = i;
            int end = sz - 1;

            while (begin < end) {
                int mid = (begin + end) / 2;
                if (sums[mid] - partial_sum >= s) {
                    end = mid;
                } else {
                    // sums[mid] - < s
                    begin = mid + 1;   
                }
            }
            if (sums[end] - partial_sum >= s) {
                int len = end - i + 1;
                ret = len < ret ? len : ret;
            }
            partial_sum += nums[i];
        }

        if (ret == sz + 1) {
            ret = 0;
        }
        return ret;
    }
};
