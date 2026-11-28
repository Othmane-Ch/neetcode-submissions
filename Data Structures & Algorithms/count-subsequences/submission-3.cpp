class Solution {
public:
    // Time  : O(n * m)
    // Space : O(n * m)
    int numDistinct(string s, string t) {
        const int ns = s.size();
        const int nt = t.size();
        if(nt > ns) return 0;
        vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, -1));
        auto dfs = [&](this auto&& self, int i, int j) -> int
        {
            if(j == nt)
            {
                return 1;
            }
            if(i == ns)
            {
                return 0;
            }
            if(dp[i][j] != -1) return dp[i][j];
            int res = 0;
            for(int k = i; k < ns; ++k)
            {
                if(j < nt && s[k] != t[j]) continue;
                res += self(k + 1, j + 1);
            }
            return dp[i][j] = res;
        };

        return dfs(0, 0);
    }
};
