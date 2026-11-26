class Solution {
public:
    static constexpr array<int, 2> dr = {0, 1};
    static constexpr array<int, 2> dc = {1, 0};
    // 2-D DP-Bottom-up
    // Time  : O(n * m)
    // Space : O(n * m)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));
        
        dp[ROWS - 1][COLS - 1] = obstacleGrid[ROWS - 1][COLS - 1] ==  1 ? 0 : 1;

        for(int r = ROWS - 1; r >= 0; --r)
        {
            for(int c = COLS - 1; c >= 0; --c)
            {
                for(int i = 0; i < 2; ++i)
                {
                    int nr = r - dr[i], nc = c - dc[i];
                    if(nr < 0 || nc < 0 || obstacleGrid[r][c] == 1 || obstacleGrid[nr][nc]) continue;
                    dp[nr][nc] += dp[r][c];
                }
            }
        }
        return dp[0][0];
    }
};