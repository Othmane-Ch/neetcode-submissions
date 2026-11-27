class Solution {
public:
    int dfs(int day, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (day >= prices.size()) {
            return 0;
        }

        if (dp[day][canBuy] != -1) {
            return dp[day][canBuy];
        }

        int cooldown = dfs(day + 1, canBuy, prices, dp);
        int action = 0;

        if (canBuy) {
            action = -prices[day] + dfs(day + 1, 0, prices, dp);
        } else {
            action = prices[day] + dfs(day + 2, 1, prices, dp);
        }

        return dp[day][canBuy] = max(cooldown, action);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 1, prices, dp);
    }
};
