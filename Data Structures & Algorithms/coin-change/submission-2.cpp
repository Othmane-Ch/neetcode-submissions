class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(const auto& coin : coins)
            {
                if(i < coin) continue;
                dp[i] = min(dp[i] , 1  + dp[i - coin]);
            }
            
        }

        return dp[amount] == INT_MAX ? - 1 : dp[amount];
    }
};
