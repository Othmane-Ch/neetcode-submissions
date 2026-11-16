class Solution {
public:

    bool canAddQueen(int r, int c, vector<pair<int, int>>& queens)
    {
        for(const auto& [qr, qc] : queens)
        {
            if(r == qr || c == qc || abs(r - qr) == abs(c - qc))
            {
                return false;
            }
        }
        return true;
    }

    void dfs(int idx, vector<pair<int, int>>& queens,vector<string>& board, vector<vector<string>>& result)
    {
        if(idx == board.size())
        {
            result.push_back(board);
            return;
        }

        for(int c = 0; c < board.size(); ++c)
        {
            if(canAddQueen(idx, c, queens))
            {
                board[idx][c] = 'Q';
                queens.push_back(make_pair(idx, c));
                dfs(idx + 1, queens, board, result);
                queens.pop_back();
                board[idx][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {    
        vector<vector<string>> result {};
        vector<string> board(n, string(n, '.'));
        vector<pair<int, int>> queens {};
        dfs(0, queens, board, result);
        return result;
    }
};
