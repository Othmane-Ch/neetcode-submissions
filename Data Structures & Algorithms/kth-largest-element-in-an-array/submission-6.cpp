#include <algorithm>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[n - k];
    }
};
