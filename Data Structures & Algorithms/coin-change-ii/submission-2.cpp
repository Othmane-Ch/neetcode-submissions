class Solution {
public:
    // Unbounded knapsack - Bottom-up and coins outside to for combinations
    // Time  : O(n * amount)
    // Space : O(amount)
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(const auto& coin : coins)
        {
            for(int i = coin; i <= amount; ++i)
            {
                if(coin > i) continue;
                dp[i] +=  dp[i - coin];
            }
            
        }
        return dp[amount];
    }
};
