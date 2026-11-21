class Solution {
public:

    bool dfs(int i, int parent, vector<vector<int>>& adjList, vector<bool>& seen, int& t)
    {
        
        if(seen[i])
        {
             
            return false;
        }
        ++t;
        seen[i] = true;
        for(const auto& j: adjList[i])
        {
            if(j == parent) continue;
            if(!dfs(j, i, adjList, seen, t))
            {
                return false;
            }
        }
        return true;
    }
    // Time  : O(V + E)
    // Space : O(V + E)

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adjList(n);
        for(const auto& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> seen(n, false);
        int t = 0;
        return dfs(0, -1, adjList, seen, t) && t == n;
    }
};
