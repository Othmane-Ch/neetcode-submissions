class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int min_buy = prices[0];
        int max_profit = 0;

        for(int i = 1; i < n; ++i)
        {
            min_buy = min(min_buy, prices[i]);
            max_profit = max(max_profit, prices[i] - min_buy);
        }
        return max_profit;
        
    }
};
