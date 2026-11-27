class Solution {
public:
    // 1-D DP-Bottom-up
    // Time  : O(n * m) m = 2 * sum(nums)
    // Space : O(n * m)
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        const int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][sum] = 1;
        for(int i = 1; i <= n; ++i)
        {
            const int x = nums[i - 1];           // the number row i adds
            for (int s = -sum; s <= sum; ++s)
            {
                int ways = 0;
                if (s - x >= -sum) ways += dp[i - 1][s - x + sum];   // '+x': previous sum was s - x
                if (s + x <=  sum) ways += dp[i - 1][s + x + sum];   // '-x': previous sum was s + x
                dp[i][s + sum] = ways;
            }
        }
        return dp[n][target + sum];
    }
};
