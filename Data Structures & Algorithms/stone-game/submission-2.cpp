class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        auto dfs = [&](this auto&& self, int i, int j) -> int {
            if(i > j)
            {
                return 0;
            }
            if(dp[i][j] != INT_MAX) return dp[i][j];
            auto score_i = piles[i] - self(i + 1, j);
            auto score_j = piles[j] - self(i, j - 1);
            return dp[i][j] = max(score_i , score_j);
        };
        return dfs(0, piles.size() - 1) > 0;
    }
};