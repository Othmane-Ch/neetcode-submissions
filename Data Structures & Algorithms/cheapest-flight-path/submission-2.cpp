class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(const auto& flight : flights)
        {
            adjList[flight[0]].push_back(make_pair(flight[2], flight[1]));
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<tuple<int, int, int>> q {};
        q.push(make_tuple(0, src, k + 1));
        while(!q.empty())
        {
            auto [d, u, round] = q.front(); q.pop();
            if(round < 0) continue;
            for(int i = 0; i < adjList[u].size(); ++i)
            {
                auto& [w, v] = adjList[u][i];
                int price = w + d;
                if(price < dist[v] && round > 0)
                {
                    dist[v] = price;
                    q.push(make_tuple(price, v, round - 1));
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
