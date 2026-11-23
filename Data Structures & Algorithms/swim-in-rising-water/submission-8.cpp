class Solution {
public:

    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // Time : O(nlogn) n number of cells in the grid
    // Space: O(n)
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> dist(ROWS, vector(COLS, INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_pq {};
        min_pq.push(make_tuple(grid[0][0], 0, 0));
        while(!min_pq.empty())
        {
            auto [d, r, c] = min_pq.top(); min_pq.pop();
            if(r == ROWS - 1 && c == COLS - 1) return d;
            if(d > dist[r][c]) continue;
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
                int time = max(grid[nr][nc], d);
                if(time < dist[nr][nc])
                {
                    dist[nr][nc] = time;
                    min_pq.push(make_tuple(time, nr, nc));
                }
            }
        }
    }
};
