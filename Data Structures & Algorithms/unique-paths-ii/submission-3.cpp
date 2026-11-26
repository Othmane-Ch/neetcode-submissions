class Solution {
public:
    static constexpr array<int, 2> dr = {0, 1};
    static constexpr array<int, 2> dc = {1, 0};

    int dfs(int r, int c, const int& ROWS, const int& COLS, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid)
    {
        if(r >= ROWS || c >= COLS || obstacleGrid[r][c] == 1) return 0;
        if(r == ROWS - 1 && c == COLS - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int res = 0;
        for(int i = 0; i < 2; ++i)
        {
            int nr = r + dr[i], nc = c + dc[i];
            res += dfs(nr, nc, ROWS, COLS, dp, obstacleGrid);
        }
        
        return dp[r][c] = res;;
    }

    // 2-D DP-Top-Down memoization
    // Time  : O(n * m)
    // Space : O(n * m) + O(m + n) recursion stack

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, -1));
        return dfs(0, 0, ROWS, COLS, dp, obstacleGrid);
    }

};