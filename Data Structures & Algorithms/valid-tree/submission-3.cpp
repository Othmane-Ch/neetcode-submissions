class Solution {
public:

    bool dfs(int i, int parent, vector<vector<int>>& adjList, vector<bool>& seen, int& t)
    {
        
        if(seen[i] && parent != i)
        {
             
            return false;
        }
        ++t;
        seen[i] = true;
        while(!adjList[i].empty())
        {
            int j = adjList[i].back(); adjList[i].pop_back();
            if(j == parent) continue;
            if(!dfs(j, i, adjList, seen, t))
            {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const auto& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> seen(n, false);
        int t = 0;
        return dfs(0, 0, adjList, seen, t) && t == n;
    }
};
