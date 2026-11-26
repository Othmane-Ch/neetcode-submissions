class Solution {
public:

    static constexpr array<int, 2> dr = {0, 1};
    static constexpr array<int, 2> dc = {1, 0};
    // 2-D DP-Bottom-up
    // Time  : O(m * n)
    // Space : O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        dp[n - 1] = 1;
        for(int r = m - 2; r >= 0; --r)
        {
            for(int c = n - 2; c >= 0; --c)
            {
                dp[c] += dp[c + 1];
            }
        }
        return dp[0];
    }
};
