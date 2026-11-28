class Solution {
public:
    // 
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        if(n == 1) return piles[0];
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> memo(n, vector<int>(n, sum + 1));
        auto dfs = [&] (this auto&& self, int i, int m) -> int
        {
            if(i == n)
            {
                return 0;
            }
            if(memo[i][m] != sum + 1) return memo[i][m];
            int score = INT_MIN;
            int taken = 0;
            for(int j = 0; j < 2*m; ++j)
            {
                if (i + j >= n) break;
                taken += piles[i + j];
                score = max(score, taken - self(i + j + 1, max(m, j + 1)));
            }
            return memo[i][m] = score;
        };
        
        return (sum + dfs(0, 1)) / 2;
    }
};