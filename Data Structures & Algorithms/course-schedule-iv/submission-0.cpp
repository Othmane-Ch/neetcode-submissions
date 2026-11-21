class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(const auto& edge : prerequisites)
        {
            adjList[edge[0]].push_back(edge[1]);
            ++indegree[edge[1]];
        }
        queue<int> q {};
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        unordered_map<int, unordered_set<int>> ancestors;
        while(!q.empty())
        {
            auto p = q.front(); q.pop();

            for(int c : adjList[p])
            {
                ancestors[c].insert(p);
                for(const auto& a : ancestors[p]){
                    ancestors[c].insert(a);
                }
                --indegree[c];
                if(indegree[c] == 0){
                    q.push(c);
                }
            }
        }

        vector<bool> result(queries.size(), false);
        for(int i = 0; i < queries.size(); ++i)
        {
            result[i] = ancestors[queries[i][1]].contains(queries[i][0]);
        }
        return result;
    }
};