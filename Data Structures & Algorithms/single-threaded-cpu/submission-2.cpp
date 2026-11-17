class Solution {
public:
    // Time  : O(nlog(n))
    // Space : o(n) 
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_pq_arriving {}; // eq_T, process_T, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq_arrived {}; 
    
        for(int i = 0; i < tasks.size(); ++i)
        {
            min_pq_arriving.push(make_tuple(tasks[i][0], tasks[i][1], i));
        }

        vector<int> result {};
        int t = 0;
        while(result.size() != tasks.size())
        {
            if(!min_pq_arrived.empty())
            {
                auto [prTime, idx] = min_pq_arrived.top();min_pq_arrived.pop();
                t += prTime;
                result.push_back(idx);    
            } else {
                t = get<0>(min_pq_arriving.top());
            }
            while(!min_pq_arriving.empty() && get<0>(min_pq_arriving.top()) <= t)
            {
                auto [_ , prTime, idx] = min_pq_arriving.top(); min_pq_arriving.pop();
                min_pq_arrived.push(make_pair(prTime, idx));
            }
        }    
        return result;
    }
};