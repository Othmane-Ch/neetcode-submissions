class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0, 1};
        vector<vector<int>> adjList(n);
        vector<int> degree(n); // undirected graph : degree are the number of neighbors
        for(const auto& edge : edges)
        {
            ++degree[edge[0]];
            ++degree[edge[1]];
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q {};        
        for(int i = 0; i < n; ++i)
        {
            if(adjList[i].size() == 1)
            {
                q.push(i);
            }
        }
        int remaining = n;
        while(remaining > 2)
        {
            int sz = q.size();
            for(int j = 0; j < sz; ++j)
            {
                auto node = q.front(); q.pop();
                --degree[node];
                for(int i = 0; i < adjList[node].size(); ++i)
                {
                    if(degree[adjList[node][i]] == 0) continue;
                    --degree[adjList[node][i]];
                    if(degree[adjList[node][i]] == 1)
                    {
                        q.push(adjList[node][i]);
                    }
                }
                --remaining;
            }   
        }
        vector<int> result {};
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};