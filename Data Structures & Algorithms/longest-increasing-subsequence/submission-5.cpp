class Solution {
public:
    // DP-Bottom-Up
    // Time  : O(n²)
    // Space : O(n)
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1); // dp[i] is LIS that has nums[i]
        int best = dp[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};
