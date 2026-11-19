class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, -1, 1};
    static constexpr array<int, 4> dc = {-1, 1, 0, 0};

    int dfs(int r, int c, vector<vector<int>>& grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int area = 0;
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || !grid[r][c])
        {
            return area;
        }
        ++area;
        grid[r][c] = 0;
        for(int i = 0; i < 4; ++i)
        {
            area += dfs(r + dr[i], c + dc[i], grid);
        }
        return area;
    }
    // Time  : O(R * C)
    // Space : O(R * C)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int ROWS = grid.size();
       int COLS = grid[0].size();
       int res = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                res = max(res, dfs(r, c, grid));
            }
        }
        return res;
    }
};
