class Solution {
public:
    // Time  : O(n + m)
    // Space : O(n + m)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(const auto& pre : prerequisites)
        {
            ++indegree[pre[0]];
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q {};
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0) q.push(i); 
        }
        vector<int> order {};
        while(!q.empty())
        {
            auto u = q.front(); q.pop();
            order.push_back(u);
            while(!adj[u].empty())
            {
                int v = adj[u].back(); adj[u].pop_back();
                --indegree[v];
                if(!indegree[v])
                {
                    q.push(v);
                }
            }
        }
        return order.size() == numCourses ? order : vector<int>();
    }
};
