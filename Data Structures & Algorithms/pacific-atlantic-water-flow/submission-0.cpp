class Solution {
public:
    static constexpr array<int, 4> dr = {0, 0, 1, -1};
    static constexpr array<int, 4> dc = {1, -1, 0, 0};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<pair<bool, bool>>> isPA(ROWS, vector<pair<bool, bool>>(COLS,  {false, false})); // {isPacific, isAtlantic}
        queue<pair<int, int>> q {};
        for(int i = 0; i < COLS; ++i)
        {
            isPA[0][i].first = true;
            isPA[ROWS - 1][i].second = true;
            q.push(make_pair(0, i));
            if(ROWS > 1) q.push(make_pair(ROWS - 1, i));
        }
        if (ROWS > 1) {
            for(int i = 0; i < ROWS; ++i)
            {
                isPA[i][0].first = true;
                isPA[i][COLS - 1].second = true;
                if (i != 0 && i != ROWS - 1) 
                { 
                    q.push(make_pair(i, 0));
                    if (COLS > 1) q.push(make_pair(i, COLS - 1));
                }
            }
        }
        
        while(!q.empty())
        {
            auto [r , c] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || heights[nr][nc] < heights[r][c]) continue;
                bool gainP = isPA[r][c].first  && !isPA[nr][nc].first;
                bool gainA = isPA[r][c].second && !isPA[nr][nc].second;
                if(!gainP && !gainA) continue;
                if(gainP)
                {
                    isPA[nr][nc].first = true;
                }
                if(gainA)
                {
                    isPA[nr][nc].second = true;
                }
                q.push(make_pair(nr, nc));
            }
        }

        vector<vector<int>> result {};
        for(int r = 0; r < ROWS; ++r)
        {
            for(int c = 0; c < COLS; ++c)
            {
                if(isPA[r][c].first && isPA[r][c].second)
                {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
