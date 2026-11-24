class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0; dp[1] = 0;
        int i = 2;
        while(i <= n)
        {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
            ++i;
        }
        return dp[n];
    }
};
