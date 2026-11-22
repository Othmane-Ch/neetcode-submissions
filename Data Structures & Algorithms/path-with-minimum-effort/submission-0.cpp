class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    int dfs(int r, int c, int effort, vector<vector<int>>& heights, priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>& min_pq)
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        if(r == ROWS - 1 && c == COLS - 1) {
            return effort;
        }
        int v = heights[r][c];
        heights[r][c] = 0;

        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || heights[nr][nc] == 0) continue;
            min_pq.push(make_tuple(abs(heights[nr][nc] - v), nr, nc));
        }

        auto [e, nr, nc] = min_pq.top(); min_pq.pop();
        cout << "(" << nc <<", " << nc << ")" << endl;
        return dfs(nr, nc, max(effort, e), heights, min_pq);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>  min_pq {};
        return dfs(0, 0, 0,heights, min_pq);
    }
};