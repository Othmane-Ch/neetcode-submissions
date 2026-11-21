class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());
        for(const auto& pre : prerequisites)
        {
            ++indegree[pre[1]];
            adjList[pre[0]].push_back(pre[1]);
        }

        queue<int> q {};
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> order {};
        while(!q.empty())
        {
            int i = q.front(); q.pop();
            order.push_back(i);
            while(!adjList[i].empty())
            {
                int j = adjList[i].back(); adjList[i].pop_back();
                --indegree[j];
                if(indegree[j] == 0) {
                    q.push(j);
                }
            }
        }
        return order.size() == numCourses;
    }
};
