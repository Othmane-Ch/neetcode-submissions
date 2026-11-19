class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n, 0);
        for(const auto& edge : trust)
        {
            --delta[edge[0] - 1];
            ++delta[edge[1] - 1];
        }

        for(int i = 0; i < n; ++i)
        {
            if(delta[i] == n - 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};