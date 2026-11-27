class Solution {
public:
    // 2-D  DP-Top-Down memoization
    // Time  : O(n1 * n2)
    // Space : O(n1 * n2) + O(n1 + n2)
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1)); // -1 means unreached , true (1) and false (0)
        auto dfs = [&](this auto&& self, int i, int j)
        {
            if(i + j == s3.size())
            {
                return 1;
            }
            if(dp[i][j] != -1) return dp[i][j];

            bool b1 = i < s1.size() && s1[i] == s3[i + j] && self(i + 1, j);
            bool b2 = j < s2.size() && s2[j] == s3[i + j] && self(i, j + 1);
            return dp[i][j] = b1 || b2;
        };

        return dfs(0,0) == 1; 
    }
};
