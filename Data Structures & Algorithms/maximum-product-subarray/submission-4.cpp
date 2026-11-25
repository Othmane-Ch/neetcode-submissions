class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp_max(n, 1);
        vector<int> dp_min(n, 1);
        dp_max[0] = dp_min[0] =nums[0];
        int best = nums[0];
        for(int i = 1; i < n; ++i)
        {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            best = max(best, dp_max[i]);
        }
        return best;
    }
};
