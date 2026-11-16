class Solution {
public:

    bool canAddQueen(int row, int col, vector<int>& queens)
    {
        for(int qr = 0; qr < queens.size(); ++qr)
        {
            if(queens[qr] != -1 && (qr == row || queens[qr] == col || abs(queens[qr] - col) == abs(qr - row)))
            {
                return false;
            }
        }
        return true;
    }

    void dfs(int row, vector<int>& queens, vector<string>& board, vector<vector<string>>& result)
    {
        if(row == board.size())
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < board.size(); ++col)
        {
            if(canAddQueen(row, col, queens))
            {
                board[row][col] = 'Q';
                queens[row] = col;
                dfs(row + 1, queens, board, result);
                queens[row] = -1;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {    
        vector<vector<string>> result {};
        vector<string> board(n, string(n, '.'));
        vector<int> queens(n, -1);
        dfs(0, queens, board, result);
        return result;
    }
};
