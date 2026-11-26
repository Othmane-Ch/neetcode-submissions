class Solution {
public:

    int longestCommonSubsequence(string s, string t) {
        const int ns = s.size(), nt = t.size();
        vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, 0)); // dp[i][j] is the LCS of s1[0..i] && t[0..j]
        for(int i = 1; i <= ns; ++i)
        {
            for(int j = 1; j <= nt; ++j)
            {
                if(s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1] ,dp[i - 1][j]);
                }
            }
        }
        return dp[ns][nt];
    }
};
