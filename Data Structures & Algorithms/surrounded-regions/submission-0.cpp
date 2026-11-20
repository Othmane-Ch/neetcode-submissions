class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    // Time  : O(R * C)
    // Space : O(R * C)
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        queue<pair<int, int>> q {};
        vector<vector<bool>> isSafe(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false));
        for(int c = 0; c < COLS; ++c)
        {
            if(board[0][c] == 'O')
            {
                auto p = make_pair(0, c);
                q.push(p);
                isSafe[0][c] = true;
            }
            if(ROWS > 1 && board[ROWS - 1][c] == 'O')
            {
                auto p = make_pair(ROWS - 1, c);
                q.push(p);
                isSafe[ROWS - 1][c] = true;
            }
        }
        
        if(ROWS > 2)
        {
            for(int r = 1; r < ROWS - 1; ++r)
            {
                if(board[r][0] == 'O')
                {
                    auto p = make_pair(r, 0);
                    q.push(p);
                    isSafe[r][0] = true;
                }
                if(COLS > 1 && board[r][COLS - 1] == 'O')
                {
                    auto p = make_pair(r, COLS - 1);
                    q.push(p);
                    isSafe[r][COLS - 1] = true;
                }
            }
        }
        
        while(!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            seen[r][c] = true;
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || board[nr][nc] == 'X' || seen[nr][nc]) continue;
                auto p = make_pair(nr, nc);
                isSafe[nr][nc] = true;
                q.push(p);
            }
        }

        for(int r = 1; r < ROWS - 1; ++r)
        {
            for(int c = 1; c < COLS - 1; ++c)
            {
                if(!isSafe[r][c]  && board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
            }
        }
        
    }
};
