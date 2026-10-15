class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> seen_row {};
        unordered_map<int, unordered_set<char>> seen_col {};
        unordered_map<int, unordered_set<char>> seen_box {};

        for(int i = 0; i < board.size(); ++i)
        {
            
            for(int j = 0; j < board.size(); ++j)
            {
                if(board[i][j] != '.')
                {
                    // Row duplicate
                    if(seen_row[i].contains(board[i][j]))
                    {
                        return false;
                    }
                    seen_row[i].insert(board[i][j]);
                    // Col duplicate
                    if(seen_col[j].contains(board[i][j]))
                    {
                        return false;
                    }
                    seen_col[j].insert(board[i][j]);
                    // Box duplicate
                    int box_key = (i/3) * 3 + j/3;
                    if(seen_box[box_key].contains(board[i][j]))
                    {
                        return false;
                    }
                    seen_box[box_key].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
