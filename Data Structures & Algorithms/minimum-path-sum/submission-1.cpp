class Solution {
public:

    int dfs(int r, int c, const int& ROWS, const int& COLS, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(r >= ROWS || c >= COLS) return INT_MAX;
        if(r == ROWS - 1 && c == COLS - 1) return grid[r][c];
        if(dp[r][c] != INT_MAX) return dp[r][c];
        int res = grid[r][c];
        res += min(dfs(r, c + 1, ROWS, COLS, grid, dp), dfs(r + 1, c, ROWS, COLS, grid, dp));
        return dp[r][c] = res ;
    }
    // 2-D Top-Down
    // Time  : O(n * m)
    // Space : O(n * m) + O(n + m) for recursion stack
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, INT_MAX));
        return dfs(0, 0, ROWS, COLS, grid, dp);
    }
};