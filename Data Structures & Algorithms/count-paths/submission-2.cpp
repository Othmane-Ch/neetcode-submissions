class Solution {
public:

    static constexpr array<int, 4> dr = {0, 1};
    static constexpr array<int, 4> dc = {1, 0};
    // 2-D DP-Top-down
    // Time  : O(m * n)
    // Space : O(m * n)
    int dfs(int r, int c, int ROWS, int COLS, vector<vector<int>>& dp)
    {
        if(r == ROWS - 1 && c == COLS - 1)
        {
            return 1;
        }

        if(r >= ROWS || c >= COLS)
        {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < 2; ++i)
        {
            int nr = r + dr[i], nc = c + dc[i];
            res += dp[nr][nc] ? dp[nr][nc] : dfs(nr, nc, ROWS, COLS, dp);
        }
        dp[r][c] = res;
        return res;
    }   

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector(n + 1, 0));
        dp[0][0] = 1;
        return dfs(0, 0, m, n, dp);
    }
};
