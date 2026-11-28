class Solution {
public:
    // 2-D DP Top-Down
    // Time  : O(n * m)
    // Space : O(n * m) + O(n + m) recursion stack
    int minDistance(string word1, string word2) {
        const int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        auto dfs = [&](this auto&& self, int i, int j)
        {
            if(i == n1)
            {
                return n2 - j;
            }
            if(j == n2)
            {
                return n1 - i;
            }
            if(dp[i][j] != -1) return dp[i][j];
            int res = 0;
            if(word1[i] == word2[j])
            {
                res = self(i + 1, j + 1);
            } else {
                res = 1 + min({self(i, j + 1) , self(i + 1, j) , self(i + 1, j + 1)});
            }
            
            return dp[i][j] = res;
        };

        return dfs(0, 0);
    }
};
