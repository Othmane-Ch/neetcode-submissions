class Solution {
public:

    bool canAddQueen(int row, int col, vector<int>& queens)
    {
        for(int qr = 0; qr < row; ++qr)
        {
            if(queens[qr] != -1 && (qr == row || queens[qr] == col || abs(queens[qr] - col) == abs(qr - row)))
            {
                return false;
            }
        }
        return true;
    }

    void dfs(int row, vector<int>& queens, vector<string>& board, int& result)
    {
        if(row == board.size())
        {
            ++result;
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

    // Time  : O(n * n!)
    // Space : O(n*n)
    int totalNQueens(int n) 
    {    
        int result {};
        vector<string> board(n, string(n, '.'));
        vector<int> queens(n, -1);
        dfs(0, queens, board, result);
        return result;
    }
};
