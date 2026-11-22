class Solution {
public:
    // T
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& time : times)
        {
            int u = time[0], v = time[1], w = time[2];
            graph[u - 1].push_back(make_pair(w, v - 1));
        }

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq {};
        min_pq.push(make_pair(0, k - 1));
        while(!min_pq.empty())
        {
            auto [d, u] = min_pq.top(); min_pq.pop();
            if(d > dist[u]) continue;
            for(const auto& [w, v] : graph[u])
            {
                if(dist[v] > w + d)
                {
                    dist[v] = w + d;
                    min_pq.push(make_pair(dist[v], v));
                }
            }
        }
        int res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX ? - 1 : res;
    }
};
