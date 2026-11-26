class Solution {
public:
    // 2-D Bottom-UP
    // Time  : O(n * m)
    // Space : O(1)
    int minPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for (auto& row : grid) row.push_back(INT_MAX);      // extra column on the right
        grid.push_back(vector<int>(COLS + 1, INT_MAX));     // extra row at the bottom
        grid[ROWS][COLS - 1] = 0;                           // the cell just below the target
        for(int r = ROWS - 1; r >= 0; --r)
        {
            for(int c = COLS - 1; c >= 0; --c)
            {
                grid[r][c] += min(grid[r + 1][c] , grid[r][c + 1]);
            }
        }
        return grid[0][0];
    }
};