#include <vector>
#include <iostream>

int binary_search(std::vector<int>, int);

int main(void)
{
    std::vector<int> n{1, 2, 4, 9, 18, 20, 35, 46, 79, 99, 100};

    std::cout << binary_search(n, 20) << '\n';
}

int binary_search(std::vector<int> nums, int target)
{
    // return size + 1 if not exits
    //
    int sz = nums.size();
    int start = 0;
    int end = sz - 1;
    int ret = sz + 1;

    while (start < end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            ret = mid;
            break;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            // nums[mid] > target
            end = mid - 1;
        }
    }
    return ret;
}
