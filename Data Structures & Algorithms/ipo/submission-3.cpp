class Solution {
public:
    // Time  : O(nlog(n) + klog(n))
    // Space : O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_capital {};
        for(int i = 0; i < capital.size(); ++i)
        {
            min_capital.push(make_pair(capital[i], i));
        }
        priority_queue<int> max_profit {};
        while(k > 0)
        {
            while(!min_capital.empty() && min_capital.top().first <= w)
            {
                auto [_, i] = min_capital.top();
                min_capital.pop();
                max_profit.push(profits[i]);
                
            }
            if(!max_profit.empty())
            {
                w += max_profit.top();
                max_profit.pop();
            } else {
                break;
            }
            --k;
        }
        return w;
    }
};