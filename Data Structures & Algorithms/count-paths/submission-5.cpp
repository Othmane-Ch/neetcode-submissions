class Solution {
public:

    static constexpr array<int, 2> dr = {0, 1};
    static constexpr array<int, 2> dc = {1, 0};
    // 2-D DP-Bottom-up
    // Time  : O(m * n)
    // Space : O(m * n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 0));
        dp[m - 1][n - 1] = 1;
        for(int r = m - 1; r >= 0; --r)
        {
            for(int c = n - 1; c >= 0; --c)
            {
                for(int i = 0; i < 2; ++i)
                {
                    int nr = r - dr[i], nc = c - dc[i];
                    if(nr < 0 || nc < 0) continue;
                    dp[nr][nc] += dp[r][c];
                }
            }
        }
        return dp[0][0];
    }
};
