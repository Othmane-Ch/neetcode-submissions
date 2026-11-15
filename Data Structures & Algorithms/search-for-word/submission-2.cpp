class Solution {
public:
    static constexpr int directions = 4;
    static constexpr array<int, directions> dx = {0, 0, -1, 1};
    static constexpr array<int, directions> dy = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<char>>& board, const string& word, int i, bool& res, vector<vector<bool>>& seen)
    {
        int ROWS = board.size();
        int COLS = board[0].size();

        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != word[i] || seen[r][c] || res)
        {
            return;
        }

        if(i == word.size() - 1)
        {
            res = true;
            return;
        }
        
        seen[r][c] = true;
        for(int j = 0; j < directions; ++j)
        {
            dfs(r + dx[j], c + dy[j], board, word, i + 1, res, seen);
        }
        seen[r][c] = false;
    }
    // Time  : O(m * 4**(m * n))
    // Space : O(m )  
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        bool res = false;
        vector<vector<bool>> seen(ROWS, vector(COLS, false));
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                dfs(r, c, board, word, 0, res, seen);
                if(res) return res;
            }
        }
        return res;
    }
};
