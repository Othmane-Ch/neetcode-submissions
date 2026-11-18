class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_capital {};
        for(int i = 0; i < capital.size(); ++i)
        {
            min_capital.push(make_pair(capital[i], i));
        }
        priority_queue<int> max_profit {};
        int total = 0;
        while(k > 0)
        {
            while(!min_capital.empty() && min_capital.top().first <= w + total)
            {
                auto [_, i] = min_capital.top();
                min_capital.pop();
                max_profit.push(profits[i]);
                
            }
            if(!max_profit.empty())
            {
                total += max_profit.top();
                max_profit.pop();
                
            }
            --k;
        }
        return total + w;
    }
};