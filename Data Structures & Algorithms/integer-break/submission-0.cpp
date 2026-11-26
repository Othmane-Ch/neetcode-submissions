class Solution {
public:
    // 1-D DP-Bottom-Up
    // Time  : O(n²)
    // Space : O(n)
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1); // dp[i] the max product when i is split into at least 2 positive parts
        dp[1] = 1;
        for(int i = 2 ; i <= n; ++i)
        {
            for(int j = i - 1; j >= 1; --j)
            {
                dp[i] = max(dp[i], max(j , dp[j]) * max((i - j), dp[i - j]));
            }
        }
        return dp[n];
    }
};