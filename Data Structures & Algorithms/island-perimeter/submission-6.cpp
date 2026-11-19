class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, -1, 1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};

    bool outOfGrid(int r, int c, int rows, int cols)
    {
        return r < 0 || r >= rows || c < 0 || c >= cols;
    }

    void dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<bool>>& seen, int& result)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if(outOfGrid(r, c, ROWS, COLS) || grid[r][c] == 0)
        {
            ++result;
            return;
        }
        if(seen[r][c]) return;
        seen[r][c] = true;
        for(int i = 0; i < 4; ++i)
        {
            dfs(r + dr[i], c + dc[i], grid, seen, result);
        }
    }
    
    // Time  : O(R * C) worst case if there is no land
    // Space : O(R * C) n number of cells in grid
    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> seen(ROWS, vector(COLS, false));
        int result = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(grid[r][c] == 1)
                {
                    dfs(r, c, grid, seen, result);
                }
            }
        }

        return result;
    }
};