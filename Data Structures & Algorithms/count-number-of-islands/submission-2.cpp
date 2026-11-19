class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};

    bool dfs(int r, int c, vector<vector<char>>& grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0')
        {
            return false;
        }
        grid[r][c] = '0';
        for(int i = 0; i < 4; ++i)
        {
            dfs(r + dr[i], c + dc[i], grid);
        }
        return true;
    }
    // Time  : O(R * C)
    // Space : O(R * C)
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int result = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(dfs(r, c, grid)) ++result;
            }
        }
        return result;
    }
};
