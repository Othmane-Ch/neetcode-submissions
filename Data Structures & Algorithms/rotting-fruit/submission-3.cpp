class Solution {
public:
    
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // multi source BFS
    // Time  : O(R * C)
    // Space : O(R * C) at worst
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<tuple<int, int, int>> q {};
        int fresh = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(grid[r][c] == 2)
                {
                    q.push(make_tuple(r, c, 0));
                } else if(grid[r][c] == 1)
                {
                    ++fresh;
                }
            }
        }
        int minutes {};
        while(!q.empty())
        {
            auto [r, c, m] = q.front();q.pop();
            minutes = m;
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != 1) continue;
                --fresh;
                grid[nr][nc] = 2;
                q.push(make_tuple(nr, nc, m + 1));
            }
        }
        return fresh ? -1 : minutes;
    }
};
