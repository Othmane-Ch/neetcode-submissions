class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // Djikstra
    // Time  : O((R * C) Log(R * C))
    // Space : O(R * C)
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>  min_pq {};
        min_pq.push(make_tuple(0, 0, 0));

        while(!min_pq.empty())
        {
            auto [d, r, c] = min_pq.top(); min_pq.pop();
            if(d > dist[r][c]) continue;
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
                int newEffort = max(d, abs(heights[nr][nc] - heights[r][c]));
                if(newEffort < dist[nr][nc])
                {
                    dist[nr][nc] = newEffort;
                    min_pq.push({newEffort, nr, nc});
                }
            }
        }
        return dist[ROWS - 1][COLS - 1];
    }
};