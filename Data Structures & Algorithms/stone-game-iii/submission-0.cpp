class Solution {
public:
    // 1-DP Top-Down
    // Time  : O(n)
    // Space : O(n)
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> memo(n,  INT_MAX);
        auto dfs = [&] (this auto&& self, int i) -> int
        {
            if(i == n)
            {
                return 0;
            }
            if(memo[i] != INT_MAX) return memo[i];
            int score = INT_MIN;
            int taken = 0;
            for(int j = 0; j < 3; ++j)
            {
                if (i + j >= n) break;
                taken += stoneValue[i + j];
                score = max(score, taken - self(i + j + 1));
            }
            return memo[i] = score;
        };
        int res = dfs(0);
        return  res > 0 ? "Alice" : res < 0 ? "Bob" : "Tie";
    }
};