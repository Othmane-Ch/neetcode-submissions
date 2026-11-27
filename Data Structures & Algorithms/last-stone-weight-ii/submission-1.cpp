class Solution {
public:
    // 2-D Top-Down
    // Time  : O(n*m)
    // Space : O(n*m)
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum/2;
        const int n = stones.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false)); // dp[i][j] : using the first i element, can their sum equal j
        dp[0][0] = true;
        int last_amount = 0;
        for(int j = 0; j <= target; ++j)
        {
            for(int i = 1; i <= n; ++i)
            {
                dp[i][j] = dp[i - 1][j] || (stones[i - 1] <= j && dp[i - 1][j - stones[i - 1]]);
                if(dp[i][j])
                {
                    last_amount = j;
                }
            }
        }
        return sum - last_amount - last_amount;
    }
};