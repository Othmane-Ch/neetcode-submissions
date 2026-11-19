class Solution {
public:
    static constexpr int INF = 2147483647;
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // Time  : O(n) n numbers of cells in the grid
    // Space : O(n) queue    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        queue<pair<int, int>> q {};
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(grid[r][c] == 0)
                {
                    q.push(make_pair(r, c));
                }
            }
        }

        while(!q.empty())
        {
            auto [r , c] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INF) continue;
                grid[nr][nc] = grid[r][c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
};
