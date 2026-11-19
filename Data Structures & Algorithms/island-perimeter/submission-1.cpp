class Solution {
public:
    static constexpr array<int, 4> horizontal = {0, 0, -1, 1};
    static constexpr array<int, 4> vertical = {1, -1, 0, 0};

    bool outOfGrid(int r, int c, int rows, int cols)
    {
        return r < 0 || r >= rows || c < 0 || c >= cols;
    }

    int dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<bool>>& seen, int& result)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if(outOfGrid(r, c, ROWS, COLS) || seen[r][c] || grid[r][c] == 0)
        {
            return 0;
        }
        seen[r][c] = true;
        for(int i = 0; i < 4; ++i)
        {
            int dx = horizontal[i], dy = vertical[i];
            if(outOfGrid(r + dx, c + dy, ROWS, COLS))
            {
                ++result;
            }
            else if(grid[r + dx][c + dy] == 0)
            {
                ++result;
            }
            dfs(r + dx, c + dy, grid, seen, result);
        }
        return result;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> seen(ROWS, vector(COLS, false));
        int result = 0;
        int start_r = 0;
        int start_c = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(grid[r][c] == 1)
                {
                    start_r = r;
                    start_c = c;
                    break;
                }
            }
        }
        dfs(start_r, start_c, grid, seen, result);

        return result;
    }
};