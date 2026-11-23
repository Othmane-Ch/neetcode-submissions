class Solution {
public:

    void dfs(const string& airport, unordered_map<string, queue<string>>& graph, vector<string>& path)
    {
        while(!graph[airport].empty())
        {
            auto next = graph[airport].front(); graph[airport].pop();
            dfs(next, graph, path);
        }
        path.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, queue<string>> graph {};
        for(const auto& ticket : tickets)
        {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> path {};
        dfs("JFK", graph, path);
        reverse(path.begin(), path.end());
        return path;
    }
};