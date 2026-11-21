class Solution {
public:

    bool dfs(int i, vector<vector<int>>& adjList, vector<bool>& seen)
    {

        if(seen[i] && !adjList[i].empty()) return false;
        seen[i] = true;
        while(!adjList[i].empty())
        {
            if(dfs(adjList[i].back(), adjList, seen))
            {
                adjList[i].pop_back();
            } else {
                return false;
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        for(const auto& pre : prerequisites)
        {
            adjList[pre[0]].push_back(pre[1]);
        }
        vector<bool> seen(numCourses, false);
        for(int i = 0; i < numCourses; ++i)
        {
            if(!dfs(i, adjList, seen))
            {
                return false;
            }
        }
        return true;
    }
};
