class Solution {
public:

    double dfs(const string& start, const string& dest, unordered_map<string, vector<pair<double, string>>>& graph, unordered_set<string>& visited)
    {

        if(graph.contains(start) && start == dest)
        {
            return 1;
        }
        visited.insert(start);
        auto it = graph.find(start);
        if (it != graph.end()) {
            for (const auto& p : it->second)
            {
                if(visited.contains(p.second)) continue;
                double res = dfs(p.second, dest, graph, visited);
                if(res != -1)
                {
                    return p.first * res;
                }
                
            }
        }
        return -1.0;
    }
    // Time  : O(Q * (E +V))
    // Space : O(E + V)
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<double, string>>> graph {};
        for(int i = 0; i < equations.size(); ++i)
        {
            graph[equations[i][0]].push_back(make_pair(1 / values[i], equations[i][1]));
            graph[equations[i][1]].push_back(make_pair(values[i], equations[i][0]));
        }
        vector<double> result {};
        for(const auto& query : queries)
        {
            unordered_set<string> visited {};
            result.push_back(dfs(query[1], query[0], graph, visited));
        }
        return result;
    }
};