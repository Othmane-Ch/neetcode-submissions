class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};

    int dfs(int r, int c, const vector<vector<char>>& grid, vector<vector<bool>>& seen)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0' || seen[r][c])
        {
            return 0;
        }
        int res = 1;
        seen[r][c] = true;
        for(int i = 0; i < 4; ++i)
        {
            res += dfs(r + dr[i], c + dc[i], grid, seen);
        }
        return res;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> seen(ROWS, vector(COLS, false));
        int result = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(dfs(r, c, grid, seen)) ++result;
            }
        }
        return result;
    }
};
