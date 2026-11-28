class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // Time  : O(R * C)
    // Space : O(R * C) + O(R + C)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> memo(ROWS, vector<int>(COLS, 0));
        auto dfs = [&] (this auto&& self, int r, int c) -> int
        {
            if(memo[r][c] != 0) return memo[r][c];
            int res = 1;
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || matrix[r][c] >= matrix[nr][nc])
                {
                    continue;
                }
                res = max(res, 1 + self(nr, nc));
            }
            return memo[r][c] = res;
        };

        int lip = 0;
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                lip = max(lip, dfs(r, c));
            }
        }

        return lip;
    }
};
